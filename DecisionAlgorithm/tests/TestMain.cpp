#include "TestMain.h"

#include "Modules\CountingModuleTests.h"
#include "Modules\VotingModuleTests.h"
#include "Modules\TierModuleTests.h"

void TestMain::runTests() {

	CountingModuleTests::runTests();
	VotingModuleTests::runTests();
	TierModuleTests::runTests();

}
