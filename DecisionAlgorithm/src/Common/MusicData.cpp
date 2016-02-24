#include "MusicData.h"

void MusicData::setTier(Tier tier) {
	m_tier = tier;
}

Tier MusicData::getTier() {
	return m_tier;
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
	switch (m_tier)
	{
	case Tier_SG:
		m_tier = Tier_SAG;
		break;
	case Tier_S:
		m_tier = Tier_SA;
		break;
	case Tier_G:
		m_tier = Tier_AG;
		break;
	case Tier_INVALID:
	default:
		m_tier = Tier_A;
		break;
	}

	m_artist = artist;
}

std::string MusicData::getArtist() const {
	return m_artist;
}

void MusicData::addSong(std::string song){
	switch (m_tier)
	{
	case Tier_AG:
		m_tier = Tier_SAG;
		break;
	case Tier_A:
		m_tier = Tier_SA;
		break;
	case Tier_G:
		m_tier = Tier_SG;
		break;
	case Tier_INVALID:
	default:
		m_tier = Tier_S;
		break;
	}

	m_song = song;
}

std::string MusicData::getSong() const {
	return m_song;
}

void MusicData::addGenre(std::string genre){
	switch (m_tier)
	{
	case Tier_SA:
		m_tier = Tier_SAG;
		break;
	case Tier_S:
		m_tier = Tier_SG;
		break;
	case Tier_A:
		m_tier = Tier_AG;
		break;
	case Tier_INVALID:
	default:
		m_tier = Tier_G;
		break;
	}

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
