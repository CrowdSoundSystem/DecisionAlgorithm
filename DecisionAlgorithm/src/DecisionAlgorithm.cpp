#include "DecisionAlgorithm.h"

#include "Modules\CountingModule.h"
#include "Modules\GenerationModule.h"
#include "Modules\TierModule.h"
#include "Modules\VotingModule.h"

void DecisionAlgorithm::getMusicData() {

	// TEMP: Pull from DB

}

void DecisionAlgorithm::run() {

	MusicDataList nextSet;

	CountingModule::run(m_settings, m_musicDataList);
	VotingModule::run(m_settings, m_musicDataList);
	TierModule::run(m_settings, m_musicDataList);
	GenerationModule::run(m_settings, m_musicDataList, nextSet);

	for each (MusicData song in nextSet)
	{
		// TEMP: Push to DB
	}

}

