#ifndef DecisionAlgorithm_HEADER
#define DecisionAlgorithm_HEADER

#include <list>
#include <memory>

#include "Common/Const.h"
#include "Common/DecisionSettings.h"
#include "Common/MusicData.h"

// DB stuff
#include "skrillex/skrillex.hpp"

class DecisionAlgorithm {

public:

	DecisionAlgorithm(DecisionSettings settings, std::shared_ptr<skrillex::DB> db)
		: m_settings(settings), m_db(db)
	{
	}

	void getMusicData();

	void run();


private:

	MusicDataList m_musicDataList;
	DecisionSettings m_settings;
	
	std::shared_ptr<skrillex::DB> m_db;

};

#endif

