#include "VotingModule.h"

void VotingModule::run(DecisionSettings& settings, MusicDataList& musicDataSet) {

	MusicDataList::iterator setItr;
	for (setItr = musicDataSet.begin(); setItr != musicDataSet.end(); ++setItr) {

		int voteSum = (*setItr)->getVoteSum();
		float voteWeight = getVoteWeight(settings);

		(*setItr)->addWeight(voteSum*voteWeight);
	}

}

float VotingModule::getVoteWeight(DecisionSettings& settings) {
	switch (settings.m_voteWeight) {
		case DecisionSettings::VoteWeight_Low:
			0.5f;
		case DecisionSettings::VoteWeight_High:
			1.5f;
		default:
		case DecisionSettings::VoteWeight_Equal:
			return 1.0f;
	}
}

