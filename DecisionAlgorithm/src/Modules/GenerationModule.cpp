#include "GenerationModule.h"

void GenerationModule::run(DecisionSettings& settings, MusicDataList& musicDataSet, MusicDataList& nextSet) {

	musicDataSet.sort(compareWeight);

	int counter = 0;
	MusicDataList::iterator itr = musicDataSet.begin();
	while (itr != musicDataSet.end()) 
	{
		nextSet.push_back((*itr));
		counter++;

		++itr;
	}

}

bool GenerationModule::compareWeight(const MusicData& first, const MusicData& second)
{
	return (first.getScore() > second.getScore());
}