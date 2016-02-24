#ifndef DecisionAlgorithm_HEADER
#define DecisionAlgorithm_HEADER

#include <list>
#include <memory>

#include "Common/Const.h"
#include "Common/DecisionSettings.h"
#include "Common/MusicData.h"

#define DEBUG_MODE 0

#if DEBUG_MODE == 0
// DB stuff
#include "skrillex/skrillex.hpp"
#endif

class DecisionAlgorithm {

public:

#if DEBUG_MODE == 0
	DecisionAlgorithm(DecisionSettings settings, std::shared_ptr<skrillex::DB> db)
		: m_settings(settings), m_db(db)
	{}
#else
	DecisionAlgorithm(DecisionSettings settings)
		: m_settings(settings)
	{}
#endif

	void run();

private:

	void getMusicData();

	MusicDataList m_musicDataList;
	DecisionSettings m_settings;

#if DEBUG_MODE == 0
	std::shared_ptr<skrillex::DB> m_db;
#endif

};

#endif

