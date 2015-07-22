#include "GenerationModule.h"

void GenerationModule::run(DecisionSettings& settings, MusicDataList& musicDataSet, MusicDataList& nextSet) {

	musicDataSet.sort(compareWeight);

	int counter = 0;
	for each (MusicData data in musicDataSet) {
		nextSet.push_back(data);
		counter++;

		if (counter == settings.m_numSongsGenerated) {
			break;
		}
	}

}

bool GenerationModule::compareWeight(const MusicData& first, const MusicData& second)
{
	return (first.getWeight() < second.getWeight());
}