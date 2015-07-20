#include <stdio.h>

#include "src\Common\DecisionSettings.h"
#include "src\DecisionAlgorithm.h"
#include "tests\TestMain.h"

int main()
{

	//TestMain::runTests();

	DecisionSettings settings;
	settings.m_countWeight = 1.0;

	settings.m_voteWeight = DecisionSettings::VoteWeight_Equal;

	settings.m_songGenreWeight = DecisionSettings::VoteWeight_Equal;
	settings.m_artistGenreWeight = DecisionSettings::VoteWeight_Equal;

	settings.m_tierMultiplierSAG = 1.0f;
	settings.m_tierMultiplierSA = 0.9f;
	settings.m_tierMultiplierSG = 0.8f;
	settings.m_tierMultiplierAG = 0.7f;
	settings.m_tierMultiplierS = 0.6f;
	settings.m_tierMultiplierA = 0.5f;
	settings.m_tierMultiplierG = 0.4f;


	
	DecisionAlgorithm algorithm(settings);

	while (true) {
		algorithm.run();
	}
	





	printf("\nHello World\n\n");
}
