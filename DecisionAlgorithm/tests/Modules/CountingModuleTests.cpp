#include "CountingModuleTests.h"

#include <cassert>

#include "..\..\src\Modules\CountingModule.h"

void CountingModuleTests::runTests() {
	test_1();
}

MusicDataList CountingModuleTests::getMusicTestData() {

	MusicDataList musicData;

	MusicData data1;
	musicData.push_back(data1);

	MusicData data2;
	musicData.push_back(data2);

	MusicData data3;
	musicData.push_back(data3);

	return musicData;

}

void CountingModuleTests::test_1() {

	MusicDataList musicList = getMusicTestData();

	DecisionSettings settings;
	settings.m_countWeight = 1.0f;

	CountingModule::run(settings, musicList);

	for each (MusicData data in musicList) {
		assert(data.getWeight() == 1.0f);
	}

}


