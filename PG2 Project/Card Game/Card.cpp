#include "Card.h"

// Default constructor
// In:	_face			The face value of the card
//		_suit			The suit of the card
Card::Card(int _face, char _suit)
{
	/* TODO Lab1:
			Fill out the constructor body
	*/

	m_face = _face;
	m_suit = _suit;
}

Card::~Card()
{

}


/* Accessors */

/* TODO Lab1:
		Define the two accessors if they were not inlined.
*/

/* Mutators */

/* TODO Lab1:
		Define the two mutators if they were not inlined.
*/

// Display a card to the screen
void Card::Show() const
{
	/* TODO Lab1:
			Display the Card object.  

			Make sure that "face" cards (Jack-Ace) display as 'J', 'Q', 'K', 'A'
			or something similar instead of their numeric value.

			*Note - This unit test is not automated, so make sure you verify 
			the face card is displaying correctly.
	*/

	switch (m_face)
	{
	case 10:
		cout << "DRAW 2  " << m_suit;
		break;
	case 11:
		cout << "REVERSE  " << m_suit;
		break;
	case 12: 
		cout << "SKIP " << m_suit;
		break;
	case 13: 
		cout << "WILD  " << m_suit;
		break;
	case 14: 
		cout << "WILD DRAW 4  " << m_suit;
	default:
		cout << GetFace() << GetSuit();
		break;
	}
}

// Relational operators

/* TODO Lab1:
		Define the six relational operators if they were not inlined.
*/

// Insertion operator to display Cards with cout (or any other ostream object)

/* TODO Lab1:
		Define the insertion operator to display a card.

		Make sure that "face" cards (Jack-Ace) display as 'J', 'Q', 'K', 'A'
		or something similar instead of their numeric value.

		*Note - This unit test is not automated, so make sure you verify
		the face card is displaying correctly.
*/

ostream& operator<<(ostream& _os, const Card& _NewVal)
{
	switch (_NewVal.GetFace())
	{
	case 10:
		_os << "DRAW 2  " << _NewVal.GetSuit();
		break;
	case 11:
		_os << "REVERSE  " << _NewVal.GetSuit();
		break;
	case 12:
		_os << "SKIP " << _NewVal.GetSuit();
		break;
	case 13:
		_os << "WILD  " << _NewVal.GetSuit();
		break;
	case 14:
		_os << "WILD DRAW 4  " << _NewVal.GetSuit();
		break;
	default:
		_os << _NewVal.GetFace() << _NewVal.GetSuit();
		break;
	}

	return _os;

}