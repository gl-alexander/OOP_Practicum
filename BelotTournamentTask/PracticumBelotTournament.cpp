#include <iostream>
#include "BelotTournament.h"


int main()
{
	BelotTournament bt(2);
	bt.addTeam({ "ivan", "SE", 1233 }, { "georgi", "Lead", 39393 });
	bt.addTeam({ "dragan", "ss", 12314 }, { "badad", "trr", 2890 });
	bt.addTeam({ "gert", "ew", 2 }, { "bacx", "weee", 43300 });
	bt.addTeam({ "iran", "ggg", 333 }, { "maddd", "Lddead", 8900 });
	bt.addTeam({ "stoioa", "SE", 4444 }, { "radan", "ssd", 9900 });

	bt.runTournament();
}