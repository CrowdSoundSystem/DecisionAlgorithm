#include "VotingModule.h"

void VotingModule::run(DecisionSettings& settings, MusicDataList& musicDataSet) 
{
	MusicDataList::iterator setItr;
	for (setItr = musicDataSet.begin(); setItr != musicDataSet.end(); ++setItr) 
	{
		float artistScore = settings.m_artistWeight * setItr->getArtistVotes();
		float genreScore = settings.m_genreWeight * setItr->getGenreVotes();
		float baseScore = getVoteWeight(settings) * setItr->getVotes();

		setItr->addScore(artistScore + genreScore + baseScore);
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

