#ifndef CountingModuleTests_HEADER
#define CountingModuleTests_HEADER

#include "..\..\src\Modules\CountingModule.h"

class CountingModuleTests {

public:
	static void runTests();

private:
	static std::list<MusicData> getMusicTestData();

	static void test_1();



};

#endif