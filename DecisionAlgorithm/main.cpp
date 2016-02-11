#include <stdio.h>

#include "src\Common\DecisionSettings.h"
#include "src\DecisionAlgorithm.h"
#include "tests\TestMain.h"

int main()
{

	printf("Running Tests\n");
	//TestMain::runTests();

	printf("Running Algorithm\n");


	DecisionSettings settings = DecisionSettings::defaultSettings();
	settings.m_numSongsGenerated = 30;

	DecisionAlgorithm algorithm(settings);

	algorithm.run();
	
}
