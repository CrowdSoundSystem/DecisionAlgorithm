#include "CountingModule.h"

void CountingModule::run(MusicDataList* musicDataSet) {

	MusicDataList::iterator setItr;
	for (setItr = musicDataSet->begin(); setItr != musicDataSet->end(); ++setItr) {
		(*setItr)->addWeight(1.0);
	}

}
