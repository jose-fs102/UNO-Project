#include "Computer.h"

// Default ctor
Computer::Computer(const char* _name) : Player(_name)
{
	/* TODO Lab2:
			Implement this method.
	
			Send back the appropriate information to the parent/base class.
	*/
}

// Display the computer's name and card backs
void Computer::Show() const
{
	/* TODO Lab2:
			Implement this method.
	
			Should display the name of the player as well as their card backs.

			Example:		Computer
							XX XX XX XX

	*/

	Card Object;

	cout << GetName() << endl;

	if (GetCheat() &1)
	{
		for (int i = 0; i < GetNumCards(); i++)
		{
			GetCard(i, Object);
			cout << Object << " // ";
		}
	}
	else
	{
		for (int i = 0; i < GetNumCards(); i++)
		{
			GetCard(i, Object);
			cout << "XX" << " // ";
		}
	}
}
