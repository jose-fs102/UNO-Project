#pragma once
#include <iostream>
using namespace std;

#include "Player.h"
#include "Deck.h"
#include "Human.h"
#include "Computer.h"

// Enum of gamestates, you can add and remove from this if you need additional ones (examples include: GAME_TITLE, GAME_MENU, GAME_OPTIONS, etc).
enum GAMESTATE { GAME_INIT, GAME_TITLE, GAME_MENU, GAME_PLAY, GAME_INSTRUCT, GAME_OPTIONS, GAME_SCORE, GAME_END};

class Game
{
	// Necessary data members

	// Class objects
	Player* m_players[4];			// The players in the game
	Deck m_Deck;					// The deck of cards
	Stack<Item> m_Discard;			// Stack Object
	Card C_obj;						// Card object


	// Bools.
	bool bRun = true;				// bool to keep gaming running
	bool invalid = false;			// bool to check for invalid cards
	bool m_reversed = false;		// bool to keep track of the order of play
	bool still_running = true;		// bool to Keep the first game running
	bool Comp_turn = true;			// bool to check if its computers turn
	bool Needs_Draw = true;			// bool to check if a card needs to be drawn
	bool Cannot_Draw = false;		// bool to make sure the player cannot draw twice in a row
	bool go = true;					// bool to control do while loop in gameplay
	bool skip = false;				// bool to check if Skip card is used
	bool Turn_end = true;			// bool to keep do while going in turn function
	bool first_turn = true;			// bool to shut of the shuffle of special card
	bool resume = false;			// bool to check if player can return to and from the main menu
	bool wild = false;				// bool to check if wild draw 4 was played
	bool resume2 = false;			// bool to check if player wanted to start a new game with new players


	// Variables (ints).
	int menu_choice;				// Int for menu choices
	int player_face_choice;			// Int for players card choice
	int m_currPlayer = 0;			// Int that Keeps track of which index is currently taking their turn
	int m_numPlayers;				// The number of players playing in the game
	int score = 0;					// Int to gather scores;
	int choice;						// Int to accept a restart choice from player
	int count = 0;					// Int to increment count by one in case Reverse is played more than once
	int increase = 0;

	
	// Variables (chars).
	char player_color_choice;		// Char used to get player color input
	char cheat_choice;				// Char used to get input for cheats
	

	GAMESTATE m_state;				// GAMESTATE object to store the game's current state.


public:
	// Default ctor
	Game();

	// Dtor
	~Game();

	// The main function of the game, this loops until a certain gamestate is set.
	void Run();

	// Modifier for the gamestate data member.
	void SetState(GAMESTATE _state) { m_state = _state; }

	// Function for controlling the distribution of cards to players
	void Distribute_Cards(int players);

	// Function for load menu.
	void Load();

	// Function for Game
	void Game_Prompt();

	// Function for a full turn
	void Turn(int CurrPlayer, int player_face_choice, char player_color_choice);

	// Function to check if reversed was played
	void Is_Reversed();

	// Function to check if skip was played
	void Is_Skip();

	// Function to check the discard card
	void Check_Peek();

	// Function to display and keep track of scores and hands
	void Score_Track(int Total_Players);

	// Get the score for the game
	//	For Go Fish, this will take care of pairing
	//  For UNO, this will be used for end of round scoring.
	// int Score(Player* _player);
};