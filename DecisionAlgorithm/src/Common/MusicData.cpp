#include "MusicData.h"

MusicData::MusicData(std::string artist, std::string song, std::string genre)
	: m_weight(0), m_voteSum(0)
{
	m_artist = artist;
	m_song = song;
	m_genre = genre;
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

