#include "DecisionAlgorithm.h"

#include <iostream>

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

void DecisionAlgorithm::run() {
	getMusicData();

    cout << "[Algorithm] Retrieved " << m_musicDataList.size() << " songs from db." << endl;
    cout << "[Algorithm] Running modules..." << endl;

	MusicDataList nextSet;

	CountingModule::run(m_settings, m_musicDataList);
	VotingModule::run(m_settings, m_musicDataList);
	TierModule::run(m_settings, m_musicDataList);
	GenerationModule::run(m_settings, m_musicDataList, nextSet);

	m_db->clearQueue();

	MusicDataList::iterator itr = nextSet.begin();
	while (itr != nextSet.end())
	{
		cout << "[Algorithm] Queueing song: " << itr->getSong() << endl;
		m_db->queueSong((*itr).getId());
		++itr;
	}

}
