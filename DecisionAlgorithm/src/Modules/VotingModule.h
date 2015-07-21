#ifndef VotingModule_HEADER
#define VotingModule_HEADER

#include <list>

#include "..\Common\DecisionSettings.h"
#include "..\Common\MusicData.h"
#include "..\Common\Const.h"

class VotingModule {

public:

	static void run(DecisionSettings&, MusicDataList&);
	static float getVoteWeight(DecisionSettings&);

};

#endif