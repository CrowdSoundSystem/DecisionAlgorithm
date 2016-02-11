#include "VotingModule.h"

void VotingModule::run(DecisionSettings& settings, MusicDataList& musicDataSet) {

	std::unordered_map<std::string, int > artistCounts;
	std::unordered_map<std::string, int > genreCounts;

	// First iteration for direct votes
	MusicDataList::iterator setItr;
	for (setItr = musicDataSet.begin(); setItr != musicDataSet.end(); ++setItr) {

		int voteSum = (*setItr).getVoteSum();

		artistCounts[(*setItr).getArtist()] += voteSum;
		genreCounts[(*setItr).getGenre()] += voteSum;

		float voteWeight = getVoteWeight(settings);
		(*setItr).addScore(voteSum*voteWeight);
	}

	// Second iteration for artist/genre votes
	for (setItr = musicDataSet.begin(); setItr != musicDataSet.end(); ++setItr) {

		float artistScore = settings.m_artistWeight * artistCounts[(*setItr).getArtist()];
		float genreScore = settings.m_genreWeight * genreCounts[(*setItr).getGenre()];

		(*setItr).addScore(artistScore + genreScore);
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

