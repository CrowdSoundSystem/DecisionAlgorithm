#include "DecisionAlgorithm.h"

#include <iostream>

#include "Modules/CountingModule.h"
#include "Modules/GenerationModule.h"
#include "Modules/TierModule.h"
#include "Modules/VotingModule.h"

using namespace std;

void DecisionAlgorithm::getMusicData() {

	m_musicDataList.clear();

#if DEBUG_MODE == 0
	skrillex::ResultSet<skrillex::Song> songs;
	m_db->getSongs(songs);

	for (auto& song : songs) {

		MusicData musicData;

        if(song.last_played > 0) {
			cout << "[Algorithm] Dropping " << song.name << ", as it was previously played" << endl;
			musicData.setPreviouslyPlayed(true);
        }

		if (!song.name.empty())
			musicData.addSong(song.name);

		if (!song.artist.name.empty())
			musicData.addArtist(song.artist.name);

		if (!song.genre.name.empty())
			musicData.addArtist(song.genre.name);

		musicData.setCount(song.count);
		musicData.setVoteSum(song.votes);
		musicData.setId(song.id);

		m_musicDataList.push_back(musicData);
	}
#else

	const MusicData data[30] = { 
		// double score, int voteSum, int tier, int count, int id, std::string song, std::string artist, std::string genre
		{ 0, 0, 1, 1, 0, "Song #01", "Artist #14", "Genre #3" },
		{ 0, 2, 1, 2, 0, "Song #02", "Artist #7", "Genre #3" },
		{ 0, 3, 1, 3, 0, "Song #03", "Artist #5", "Genre #3" },
		{ 0, -1, 1, 5, 0, "Song #04", "Artist #2", "Genre #3" },
		{ 0, 3, 1, 2, 0, "Song #05", "Artist #10", "Genre #2" },
		{ 0, 2, 2, 2, 0, "Song #06", "Artist #3", "Genre #3"},
		{ 0, 2, 1, 6, 0, "Song #07", "Artist #19", "Genre #2" },
		{ 0, 0, 1, 9, 0, "Song #08", "Artist #10", "Genre #3" },
		{ 0, 0, 1, 8, 0, "Song #09", "Artist #15", "Genre #4"},
		{ 0, 5, 1, 6, 0, "Song #10", "Artist #15", "Genre #3" },
		{ 0, -3, 3, 3, 0, "Song #11", "Artist #1", "Genre #2" },
		{ 0, 0, 1, 12, 0, "Song #12", "Artist #1", "Genre #1" },
		{ 0, 2, 1, 2, 0, "Song #13", "Artist #5", "Genre #2" },
		{ 0, 2, 1, 1, 0, "Song #14", "Artist #13", "Genre #4"},
		{ 0, 1, 1, 7, 0, "Song #15", "Artist #2", "Genre #5" },
		{ 0, 1, 5, 7, 0, "Song #16", "Artist #12", "Genre #4" },
		{ 0, -5, 1, 16, 0, "Song #17", "Artist #4", "Genre #5"},
		{ 0, 1, 1, 13, 0, "Song #18", "Artist #11", "Genre #4" },
		{ 0, 1, 1, 3, 0, "Song #19", "Artist #6", "Genre #4" },
		{ 0, 0, 1, 4, 0, "Song #20", "Artist #16", "Genre #2" },
		{ 0, 1, 1, 2, 0, "Song #21", "Artist #17", "Genre #4"},
		{ 0, -7, 1, 4, 0, "Song #22", "Artist #8", "Genre #3" },
		{ 0, 1, 5, 1, 0, "Song #23", "Artist #9", "Genre #6"},
		{ 0, -2, 2, 16, 0, "Song #24", "Artist #5", "Genre #3" },
		{ 0, 2, 1, 7, 0, "Song #25", "Artist #1", "Genre #1" },
		{ 0, 3, 1, 8, 0, "Song #26", "Artist #18", "Genre #4" },
		{ 0, -2, 1, 2, 0, "Song #27", "Artist #3", "Genre #3" },
		{ 0, 0, 1, 12, 0, "Song #28", "Artist #3", "Genre #2" },
		{ 0, 0, 2, 16, 0, "Song #29", "Artist #1", "Genre #1"},
		{ 0, 0, 1, 1, 0, "Song #30", "Artist #20", "Genre #5"},
	};

	for (int i = 0; i < 30; i++)
		m_musicDataList.push_back(data[i]);

#endif

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

#if DEBUG_MODE == 0
	m_db.clearQueue();
#endif

	MusicDataList::iterator itr = nextSet.begin();
	while (itr != nextSet.end())
	{
#if DEBUG_MODE == 0
		cout << "[Algorithm] Queueing song: " << itr->getSong() << endl;
		m_db->queueSong((*itr).getId());
#else
		cout << itr->getSong() << " " << itr->getScore() << endl;
#endif
		++itr;
	}

}
