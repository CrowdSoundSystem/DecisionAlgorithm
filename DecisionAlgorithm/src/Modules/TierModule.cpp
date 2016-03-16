#include "TierModule.h"

#include <time.h>

void TierModule::run(DecisionSettings& settings, MusicDataList& musicDataSet) 
{
	time_t currentTime;
	time(&currentTime);

	MusicDataList::iterator setItr;
	for (setItr = musicDataSet.begin(); setItr != musicDataSet.end(); ++setItr) 
	{

		Tier tier = setItr->getTier();
		float multiplier = 1.0;

		if (settings.m_tierMultipliers.count(tier) == 1)
			multiplier = settings.m_tierMultipliers[tier];

		if (setItr->getPreviouslyPlayed() > 0)
		{
			if (currentTime - setItr->getPreviouslyPlayed() > settings.m_minsBeforeCanPlayAgain * 60 * 1000)
				multiplier *= settings.m_playedAgainMultipler;
			else
				multiplier = 0;
		}

		setItr->mulScore(multiplier);
	}
}
