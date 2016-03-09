#include "MusicData.h"

void MusicData::setSong(skrillex::Song& song)
{
	m_song = song;

	if (!getSong().empty())
		m_tier = Tier_S;

	if (!getArtist().empty())
		m_tier = static_cast<Tier>(m_tier + Tier_A);

	if (!getGenre().empty())
		m_tier = static_cast<Tier>(m_tier + Tier_G);
}

void MusicData::setTier(Tier tier) {
	m_tier = tier;
}

Tier MusicData::getTier() {
	return m_tier;
}

int MusicData::getId() {
	return m_song.id;
}

int MusicData::getCount() {
	return m_song.count;
}

int MusicData::getVotes() {
	return m_song.votes;
}

int MusicData::getArtistVotes() {
	return m_song.artist.votes;
}

int MusicData::getGenreVotes() {
	return m_song.genre.votes;
}

std::string MusicData::getArtist() const {
	return m_song.artist.name;
}

std::string MusicData::getSong() const {
	return m_song.name;
}

std::string MusicData::getGenre() const {
	return m_song.genre.name;
}

void MusicData::setScore(double value) {
	m_score = value;
}

double MusicData::getScore() const {
	return m_score;
}

void MusicData::addScore(double value) {
	m_score += value;
}

void MusicData::subScore(double value) {
	m_score -= value;
}

void MusicData::mulScore(double value) {
	m_score *= value;
}

uint64_t MusicData::getPreviouslyPlayed() const {
	return m_song.last_played;
}
