#include "CountingModuleTests.h"

#include <cassert>

#include "..\..\src\Modules\CountingModule.h"

void CountingModuleTests::runTests() {
	test_1();
}

MusicDataList CountingModuleTests::getMusicTestData() {

	MusicDataList musicData;

	MusicData data1;
	data1.setScore(1.f);
	musicData.push_back(data1);

	MusicData data2;
	data2.setScore(1.f);
	musicData.push_back(data2);

	MusicData data3;
	data3.setScore(1.f);
	musicData.push_back(data3);

	return musicData;

}

void CountingModuleTests::test_1() {

	MusicDataList musicList = getMusicTestData();

	DecisionSettings settings;
	settings.m_countWeight = 1.0f;

	CountingModule::run(settings, musicList);

	MusicDataList::iterator itr = musicList.begin();
	while (itr != musicList.end())
	{
		assert((*itr).getScore() == 1.0f);

		++itr;
	}

}


