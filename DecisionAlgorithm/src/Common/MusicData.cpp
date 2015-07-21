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

void MusicData::addArtist(std::string artist){
	m_tier |= Tier_A;
	m_artist = artist;
}

std::string MusicData::getArtist(){
	return m_artist;
}

void MusicData::addSong(std::string song){
	m_tier |= Tier_S;
	m_song = song;
}

std::string MusicData::getSong(){
	return m_song;
}

void MusicData::addGenre(std::string genre){
	m_tier |= Tier_G;
	m_genre = genre;
}

std::string MusicData::getGenre(){
	return m_genre;
}

void MusicData::setWeight(double weight) {
	m_weight = weight;
}

double MusicData::getWeight(){
	return m_weight;
}

void MusicData::addWeight(double value) {
	m_weight += value;
}

void MusicData::subWeight(double value) {
	m_weight -= value;
}

void MusicData::mulWeight(double value) {
	m_weight *= value;
}

void MusicData::setVoteSum(int votes){
	m_voteSum = votes;
}

int MusicData::getVoteSum() {
	return m_voteSum;
}

