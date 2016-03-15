#ifndef DecisionAlgorithm_HEADER
#define DecisionAlgorithm_HEADER

#include <list>
#include <memory>
#include <mutex>

#include "Common/Const.h"
#include "Common/DecisionSettings.h"
#include "Common/MusicData.h"

// DB stuff
#include "skrillex/skrillex.hpp"

class DecisionAlgorithm {

public:

	DecisionAlgorithm(std::shared_ptr<skrillex::DB> db)
		: m_db(db)
	{}

	void run(DecisionSettings settings);

private:

	void getMusicData();

	MusicDataList m_musicDataList;

	std::shared_ptr<skrillex::DB> m_db;
    std::mutex m_run_mutex;
};

#endif

