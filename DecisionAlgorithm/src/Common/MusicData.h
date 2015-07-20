#ifndef MusicData_HEADER
#define MusicData_HEADER

#include <string>

class MusicData {

public:

	MusicData(std::string, std::string, std::string);

	void addWeight(double);
	void subWeight(double);
	void mulWeight(double);

	void setWeight(double);
	double getWeight();


private:

	std::string m_artist;
	std::string m_song;
	std::string m_genre;

	double m_weight;

};

#endif
