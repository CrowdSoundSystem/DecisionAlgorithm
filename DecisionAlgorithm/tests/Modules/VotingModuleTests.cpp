#include "VotingModuleTests.h"

#include <cassert>

#include "..\..\src\Modules\VotingModule.h"

void VotingModuleTests::runTests() {
	test_1();
}

MusicDataList VotingModuleTests::getMusicTestData() {

	MusicDataList musicData;

	MusicData data1;
	data1.setVoteSum(3);
	musicData.push_back(data1);

	MusicData data2;
	data2.setVoteSum(0);
	musicData.push_back(data2);

	MusicData data3;
	data3.setVoteSum(-1);
	musicData.push_back(data3);

	return musicData;

}

void VotingModuleTests::test_1() {

	MusicDataList musicList = getMusicTestData();

	DecisionSettings settings;
	settings.m_countWeight = 1.0f;
	settings.m_voteWeight = DecisionSettings::VoteWeight_Equal;

	VotingModule::run(settings, musicList);

	for each (MusicData data in musicList) {
		assert(data.getWeight() == data.getVoteSum()*settings.m_countWeight);
	}
}

void VotingModuleTests::test_2() {

	MusicDataList musicList = getMusicTestData();

	DecisionSettings settings;
	settings.m_countWeight = 1.0f;
	settings.m_voteWeight = DecisionSettings::VoteWeight_High;

	VotingModule::run(settings, musicList);

	for each (MusicData data in musicList) {
		assert(data.getWeight() == data.getVoteSum()*settings.m_countWeight*1.5);
	}
}

void VotingModuleTests::test_3() {

	MusicDataList musicList = getMusicTestData();

	DecisionSettings settings;
	settings.m_countWeight = 1.0f;
	settings.m_voteWeight = DecisionSettings::VoteWeight_Low;

	VotingModule::run(settings, musicList);

	for each (MusicData data in musicList) {
		assert(data.getWeight() == data.getVoteSum()*settings.m_countWeight*0.5);
	}
}
