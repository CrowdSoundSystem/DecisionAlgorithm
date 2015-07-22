#ifndef DecisionAlgorithm_HEADER
#define DecisionAlgorithm_HEADER

#include <list>

#include "Common/Const.h"
#include "Common/DecisionSettings.h"
#include "Common/MusicData.h"

class DecisionAlgorithm {

public:

	DecisionAlgorithm(DecisionSettings settings)
		: m_settings(settings)
	{
	}

	void getMusicData();

	void run();


private:

	MusicDataList m_musicDataList;
	DecisionSettings m_settings;

};

#endif

