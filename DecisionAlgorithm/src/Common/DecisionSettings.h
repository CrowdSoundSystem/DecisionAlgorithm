#ifndef DecisionSettings_HEADER
#define DecisionSettings_HEADER

#include <map>

#include "Const.h"
#include "MusicData.h"

struct DecisionSettings {

	enum VoteWeight {
		VoteWeight_Low,
		VoteWeight_Equal,
		VoteWeight_High
	};

	float m_countWeight;

	VoteWeight m_voteWeight;

	VoteWeight m_songGenreWeight;	// Voting for song, weight for given genre
	VoteWeight m_artistGenreWeight;	// Voting for artist, weight for given genre

	std::map<Tier, float> m_tierMultipliers;

};

#endif