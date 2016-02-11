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

	float m_genreWeight;	// Voting for song, weight for given genre
	float m_artistWeight;	// Voting for song, weight for given artist

	std::map<Tier, float> m_tierMultipliers;

	int m_numSongsGenerated;

	static DecisionSettings defaultSettings() {
		DecisionSettings settings;
		settings.m_countWeight = 1.0;

		settings.m_voteWeight = DecisionSettings::VoteWeight_Equal;

		settings.m_genreWeight = 0.5;
		settings.m_artistWeight = 1.0;

		settings.m_tierMultipliers[Tier_SAG] = 1.0f;
		settings.m_tierMultipliers[Tier_SA] = 0.8f;
		settings.m_tierMultipliers[Tier_SG] = 0.7f;
		settings.m_tierMultipliers[Tier_AG] = 0.5f;
		settings.m_tierMultipliers[Tier_S] = 0.5f;
		settings.m_tierMultipliers[Tier_A] = 0.3f;
		settings.m_tierMultipliers[Tier_G] = 0.2f;

		settings.m_numSongsGenerated = 3;
		
		return settings;
	}

};

#endif
