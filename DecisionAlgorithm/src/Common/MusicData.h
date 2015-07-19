#include <string>

class MusicData {

public:

	MusicData(std::string, std::string, std::string);

	void setWeight(double);
	double getWeight();


private:

	std::string m_artist;
	std::string m_song;
	std::string m_genre;

	double m_weight;

};
