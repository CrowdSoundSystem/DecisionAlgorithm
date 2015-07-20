#ifndef TierModule_HEADER
#define TierModule_HEADER

#include <list>

#include "..\Common\DecisionSettings.h"
#include "..\Common\MusicData.h"
#include "..\Common\Const.h"

class TierModule {

public:

	static void run(DecisionSettings&, MusicDataList&);

};

#endif