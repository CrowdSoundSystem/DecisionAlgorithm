#ifndef MusicData_HEADER
#define MusicData_HEADER

#include <string>

class MusicData {

public:

	enum Tier {
		Tier_S = 1,
		Tier_A,
		Tier_G,
		Tier_SG,
		Tier_SA,
		Tier_AG,
		Tier_SAG
	};

	MusicData::MusicData()
		: m_weight(0), m_voteSum(0)
	{}

	void addArtist(std::string);
	std::string getArtist();
	void addSong(std::string);
	std::string getSong();
	void addGenre(std::string);
	std::string getGenre();

	Tier getTier();

	void addWeight(double);
	void subWeight(double);
	void mulWeight(double);

	void setVoteSum(int);
	int getVoteSum();

	void setWeight(double);
	double getWeight();


private:

	Tier m_tier;

	std::string m_artist;
	std::string m_song;
	std::string m_genre;

	double m_weight;

	int m_voteSum;

};

#endif
