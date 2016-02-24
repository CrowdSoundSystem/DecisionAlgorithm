#include "MusicData.h"

Tier MusicData::getTier() {

	switch (m_tier)
	{
		case Tier_S:
		case Tier_A:
		case Tier_G:
		case Tier_SG:
		case Tier_SA:
		case Tier_AG:
		case Tier_SAG:
			return static_cast<Tier>(m_tier);
		default:
			return Tier_INVALID;
	}
}

void MusicData::setId(int id) {
	m_id = id;
}

int MusicData::getId() {
	return m_id;
}

void MusicData::setCount(int count) {
	m_count = count;
}

int MusicData::getCount() {
	return m_count;
}

void MusicData::addArtist(std::string artist){
	m_tier |= Tier_A;
	m_artist = artist;
}

std::string MusicData::getArtist() const {
	return m_artist;
}

void MusicData::addSong(std::string song){
	m_tier |= Tier_S;
	m_song = song;
}

std::string MusicData::getSong() const {
	return m_song;
}

void MusicData::addGenre(std::string genre){
	m_tier |= Tier_G;
	m_genre = genre;
}

std::string MusicData::getGenre() const {
	return m_genre;
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

void MusicData::setVoteSum(int votes){
	m_voteSum = votes;
}

int MusicData::getVoteSum() const {
	return m_voteSum;
}

void MusicData::setPreviouslyPlayed(bool played) {
	m_previouslyPlayed = played;
}

bool MusicData::getPreviouslyPlayed() const {
	return m_previouslyPlayed;
}
