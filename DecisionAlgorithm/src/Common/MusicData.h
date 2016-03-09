#ifndef MusicData_HEADER
#define MusicData_HEADER

#include <string>
#include <stdint.h>

#include "skrillex/skrillex.hpp"

enum Tier {
	Tier_INVALID = 0,

	Tier_S = 1 << 0,
	Tier_A = 1 << 1,
	Tier_G = 1 << 2,

	Tier_SA	= Tier_S | Tier_A,
	Tier_SG	= Tier_S | Tier_G,
	Tier_AG	= Tier_G | Tier_A,

	Tier_SAG = Tier_S | Tier_A | Tier_G
};

class MusicData {

public:

	MusicData()
		: m_score(0), m_tier(Tier_INVALID)
	{}

	MusicData(double score, int tier)
		: m_score(score), m_tier(static_cast<Tier>(tier))
	{}

	void setSong(skrillex::Song&);

	std::string getArtist() const;
	std::string getSong() const;
	std::string getGenre() const;

	Tier getTier();
	void setTier(Tier);

	int getId();
	int getCount();
	int getVotes();
	int getArtistVotes();
	int getGenreVotes();

	void addScore(double);
	void subScore(double);
	void mulScore(double);

	void setScore(double value);
	double getScore() const;

	uint64_t getPreviouslyPlayed() const;

private:

	Tier m_tier;
	double m_score;

	skrillex::Song m_song;

};

#endif
