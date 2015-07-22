#include "TierModule.h"

void TierModule::run(DecisionSettings& settings, MusicDataList& musicDataSet) {

	MusicDataList::iterator setItr;
	for (setItr = musicDataSet.begin(); setItr != musicDataSet.end(); ++setItr) {

		Tier tier = (*setItr).getTier();
		float multiplier = 1.0;

		if (settings.m_tierMultipliers.count(tier) == 1) {
			multiplier = settings.m_tierMultipliers[tier];
		}

		(*setItr).mulWeight(multiplier);
	}

}
