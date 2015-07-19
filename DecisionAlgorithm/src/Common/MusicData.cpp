#include "MusicData.h"

MusicData::MusicData(std::string artist, std::string song, std::string genre) {
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
