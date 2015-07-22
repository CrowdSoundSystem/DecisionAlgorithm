#include "TierModuleTests.h"

#include <cassert>

#include "..\..\src\Modules\TierModule.h"

void TierModuleTests::runTests() {
	test_1();
	test_2();
	test_3();
}

MusicDataList TierModuleTests::getMusicTestData() {

	MusicDataList musicData;

	MusicData data1;
	data1.addArtist("Disturbed");
	data1.addSong("Indestructible");
	data1.addGenre("Rock");
	data1.setWeight(1.0);
	musicData.push_back(data1);

	MusicData data2;
	data2.addArtist("Daft Punk");
	data2.addSong("Harder, Better, Faster, Stronger");
	data2.setWeight(1.0);
	musicData.push_back(data2);

	MusicData data3;
	data3.addArtist("Nero");
	data3.addGenre("House");
	data3.setWeight(1.0);
	musicData.push_back(data3);

	MusicData data4;
	data4.addSong("One");
	data4.addGenre("Rock");
	data4.setWeight(1.0);
	musicData.push_back(data4);

	MusicData data5;
	data5.addArtist("Coyote Kisses");
	data5.setWeight(1.0);
	musicData.push_back(data5);

	MusicData data6;
	data6.addSong("Maestro");
	data6.setWeight(1.0);
	musicData.push_back(data6);

	MusicData data7;
	data7.addGenre("Pop");
	data7.setWeight(1.0);
	musicData.push_back(data7);

	return musicData;

}

void TierModuleTests::test_1() {

	MusicData data1;
	data1.addArtist("Disturbed");
	data1.addSong("Indestructible");
	data1.addGenre("Rock");
	assert(data1.getTier() == Tier_SAG);

	MusicData data2;
	data2.addArtist("Daft Punk");
	data2.addSong("Harder, Better, Faster, Stronger");
	assert(data2.getTier() == Tier_SA);

	MusicData data3;
	data3.addArtist("Nero");
	data3.addGenre("House");
	assert(data3.getTier() == Tier_AG);

	MusicData data4;
	data4.addSong("One");
	data4.addGenre("Rock");
	assert(data4.getTier() == Tier_SG);

	MusicData data5;
	data5.addArtist("Coyote Kisses");
	assert(data5.getTier() == Tier_A);

	MusicData data6;
	data6.addSong("Maestro");
	assert(data6.getTier() == Tier_S);

	MusicData data7;
	data7.addGenre("Pop");
	assert(data7.getTier() == Tier_G);

}

void TierModuleTests::test_2() {

	MusicDataList musicList = getMusicTestData();

	DecisionSettings settings;
	settings.m_tierMultipliers[Tier_SAG] = 2.0;

	TierModule::run(settings, musicList);

	for each (MusicData data in musicList) {
		if (data.getTier() == Tier_SAG) {
			assert(data.getWeight() == 1.0 * settings.m_tierMultipliers[Tier_SAG]);
		} else {
			assert(data.getWeight() == 1.0);
		}
	}
}

void TierModuleTests::test_3() {

	MusicDataList musicList = getMusicTestData();

	DecisionSettings settings;
	settings.m_tierMultipliers[Tier_SAG] = 2.0;
	settings.m_tierMultipliers[Tier_AG] = 3.0;
	settings.m_tierMultipliers[Tier_SA] = 4.0;
	settings.m_tierMultipliers[Tier_SG] = 5.0;

	TierModule::run(settings, musicList);

	for each (MusicData data in musicList) {
		if (data.getTier() == Tier_SAG) {
			assert(data.getWeight() == 1.0 * settings.m_tierMultipliers[Tier_SAG]);
		} else if (data.getTier() == Tier_AG) {
			assert(data.getWeight() == 1.0 * settings.m_tierMultipliers[Tier_AG]);
		} else if (data.getTier() == Tier_SA) {
			assert(data.getWeight() == 1.0 * settings.m_tierMultipliers[Tier_SA]);
		} else if (data.getTier() == Tier_SG) {
			assert(data.getWeight() == 1.0 * settings.m_tierMultipliers[Tier_SG]);
		} else {
			assert(data.getWeight() == 1.0);
		}
	}
}
