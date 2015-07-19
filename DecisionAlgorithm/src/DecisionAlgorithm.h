#ifndef DecisionAlgorithm_HEADER
#define DecisionAlgorithm_HEADER

#include <list>

#include "Common\MusicData.h"
#include "Common\Const.h"

class DecisionAlgorithm {

public:

	DecisionAlgorithm();

	void getMusicData();

	void run();


private:

	MusicDataList m_musicDataList;


};

#endif

