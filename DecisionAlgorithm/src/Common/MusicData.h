#ifndef MusicData_HEADER
#define MusicData_HEADER

#include <string>

enum Tier {
	Tier_INVALID = 0,
	Tier_SAG,
	Tier_SA,
	Tier_SG, 
	Tier_AG,
	Tier_S,
	Tier_A,
	Tier_G
};

class MusicData {

public:

	MusicData()
		: m_score(0), m_voteSum(0), m_tier(0), m_count(0), m_id(0)
	{}

	MusicData(double score, int voteSum, int tier, int count, int id, std::string song, std::string artist, std::string genre)
		: m_score(score), m_voteSum(voteSum), m_tier(tier), m_count(count), m_id(id), m_song(song), m_artist(artist), m_genre(genre)
	{}

	void addArtist(std::string);
	std::string getArtist() const;
	void addSong(std::string);
	std::string getSong() const;
	void addGenre(std::string);
	std::string getGenre() const;

	Tier getTier();

	void setId(int);
	int getId();

	void setCount(int);
	int getCount();

	void addScore(double);
	void subScore(double);
	void mulScore(double);

	void setVoteSum(int);
	int getVoteSum() const;

	void setScore(double);
	double getScore() const;

	void setPreviouslyPlayed(bool);
	bool getPreviouslyPlayed() const;

private:

	int m_id;

	int m_tier;

	std::string m_artist;
	std::string m_song;
	std::string m_genre;

	double m_score;

	int m_voteSum;
	int m_count;

	bool m_previouslyPlayed;

};

#endif
