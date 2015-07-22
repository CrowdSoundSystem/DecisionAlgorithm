#include "VotingModule.h"

void VotingModule::run(DecisionSettings& settings, MusicDataList& musicDataSet) {

	MusicDataList::iterator setItr;
	for (setItr = musicDataSet.begin(); setItr != musicDataSet.end(); ++setItr) {

		int voteSum = (*setItr).getVoteSum();
		float voteWeight = getVoteWeight(settings);

		(*setItr).addWeight(voteSum*voteWeight);
	}

}

float VotingModule::getVoteWeight(DecisionSettings& settings) {
	switch (settings.m_voteWeight) {

		case DecisionSettings::VoteWeight_Low:
			return settings.m_countWeight * 0.5f;

		case DecisionSettings::VoteWeight_High:
			return settings.m_countWeight * 1.5f;

		default:
		case DecisionSettings::VoteWeight_Equal:
			return settings.m_countWeight;
	}
}

