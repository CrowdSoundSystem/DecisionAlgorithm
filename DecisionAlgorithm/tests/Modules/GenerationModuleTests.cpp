#include "GenerationModuleTests.h"

#include <cassert>

#include "..\..\src\Modules\GenerationModule.h"

void GenerationModuleTests::runTests() {
	test_1();
}

MusicDataList GenerationModuleTests::getMusicTestData() {

	MusicDataList musicData;

	MusicData data1;
	data1.setScore(1.0);
	musicData.push_back(data1);

	MusicData data2;
	data2.setScore(12.1);
	musicData.push_back(data2);

	MusicData data3;
	data3.setScore(4.3);
	musicData.push_back(data3);

	MusicData data4;
	data4.setScore(-4.0);
	musicData.push_back(data4);

	MusicData data5;
	data5.setScore(0.0);
	musicData.push_back(data5);

	MusicData data6;
	data6.setScore(9.3);
	musicData.push_back(data6);

	MusicData data7;
	data7.setScore(9.2);
	musicData.push_back(data7);

	return musicData;

}

void GenerationModuleTests::test_1() {

	MusicDataList musicList = getMusicTestData();
	MusicDataList outputSet;

	DecisionSettings settings;
	settings.m_numSongsGenerated = 3;

	GenerationModule::run(settings, musicList, outputSet);

	assert(outputSet.size() == 3);

	double previousWeight = 100.0;
	MusicDataList::iterator itr = musicList.begin();
	while (itr != musicList.end())
	{
		assert((*itr).getScore() < previousWeight);
		previousWeight = (*itr).getScore();

		++itr;
	}
}
