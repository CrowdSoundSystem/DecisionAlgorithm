#include <stdio.h>

#include "src\Common\DecisionSettings.h"
#include "src\DecisionAlgorithm.h"
#include "tests\TestMain.h"

int main()
{

	printf("Running Tests\n");
	TestMain::runTests();

	printf("Running Algorithm\n");

	DecisionAlgorithm algorithm(DecisionSettings::defaultSettings(), nullptr);

	while (true) {
		algorithm.run();
	}
	
}
