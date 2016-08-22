// main.cpp : Entry point for the project

// This includes all of our standard headers
#include "src\\UnitTest++.h"
#include "src\\TestReporterStdout.h"

#include "stdafx.h"

#include "TestManager.h"

#include "Game.h"

/***********/
/* Globals */
/***********/

/**************/
/* Prototypes */
/**************/

// Our primary routine.  This is called when the program starts.
//
// Return:	We always return 0.
int main(int, const char*[])
{
	// This will check for memory leaks.  They will show up in your
	// output window along with the line number.  Replace the 
	// -1 argument in the second call with the allocation number
	// and then trace back through the call stack to find the leak.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(-1);
	
	srand(unsigned int(time(0)));


#if GAME
	Game game;
	game.Run();
#else
	UnitTest::RunAllTests();
#endif

	Console::ResetColor();
	cout << "\n\n";
	system("pause");
	return 0;
}