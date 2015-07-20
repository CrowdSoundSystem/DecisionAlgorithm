#include "CountingModule.h"

void CountingModule::run(DecisionSettings& settings, MusicDataList& musicDataSet) {

	MusicDataList::iterator setItr;
	for (setItr = musicDataSet.begin(); setItr != musicDataSet.end(); ++setItr) {
		(*setItr)->addWeight(settings.m_countWeight);
	}

}
