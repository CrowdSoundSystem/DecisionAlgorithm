#include "GenerationModuleTests.h"

#include <cassert>

#include "..\..\src\Modules\GenerationModule.h"

void GenerationModuleTests::runTests() {
	test_1();
}

MusicDataList GenerationModuleTests::getMusicTestData() {

	MusicDataList musicData;

	MusicData data1;
	data1.setWeight(1.0);
	musicData.push_back(data1);

	MusicData data2;
	data2.setWeight(12.1);
	musicData.push_back(data2);

	MusicData data3;
	data3.setWeight(4.3);
	musicData.push_back(data3);

	MusicData data4;
	data4.setWeight(-4.0);
	musicData.push_back(data4);

	MusicData data5;
	data5.setWeight(0.0);
	musicData.push_back(data5);

	MusicData data6;
	data6.setWeight(9.3);
	musicData.push_back(data6);

	MusicData data7;
	data7.setWeight(9.2);
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
	for each (MusicData data in outputSet) {
		assert(data.getWeight() < previousWeight);
		previousWeight = data.getWeight();
	}
}
