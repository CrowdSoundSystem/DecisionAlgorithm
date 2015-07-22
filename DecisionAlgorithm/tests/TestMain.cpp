#include "TestMain.h"

#include "Modules\CountingModuleTests.h"
#include "Modules\VotingModuleTests.h"

void TestMain::runTests() {

	CountingModuleTests::runTests();
	VotingModuleTests::runTests();

}
