#ifndef TierModuleTests_HEADER
#define TierModuleTests_HEADER

#include "..\..\src\Common\Const.h"

class TierModuleTests {

public:
	static void runTests();

private:
	static MusicDataList getMusicTestData();

	static void test_1();
	static void test_2();
	static void test_3();

};

#endif