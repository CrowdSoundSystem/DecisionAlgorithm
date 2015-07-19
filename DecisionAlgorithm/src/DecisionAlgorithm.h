#include <list>

#include "Common\MusicData.h"

class DecisionAlgorithm {

public:

	DecisionAlgorithm();

	void getMusicData();

	void run();


private:

	std::list<MusicData> m_musicDataList;


};


