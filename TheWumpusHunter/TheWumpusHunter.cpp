#include <iostream>
#include"Cavern.h"
#include"Cave.h"
#include"TheWumpusHunter.h"
#include"Player.h"
#include"textMessage.h"

using namespace std;

#ifndef UNIT_TESTS
int main()
{  
    Cavern theCaves;
    theCaves.playGame();
}
#else //UNIT_TESTS defined
#include"UnitTests.h"
int main()
{
    int testStatus;
    cerr << "Main:  Running Unit Tests\n";
    //The name of the UnitTests object reflects the date the tests were last revised.
    UnitTests T20200902;
    testStatus = T20200902.runTests();
    cerr << "Main: " << TEST_MESSAGES[testStatus];
    cerr << "Main: Not running Integration Tests yet.\n";


}
#endif