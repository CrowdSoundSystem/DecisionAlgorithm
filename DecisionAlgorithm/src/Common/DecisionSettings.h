#ifndef DecisionSettings_HEADER
#define DecisionSettings_HEADER

#include "Const.h"

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

	float m_tierMultiplierSAG;
	float m_tierMultiplierSA;
	float m_tierMultiplierSG;
	float m_tierMultiplierAG;
	float m_tierMultiplierS;
	float m_tierMultiplierA;
	float m_tierMultiplierG;

};

#endif