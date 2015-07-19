#include "DecisionAlgorithm.h"

#include "Modules\CountingModule.h"
#include "Modules\GenerationModule.h"
#include "Modules\TierModule.h"
#include "Modules\VotingModule.h"

DecisionAlgorithm::DecisionAlgorithm() {

}

void DecisionAlgorithm::getMusicData() {

	// TEMP

	// END TEMP

}

void DecisionAlgorithm::run() {

	CountingModule::run(&m_musicDataList);


}

