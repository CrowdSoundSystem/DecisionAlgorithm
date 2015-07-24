#include "DecisionAlgorithm.h"

#include "Modules/CountingModule.h"
#include "Modules/GenerationModule.h"
#include "Modules/TierModule.h"
#include "Modules/VotingModule.h"

void DecisionAlgorithm::getMusicData() {

	skrillex::ResultSet<skrillex::Song> songs;
	m_db->getSongs(songs);
    
    m_musicDataList.clear();

	for (auto& song : songs) {

		MusicData musicData;
        
		// TEMP: skip any songs that have already played. We want better logic here to repeat if enough time has passed?
        if(song.last_played > 0) {
            continue;
        }
		// END TEMP
        
		if (!song.name.empty()) {
			musicData.addSong(song.name);
		}

		if (!song.artist.name.empty()) {
			musicData.addArtist(song.artist.name);
		}

		if (!song.genre.name.empty()) {
			musicData.addArtist(song.genre.name);
		}

		musicData.setCount(song.count);
		musicData.setVoteSum(song.votes);
		musicData.setId(song.id);

		m_musicDataList.push_back(musicData);
	}

}

void DecisionAlgorithm::run() {

	getMusicData();

	MusicDataList nextSet;

	CountingModule::run(m_settings, m_musicDataList);
	VotingModule::run(m_settings, m_musicDataList);
	TierModule::run(m_settings, m_musicDataList);
	GenerationModule::run(m_settings, m_musicDataList, nextSet);

	MusicDataList::iterator itr = nextSet.begin();
	while (itr != nextSet.end())
	{
		m_db->queueSong((*itr).getId());
		++itr;
	}

}
