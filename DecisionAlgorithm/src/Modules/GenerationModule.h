#ifndef GenerationModule_HEADER
#define GenerationModule_HEADER

#include <list>

#include "../Common/DecisionSettings.h"
#include "../Common/MusicData.h"
#include "../Common/Const.h"

class GenerationModule {

public:

	static void run(DecisionSettings&, MusicDataList&, MusicDataList&);

private:

	static bool compareWeight(const MusicData& first, const MusicData& second);

};

#endif
