#ifndef MusicData_HEADER
#define MusicData_HEADER

#include <string>

enum Tier {
	Tier_INVALID = 0,

	Tier_S = (1u << 0),
	Tier_A = (1u << 1),
	Tier_G = (1u << 2),

	Tier_SG = Tier_S + Tier_G,
	Tier_SA = Tier_S + Tier_A,
	Tier_AG = Tier_A + Tier_G,

	Tier_SAG = Tier_S + Tier_A + Tier_G
};

class MusicData {

public:

	MusicData()
		: m_weight(0), m_voteSum(0), m_tier(0)
	{}

	void addArtist(std::string);
	std::string getArtist() const;
	void addSong(std::string);
	std::string getSong() const;
	void addGenre(std::string);
	std::string getGenre() const;

	Tier getTier();

	void addWeight(double);
	void subWeight(double);
	void mulWeight(double);

	void setVoteSum(int);
	int getVoteSum() const;

	void setWeight(double);
	double getWeight() const;


private:

	int m_tier;

	std::string m_artist;
	std::string m_song;
	std::string m_genre;

	double m_weight;

	int m_voteSum;

};

#endif
