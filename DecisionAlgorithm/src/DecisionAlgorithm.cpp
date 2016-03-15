#include "DecisionAlgorithm.h"

#include <iostream>
#include <vector>

#include "Modules/CountingModule.h"
#include "Modules/GenerationModule.h"
#include "Modules/TierModule.h"
#include "Modules/VotingModule.h"

using namespace std;

void DecisionAlgorithm::getMusicData() {

	m_musicDataList.clear();

	skrillex::ResultSet<skrillex::Song> songs;
	m_db->getSongs(songs);

	for (auto& song : songs)
	{
		MusicData musicData;
		musicData.setSong(song);

		m_musicDataList.push_back(musicData);
	}
}

void DecisionAlgorithm::run(DecisionSettings settings) {
    lock_guard<mutex> lock(m_run_mutex);

	getMusicData();

    cout << "[Algorithm] Retrieved " << m_musicDataList.size() << " songs from db." << endl;
    cout << "[Algorithm] Running modules..." << endl;

	MusicDataList nextSet;

	CountingModule::run(settings, m_musicDataList);
	VotingModule::run(settings, m_musicDataList);
	TierModule::run(settings, m_musicDataList);
	GenerationModule::run(settings, m_musicDataList, nextSet);


	vector<int> songIds;

	MusicDataList::iterator itr = nextSet.begin();
	while (itr != nextSet.end())
	{
		cout << "[Algorithm] Queueing song: " << itr->getSong() << endl;
		songIds.push_back(itr->getId());
		++itr;
	}

	// Atomic set.
	m_db->setQueue(songIds);
}
