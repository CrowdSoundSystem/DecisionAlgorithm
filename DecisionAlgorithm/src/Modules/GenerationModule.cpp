#include "GenerationModule.h"

#include <algorithm>

void GenerationModule::run(DecisionSettings& settings, MusicDataList& musicDataSet, MusicDataList& nextSet) 
{
	// Lets try to get some variance witht he equally weighted values
	std::random_shuffle(musicDataSet.begin(), musicDataSet.end());

	std::sort(musicDataSet.begin(), musicDataSet.end(), [](const MusicData& first, const MusicData& second) {
		return (first.getScore() > second.getScore());
	});

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