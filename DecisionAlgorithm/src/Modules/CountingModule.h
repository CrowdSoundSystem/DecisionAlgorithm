#ifndef CountingModule_HEADER
#define CountingModule_HEADER

#include <list>

#include "..\Common\DecisionSettings.h"
#include "..\Common\MusicData.h"
#include "..\Common\Const.h"

class CountingModule {

public:

	static void run(DecisionSettings, MusicDataList*);

};

#endif