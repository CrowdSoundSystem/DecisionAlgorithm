#include <stdio.h>

#include "src\Common\DecisionSettings.h"
#include "src\DecisionAlgorithm.h"
#include "tests\TestMain.h"

int main()
{

	printf("Running Tests\n");
	TestMain::runTests();

	printf("Running Algorithm\n");
	DecisionSettings settings;
	settings.m_countWeight = 1.0;

	settings.m_voteWeight = DecisionSettings::VoteWeight_Equal;

	settings.m_songGenreWeight = DecisionSettings::VoteWeight_Equal;
	settings.m_artistGenreWeight = DecisionSettings::VoteWeight_Equal;

	settings.m_tierMultipliers[Tier_SAG] = 1.0f;
	settings.m_tierMultipliers[Tier_SA] = 0.9f;
	settings.m_tierMultipliers[Tier_SG] = 0.8f;
	settings.m_tierMultipliers[Tier_AG] = 0.7f;
	settings.m_tierMultipliers[Tier_S] = 0.6f;
	settings.m_tierMultipliers[Tier_A] = 0.5f;
	settings.m_tierMultipliers[Tier_G] = 0.4f;

	settings.m_numSongsGenerated = 3;
	
	DecisionAlgorithm algorithm(settings);

	while (true) {
		algorithm.run();
	}
	





	printf("\nHello World\n\n");
}
