#include "Game.h"


// Default ctor
Game::Game()
{
	m_state = GAME_INIT;
}


// Dtor
Game::~Game()
{
	for (int i = 0; i < 4; i++)
	{
		delete m_players[i];
	}
}

void Game::Run()
{

	// Loop while our bool remains true.
	while (bRun)
	{
		switch (m_state)
		{

			// GAME INITIALIZATION.

		case GAME_INIT:

			m_players[0] = new Human;

			for (int i = 1; i < 4; i++)
			{
				m_players[i] = new Computer;
			}

			m_state = GAME_TITLE;
			break;


			//*******************************************************************************************************************
			//*******************************************************************************************************************
			//*******************************************************************************************************************


			// GAME TITLE

		case GAME_TITLE:
			Console::Clear();


			Console::SetCursorPosition(35, 0);
			Console::ForegroundColor(Blue);
			cout << " HELLO ";
			Console::SetCursorPosition(35, 2);
			Console::ForegroundColor(Red);
			cout << " WELCOME ";
			Console::SetCursorPosition(35, 4);
			Console::ForegroundColor(Green);
			cout << " TO ";
			Console::SetCursorPosition(35, 6);
			Console::ForegroundColor(Yellow);
			cout << " UNO ";

			Console::ResetColor();

			Sleep(4000);

			m_state = GAME_MENU;
			break;


			//*******************************************************************************************************************
			//*******************************************************************************************************************
			//*******************************************************************************************************************


			// GAME MENU CODE.

		case GAME_MENU:

			Console::Clear();

			if (!resume)
			{
				cout << "Welcome to UNO! \n\n";
				cout << "1: Play Game \n\n";
				cout << "2: Instructions \n\n";
				cout << "3: Options \n\n";
				cout << "4: Exit Game \n\n";
				cout << "Enter Your Choice:_\b";
				cin >> menu_choice;

				while (menu_choice <= 0 || menu_choice >= 5)
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');

					cout << "Invalid Entry \n";
					Sleep(1000);
					Console::Clear();

					cout << "Welcome to UNO! \n\n";
					cout << "1: Play Game \n\n";
					cout << "2: Instructions \n\n";
					cout << "3: Options \n\n";
					cout << "4: Exit Game \n\n";
					cout << "Enter Your Choice: ";
					cin >> menu_choice;
					continue;
				}
			}
			if (resume)
			{
				cout << "Welcome to UNO! \n\n";
				cout << "1: Play Game \n\n";
				cout << "2: Instructions \n\n";
				cout << "3: Options \n\n";
				cout << "4: Exit Game \n\n";
				cout << "5: Resume Game \n\n";
				cout << "Enter Your Choice:_\b";
				cin >> menu_choice;

				while (menu_choice <= 0 || menu_choice >= 6)
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');

					cout << "Invalid Entry \n";
					Sleep(1000);
					Console::Clear();

					cout << "Welcome to UNO! \n\n";
					cout << "1: Play Game \n\n";
					cout << "2: Instructions \n\n";
					cout << "3: Options \n\n";
					cout << "4: Exit Game \n\n";
					cout << "5: Resume Game \n\n";
					cout << "Enter Your Choice: ";
					cin >> menu_choice;
					continue;
				}
			}

			if (menu_choice == 1)
			{

				Console::Clear();

				cout << "How many computers would you like to play (1-3) \n";
				cout << "Or type 4 to return to previous page \n";
				cout << "Enter: ";
				cin >> m_numPlayers;
				if (resume)
				{
					resume2 = true;
				}

				while (m_numPlayers <= 0 || m_numPlayers >= 5)
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');

					cout << "Invalid Entry \n";
					Sleep(1000);
					Console::Clear();

					cout << "How many computers would you like to play (1-3) \n";
					cout << "Or type 4 to return to previous page \n";
					cout << "Enter: ";
					cin >> m_numPlayers;
				}

				if (m_numPlayers == 4)
				{
					m_state = GAME_MENU;
					break;
				}
				else
				{
					if (resume2)
					{
						for (int i = 0; i < m_numPlayers + 1; i++)
						{
							m_players[i]->Clear();
						}
						m_Discard.Clear();
						m_Deck.Clear();

						for (int i = 0; i < 4; i++)
						{
							delete m_players[i];
						}

						m_players[0] = new Human;

						for (int i = 1; i < 4; i++)
						{
							m_players[i] = new Computer;
						}
					}
					Distribute_Cards(m_numPlayers);
					m_state = GAME_PLAY;
					break;
				}
			}


			else if (menu_choice == 2)
			{
				m_state = GAME_INSTRUCT;
				break;
			}

			else if (menu_choice == 3)
			{
				m_state = GAME_OPTIONS;
				break;
			}

			else if (menu_choice == 4)
			{
				m_state = GAME_END;
				break;
			}
			else if (menu_choice == 5)
			{
				resume = false;

				m_state = GAME_PLAY;
				break;
			}


			//*******************************************************************************************************************
			//*******************************************************************************************************************
			//*******************************************************************************************************************


			//GAME INSTRUCTIONS.

		case GAME_INSTRUCT:

			while (menu_choice != 4)
			{
				Console::Clear();

				cout << "GAME INSTRUCTIONS \n\n";

				cout << "OBJECTIVE: To be the first player to score 500 points. Points are scored by \n";
				cout << "ridding yourself of all the cards in your hand before your opponent(s).\n";
				cout << "You score points for cards left in your opponent's hands.\n";
				cout << "Each player is dealt 7 cards with the remaining ones placed face down to form a DRAW pile.\n";
				cout << "The top card of the DRAW pile is turned over to begin a DISCARD pile.\n";
				cout << "The first player has to match the card in the DISCARD pile either by number, \n";
				cout << "color or word.\n\n";
				cout << "For example, if the card is a red 7, player must throw down a \n";
				cout << "red card or any color 7. Or the player can throw down a Wild Card.\n";
				cout << "If the player doesn't have anything to match, he must pick a card from the DRAW pile.\n";
				cout << "If he can play what is drawn, it must be played.\n";
				cout << "Otherwise play moves to the next person.\n";
				cout << "Once a player has no cards left, the hand is over.\n";
				cout << "Points are scored and you start over again.\n\n";

				cout << "S = Skip, R = Reverse, D2 = Draw 2, W = Wild, W4 = Wild Draw 4 \n\n";
				cout << "B = Blue, R = Red, Y = Yellow, G = Green\n\n";

				cout << "Face value is displayed first, Color is displayed second... \n";
				cout << "For example: 3R is a 3 Red, and Skip R is a Skip Red\n";

				cout << "Press 4 to return to previous screen: ";
				cin >> menu_choice;

				if (menu_choice != 4)
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');

					cout << "Invalid Entry \n";
					Sleep(1000);
					continue;
				}
			}

			m_state = GAME_MENU;
			break;


			//*******************************************************************************************************************
			//*******************************************************************************************************************
			//*******************************************************************************************************************


			//GAME OPTIONS.

		case GAME_OPTIONS:

			do
			{
				Console::Clear();

				cout << "CHEATS \n\n";

				cout << "CHEAT 1: DISPLAY THE OPPONENTS CARDS. \n\n\n";
				cout << "CHEAT 2: MAKE OPPONENTS DRAW A CARD EVERY TURN. \n\n\n";
				cout << "CHEAT 3: MAKE IT POSSIBLE TO PLAY ANY CARD DURING YOUR TURN. \n\n\n";

				cout << "Select which cheat you wish to activate or \n";
				cout << "Press 4 to return to previous screen: ";
				cin >> menu_choice;

				while (menu_choice <= 0 || menu_choice >= 5)
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');

					cout << "Invalid Entry \n";
					Sleep(1000);
					cout << endl;

					cout << "Select which cheat you wish to activate or \n";
					cout << "Press 4 to return to previous screen: ";
					cin >> menu_choice;
				}

				if (!resume)
				{
					if (menu_choice == 1)
					{
						if (m_players[0]->GetCheat() & 1)
						{
							cout << "Deactivate cheat (y / n) \n";
							cout << "Enter: ";
							cin >> cheat_choice;

							while (cheat_choice != 'y' && cheat_choice != 'n')
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');

								cout << "Invalid Entry \n";
								Sleep(1000);
								cout << "Deactivate cheat (y / n) \n";
								cout << "Enter: ";
								cin >> cheat_choice;
							}
							if (tolower(cheat_choice == 'n'))
							{
								cout << "Cheat 1 is still active \n";
								Sleep(2000);
								continue;
							}

							else if (tolower(cheat_choice == 'y'))
							{
								unsigned char temp = m_players[0]->GetCheat();

								temp &= ~1;

								m_players[0]->SetCheat(temp);
								cout << "Cheat is deactivated\n";
								Sleep(3000);
							}
						}
						else
						{
							cout << "Activate cheat (y / n) \n";
							cout << "Enter: ";
							cin >> cheat_choice;

							while (cheat_choice != 'y' && cheat_choice != 'n')
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');

								cout << "Invalid Entry \n";
								Sleep(1000);
								cout << "Activate cheat (y / n) \n";
								cout << "Enter: ";
								cin >> cheat_choice;
							}
							if (tolower(cheat_choice == 'y'))
							{
								unsigned char temp = m_players[0]->GetCheat();

								temp |= 1;

								m_players[0]->SetCheat(temp);

								cout << "Cheat: 'DISPLAY THE OPPONENTS CARDS' has been activated\n";
								Sleep(3000);
							}

							else if (tolower(cheat_choice == 'n'))
							{
								unsigned char temp = m_players[0]->GetCheat();

								temp &= ~1;

								m_players[0]->SetCheat(temp);
								cout << "Cheat is deactivated\n";
								Sleep(3000);
							}
						}
					}

					else if (menu_choice == 2)
					{
						if (m_players[0]->GetCheat() & (1 << 1))
						{
							cout << "Deactivate cheat (y / n) \n";
							cout << "Enter: ";
							cin >> cheat_choice;

							while (cheat_choice != 'y' && cheat_choice != 'n')
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');

								cout << "Invalid Entry \n";
								Sleep(1000);
								cout << "Deactivate cheat (y / n) \n";
								cout << "Enter: ";
								cin >> cheat_choice;
							}
							if (tolower(cheat_choice == 'n'))
							{
								cout << "Cheat 2 is still active \n";
								Sleep(2000);
								continue;
							}
							else if (tolower(cheat_choice == 'y'))
							{
								unsigned char temp = m_players[0]->GetCheat();

								temp &= ~(1 << 1);

								m_players[0]->SetCheat(temp);
								cout << "Cheat is deactivated\n";
								Sleep(3000);
							}
						}
						else
						{

							cout << "Activate cheat (y / n) \n";
							cout << "Enter: ";
							cin >> cheat_choice;

							while (cheat_choice != 'y' && cheat_choice != 'n')
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');

								cout << "Invalid Entry \n";
								Sleep(1000);
								cout << "Activate cheat (y / n) \n";
								cout << "Enter: ";
								cin >> cheat_choice;
							}
							if (tolower(cheat_choice == 'y'))
							{
								unsigned char temp = m_players[0]->GetCheat();

								temp |= (1 << 1);

								m_players[0]->SetCheat(temp);

								cout << "Cheat: 'MAKE OPPONENTS DRAW A CARD EVERY TURN' has been activated\n";
								Sleep(3000);
							}
							else if (tolower(cheat_choice == 'n'))
							{
								unsigned char temp = m_players[0]->GetCheat();

								temp &= ~(1 << 1);

								m_players[0]->SetCheat(temp);
								cout << "Cheat is deactivated\n";
								Sleep(3000);
							}
						}
					}

					else if (menu_choice == 3)
					{
						if (m_players[0]->GetCheat() & (1 << 2))
						{
							cout << "Deactivate cheat (y / n) \n";
							cout << "Enter: ";
							cin >> cheat_choice;

							while (cheat_choice != 'y' && cheat_choice != 'n')
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');

								cout << "Invalid Entry \n";
								Sleep(1000);
								cout << "Deactivate cheat (y / n) \n";
								cout << "Enter: ";
								cin >> cheat_choice;
							}
							if (tolower(cheat_choice == 'n'))
							{
								cout << "Cheat 3 is still active \n";
								Sleep(2000);
								continue;
							}
							else if (tolower(cheat_choice == 'y'))
							{
								unsigned char temp = m_players[0]->GetCheat();

								temp &= ~(1 << 2);

								m_players[0]->SetCheat(temp);
								cout << "Cheat is deactivated\n";
								Sleep(3000);
							}
						}
						else
						{

							cout << "Activate cheat (y / n) \n";
							cout << "Enter: ";
							cin >> cheat_choice;

							while (cheat_choice != 'y' && cheat_choice != 'n')
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');

								cout << "Invalid Entry \n";
								Sleep(1000);
								cout << "Activate cheat (y / n) \n";
								cout << "Enter: ";
								cin >> cheat_choice;
							}
							if (tolower(cheat_choice == 'y'))
							{
								unsigned char temp = m_players[0]->GetCheat();

								temp |= (1 << 2);

								m_players[0]->SetCheat(temp);
								cout << "Cheat: 'MAKE IT POSSIBLE TO PLAY ANY CARD DURING YOUR TURN' has been activated\n";
								Sleep(3000);
							}
							else if (tolower(cheat_choice == 'n'))
							{
								unsigned char temp = m_players[0]->GetCheat();

								temp &= ~(1 << 2);

								m_players[0]->SetCheat(temp);
								cout << "Cheat is deactivated\n";
								Sleep(3000);
							}
						}
					}
				}

				if (resume)
				{
					if (menu_choice == 1)
					{
						if (m_players[0]->GetCheat() & 1)
						{
							cout << "Deactivate cheat (y / n) \n";
							cout << "Enter: ";
							cin >> cheat_choice;

							while (cheat_choice != 'y' && cheat_choice != 'n')
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');

								cout << "Invalid Entry \n";
								Sleep(1000);
								cout << "Deactivate cheat (y / n) \n";
								cout << "Enter: ";
								cin >> cheat_choice;
							}
							if (tolower(cheat_choice == 'n'))
							{
								cout << "Cheat 1 is still active \n";
								Sleep(2000);
								break;

							}

							else if (tolower(cheat_choice == 'y'))
							{
								unsigned char temp = m_players[0]->GetCheat();

								temp &= ~1;

								m_players[0]->SetCheat(temp);
								cout << "Cheat is deactivated\n";
								Sleep(3000);
							}
						}
						else
						{
							cout << "Activate cheat (y / n) \n";
							cout << "Enter: ";
							cin >> cheat_choice;

							while (cheat_choice != 'y' && cheat_choice != 'n')
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');

								cout << "Invalid Entry \n";
								Sleep(1000);
								cout << "Activate cheat (y / n) \n";
								cout << "Enter: ";
								cin >> cheat_choice;
							}
							if (tolower(cheat_choice == 'y'))
							{
								unsigned char temp = m_players[0]->GetCheat();

								temp |= 1;

								m_players[0]->SetCheat(temp);

								cout << "Cheat: 'DISPLAY THE OPPONENTS CARDS' has been activated\n";
								Sleep(3000);
							}

							else if (tolower(cheat_choice == 'n'))
							{
								unsigned char temp = m_players[0]->GetCheat();

								temp &= ~1;

								m_players[0]->SetCheat(temp);
								cout << "Cheat is deactivated\n";
								Sleep(3000);
							}
						}
					}
					else if (menu_choice == 2)
					{
						if (m_players[0]->GetCheat() & (1 << 1))
						{
							cout << "Deactivate cheat (y / n) \n";
							cout << "Enter: ";
							cin >> cheat_choice;

							while (cheat_choice != 'y' && cheat_choice != 'n')
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');

								cout << "Invalid Entry \n";
								Sleep(1000);
								cout << "Deactivate cheat (y / n) \n";
								cout << "Enter: ";
								cin >> cheat_choice;
							}
							if (tolower(cheat_choice == 'n'))
							{
								cout << "Cheat 2 is still active \n";
								Sleep(2000);
								break;

							}
							else if (tolower(cheat_choice == 'y'))
							{
								unsigned char temp = m_players[0]->GetCheat();

								temp &= ~(1 << 1);

								m_players[0]->SetCheat(temp);
								cout << "Cheat is deactivated\n";
								Sleep(3000);
							}
						}
						else
						{
							cout << "Activate cheat (y / n) \n";
							cout << "Enter: ";
							cin >> cheat_choice;

							while (cheat_choice != 'y' && cheat_choice != 'n')
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');

								cout << "Invalid Entry \n";
								Sleep(1000);
								cout << "Activate cheat (y / n) \n";
								cout << "Enter: ";
								cin >> cheat_choice;
							}
							if (tolower(cheat_choice == 'y'))
							{
								unsigned char temp = m_players[0]->GetCheat();

								temp |= (1 << 1);

								m_players[0]->SetCheat(temp);

								cout << "Cheat: 'MAKE OPPONENTS DRAW A CARD EVERY TURN' has been activated\n";
								Sleep(3000);
							}
							else if (tolower(cheat_choice == 'n'))
							{
								unsigned char temp = m_players[0]->GetCheat();

								temp &= ~(1 << 1);

								m_players[0]->SetCheat(temp);
								cout << "Cheat is deactivated\n";
								Sleep(3000);
							}
						}
					}
					else if (menu_choice == 3)
					{
						if (m_players[0]->GetCheat() & (1 << 2))
						{
							cout << "Deactivate cheat (y / n) \n";
							cout << "Enter: ";
							cin >> cheat_choice;

							while (cheat_choice != 'y' && cheat_choice != 'n')
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');

								cout << "Invalid Entry \n";
								Sleep(1000);
								cout << "Deactivate cheat (y / n) \n";
								cout << "Enter: ";
								cin >> cheat_choice;
							}
							if (tolower(cheat_choice == 'n'))
							{
								cout << "Cheat 3 is still active \n";
								Sleep(2000);
								break;
							}
							else if (tolower(cheat_choice == 'y'))
							{
								unsigned char temp = m_players[0]->GetCheat();

								temp &= ~(1 << 2);

								m_players[0]->SetCheat(temp);
								cout << "Cheat is deactivated\n";
								Sleep(3000);
							}

						}
						else
						{
							cout << "Activate cheat (y / n) \n";
							cout << "Enter: ";
							cin >> cheat_choice;

							while (cheat_choice != 'y' && cheat_choice != 'n')
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');

								cout << "Invalid Entry \n";
								Sleep(1000);
								cout << "Activate cheat (y / n) \n";
								cout << "Enter: ";
								cin >> cheat_choice;
							}
							if (tolower(cheat_choice == 'y'))
							{
								unsigned char temp = m_players[0]->GetCheat();

								temp |= (1 << 2);

								m_players[0]->SetCheat(temp);
								cout << "Cheat: 'MAKE IT POSSIBLE TO PLAY ANY CARD DURING YOUR TURN' has been activated\n";
								Sleep(3000);
							}
							else if (tolower(cheat_choice == 'n'))
							{
								unsigned char temp = m_players[0]->GetCheat();

								temp &= ~(1 << 2);

								m_players[0]->SetCheat(temp);
								cout << "Cheat is deactivated\n";
								Sleep(3000);
							}
						}
					}
				}
			} while (menu_choice != 4);
			m_state = GAME_MENU;
			break;


			//*******************************************************************************************************************
			//*******************************************************************************************************************
			//*******************************************************************************************************************


			// GAME PLAY1.

		case GAME_PLAY:

			// Resets the current player
			m_currPlayer = 0;

			Console::Clear();
			//Load();

			do
			{
				// Reset Bool.
				cin.clear();
				Needs_Draw = true;
				Cannot_Draw = false;
				Turn_end = true;
				skip = false;

				Score_Track(m_numPlayers);
				first_turn = false;

				Score_Track(m_numPlayers);

				if (m_currPlayer == 0)
				{
					Game_Prompt();
				}
				if (resume)
				{
					m_state = GAME_MENU;
					break;
				}
				if (m_currPlayer != 0)
				{
					if (m_players[0]->GetCheat() & (1 << 1))
					{
						for (int i = 0; i < 1; i++)
						{
							m_Deck.Draw(C_obj);
							m_players[m_currPlayer]->AddCard(C_obj);
						}
					}
					Score_Track(m_numPlayers);
				}
				Turn(m_currPlayer, player_face_choice, player_color_choice);

			} while (m_state != GAME_SCORE);

			break;


			//*******************************************************************************************************************
			//*******************************************************************************************************************
			//*******************************************************************************************************************


			// GAME SCORE.

		case GAME_SCORE:
			Score_Track(m_numPlayers);


			if (m_players[0]->GetScore() >= 500)
			{
				cout << "Player is the winner! \n";
			}
			else if (m_numPlayers == 1 && m_players[1]->GetScore() >= 500)
			{
				cout << "Computer 1 is the winner! \n";
			}
			else if (m_numPlayers == 2 && m_players[2]->GetScore() >= 500)
			{
				cout << "Computer 2 is the winner! \n";
			}
			else if (m_numPlayers == 3 && m_players[3]->GetScore() >= 500)
			{
				cout << "Computer 3 is the winner! \n";
			}
			Sleep(3000);

			cout << "Would you like to play again: ";
			cout << "Enter 1 to play again, otherwise enter 0 to quit \n";
			cout << "Enter: ";
			cin >> choice;

			while (choice <= -1 || choice >= 2)
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');

				cout << "Invalid Entry \n";
				Sleep(2000);

				Console::Clear();

				cout << "Would you like to play again: ";
				cout << "Enter 1 to play again, otherwise enter 0 to quit \n";
				cout << "Enter: ";
				cin >> choice;
			}

			if (choice == 1)
			{
				for (int i = 0; i < m_numPlayers + 1; i++)
				{
					m_players[i]->Clear();
				}
				m_Discard.Clear();
				m_Deck.Clear();

				for (int i = 0; i < 4; i++)
				{
					delete m_players[i];
				}

				m_players[0] = new Human;

				for (int i = 1; i < 4; i++)
				{
					m_players[i] = new Computer;
				}
				Distribute_Cards(m_numPlayers);
				m_state = GAME_PLAY;
				break;
			}

			else if (choice == 0)
			{
				m_state = GAME_END;
				cout << endl << endl;
				cout << "Thank you for playing! \n";
				break;
			}



			//*******************************************************************************************************************
			//*******************************************************************************************************************
			//*******************************************************************************************************************


			// GAME END.

		case GAME_END:

			// The game is over, changes the bool to stop the loop.
			bRun = false;
			break;
		}
	}
}



// Helper Functions
void Game::Distribute_Cards(int players)
{
	m_Deck.Shuffle();

	for (int i = 0; i < players + 1; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			m_Deck.Draw(C_obj);
			m_players[i]->AddCard(C_obj);
		}
	}

	m_Deck.Draw(C_obj);
	m_Discard.Push(C_obj);

}

void Game::Load()
{
	int load_time = 0;

	cout << "Remember!! \n\n";
	cout << "Face value is displayed first, Color is displayed second...\n";
	cout << "For example : 3R is a 3 Red, and Skip R is a Skip Red";

	for (int i = 0; i < 101; i++)
	{
		Console::SetCursorPosition(0, 10);
		cout << "Game is loading \n";
		cout << "Please wait..." << load_time++ << "%";
		Sleep(100);
	}
	Console::Clear();
}

void Game::Game_Prompt()
{
	do
	{
		cout << "( 0 - 9 ) (10=Draw 2, 11=Reverse, 12=Skip, 13=Wild, 14=Wild Draw 4) \n";
		cout << "Enter a card by value or Type '15' to draw a new card or 16 to \n";
		cout << "return to the main menu \n";
		cout << "Enter: ";
		cin >> player_face_choice;
		go = false;


		while (player_face_choice < -1 || player_face_choice >= 17)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');

			cout << "Invalid Entry";
			Sleep(1000);

			Score_Track(m_numPlayers);

			cout << "( 0 - 9 ) (10=Draw 2, 11=Reverse, 12=Skip, 13=Wild, 154=Wild Draw 4) \n";
			cout << "Enter a card by value or Type '15' to draw a new card or 16 to \n";
			cout << "return to the main menu \n";
			cout << "Enter: ";
			cin >> player_face_choice;
		}

		if (player_face_choice == 15)
		{
			if (Cannot_Draw == false)
			{
				m_Deck.Draw(C_obj);
				m_players[0]->AddCard(C_obj);
				Cannot_Draw = true;
				go = true;
				Console::Clear();
				Score_Track(m_numPlayers);
				continue;
			}
			else if (Cannot_Draw == true)
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Sorry, you cannot draw again and must skip this turn \n\n";
				Sleep(3000);

				if (m_reversed)
				{
					m_currPlayer--;

					if (m_numPlayers == 1 && m_currPlayer <= -1)
					{
						m_currPlayer = 1;
					}
					else if (m_numPlayers == 2 && m_currPlayer <= -1)
					{
						m_currPlayer = 2;
					}
					else if (m_numPlayers == 3 && m_currPlayer <= -1)
					{
						m_currPlayer = 3;
					}
				}
				else if (m_reversed == false)
				{
					m_currPlayer++;

					if (m_numPlayers == 1 && m_currPlayer >= 2)
					{
						m_currPlayer = 0;
					}
					else if (m_numPlayers == 2 && m_currPlayer >= 3)
					{
						m_currPlayer = 0;
					}
					else if (m_numPlayers == 3 && m_currPlayer >= 4)
					{
						m_currPlayer = 0;
					}
				}
				go = false;
				break;
			}
		}

		else if (player_face_choice == 16)
		{
			m_state = GAME_MENU;
			resume = true;
			break;
		}

		cout << "(";
		Console::ForegroundColor(Blue);
		cout << "'b'=blue, ";
		Console::ForegroundColor(Red);
		cout << "'r' = red, ";
		Console::ForegroundColor(Green);
		cout << "'g' = green, ";
		Console::ForegroundColor(Yellow);
		cout << "'y' = yellow";
		Console::ResetColor();
		cout << ") \n";
		cout << "Enter your card color or type 'm' to return to main menu or 'c' to choose a new card value.\n";
		cout << "Enter: ";
		cin >> player_color_choice;
		go = false;

		while (tolower(player_color_choice) != 'b' && tolower(player_color_choice) != 'r' && tolower(player_color_choice) != 'g' && tolower(player_color_choice) != 'y' \
			&& tolower(player_color_choice) != 'n' && tolower(player_color_choice) != 'm' && tolower(player_color_choice) != 'c')
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');

			cout << "Invalid Entry";
			Sleep(1000);

			Score_Track(m_numPlayers);

			cout << "(";
			Console::ForegroundColor(Blue);
			cout << "'b'=blue, ";
			Console::ForegroundColor(Red);
			cout << "'r' = red, ";
			Console::ForegroundColor(Green);
			cout << "'g' = green, ";
			Console::ForegroundColor(Yellow);
			cout << "'y' = yellow";
			Console::ResetColor();
			cout << ") \n";
			cout << "Enter your card color or type 'm' to return to main menu or 'c' to choose a new card value.\n";
			cout << "Enter: ";
			cin >> player_color_choice;
		}

		if (tolower(player_color_choice == 'm'))
		{
			m_state = GAME_MENU;
			resume = true;
			resume2 = true;
			break;
		}
		else if (tolower(player_color_choice == 'c'))
		{
			Console::Clear();
			Score_Track(m_numPlayers);
			Game_Prompt();
		}

	} while (go);
}

void Game::Turn(int CurrPlayer, int player_face_choice, char player_color_choice)
{
	do
	{
		for (int i = 0; i < m_players[CurrPlayer]->GetNumCards(); i++)
		{
			m_players[CurrPlayer]->GetCard(i, C_obj);

			if (CurrPlayer == 0)
			{
				if (C_obj.GetFace() == player_face_choice && tolower(C_obj.GetSuit()) == tolower(player_color_choice))
				{
					if (m_players[0]->GetCheat() & (1 << 2))
					{
						m_Discard.Push(C_obj);
						m_players[CurrPlayer]->Discard(i, C_obj);

						cout << "You played a " << C_obj << endl;
						Sleep(3000);

						Score_Track(m_numPlayers);
					}
					else
					{
						if (C_obj.GetFace() == m_Discard.Peek()->GetFace() || C_obj.GetSuit() == m_Discard.Peek()->GetSuit() || C_obj.GetFace() == 13 || C_obj.GetFace() == 14)
						{
							m_Discard.Push(C_obj);
							m_players[CurrPlayer]->Discard(i, C_obj);

							cout << "You played a " << C_obj << endl;
							Sleep(3000);

							Score_Track(m_numPlayers);
						}
					}

					if (m_players[CurrPlayer]->GetNumCards() == 0)
					{
						for (int i = 0; i < m_numPlayers + 1; i++)
						{
							for (int j = 0; j < m_players[i]->GetNumCards(); j++)
							{
								m_players[i]->GetCard(j, C_obj);
								if (C_obj.GetFace() == 10)
								{
									score = score + 20;
								}
								else if (C_obj.GetFace() == 11)
								{
									score = score + 20;
								}
								else if (C_obj.GetFace() == 12)
								{
									score = score + 20;
								}
								else if (C_obj.GetFace() == 13)
								{
									score = score + 50;
								}
								else if (C_obj.GetFace() == 14)
								{
									score = score + 50;
								}
								else
									score = C_obj.GetFace() + score;
							}
						}

						m_players[CurrPlayer]->AddToScore(score);
						if (m_players[CurrPlayer]->GetScore() >= 500)
						{
							m_state = GAME_SCORE;
							Needs_Draw = false;
							break;
						}
						else
						{
							for (int i = 0; i < m_numPlayers + 1; i++)
							{
								m_players[i]->Clear();
							}
							m_Discard.Clear();
							m_Deck.Clear();
							Distribute_Cards(m_numPlayers);
							Console::Clear();
							cout << "One of the players managed to empty their hand \n";
							cout << "Since the score of 500 was not reached, the game continues \n";
							Sleep(3000);
							Needs_Draw = false;
							break;
						}
					}
					else
					{
						Needs_Draw = false;
						break;
					}
				}
			}

			else
			{
				if (C_obj.GetFace() == m_Discard.Peek()->GetFace() || C_obj.GetSuit() == m_Discard.Peek()->GetSuit() || C_obj.GetFace() == 13 || C_obj.GetFace() == 14)
				{
					m_Discard.Push(C_obj);
					m_players[CurrPlayer]->Discard(i, C_obj);

					cout << "Computer " << CurrPlayer << " Played a " << C_obj;
					Sleep(3000);
					Score_Track(m_numPlayers);


					if (m_players[CurrPlayer]->GetNumCards() == 0)
					{
						for (int i = 0; i < m_numPlayers + 1; i++)
						{
							for (int j = 0; j < m_players[i]->GetNumCards(); j++)
							{
								m_players[i]->GetCard(j, C_obj);
								if (C_obj.GetFace() == 10)
								{
									score = score + 20;
								}
								else if (C_obj.GetFace() == 11)
								{
									score = score + 20;
								}
								else if (C_obj.GetFace() == 12)
								{
									score = score + 20;
								}
								else if (C_obj.GetFace() == 13)
								{
									score = score + 50;
								}
								else if (C_obj.GetFace() == 14)
								{
									score = score + 50;
								}
								else
									score = C_obj.GetFace() + score;
							}
						}

						m_players[CurrPlayer]->AddToScore(score);
						if (score == 500)
						{
							m_state = GAME_SCORE;
							Needs_Draw = false;
							break;
						}
						else
						{
							for (int i = 0; i < m_numPlayers + 1; i++)
							{
								m_players[i]->Clear();
							}

							Distribute_Cards(m_numPlayers);
							Console::Clear();
							cout << "One of the players managed to empty their hand \n";
							cout << "Since the score of 500 was not reached, the game continues \n";
							Sleep(3000);
							Needs_Draw = false;
							break;
						}
					}
					else
					{
						Needs_Draw = false;
						break;
					}
				}
			}

		}// End of For loop


		if (Needs_Draw)
		{
			m_Deck.Draw(C_obj);
			m_players[CurrPlayer]->AddCard(C_obj);
			Needs_Draw = false;
			Score_Track(m_numPlayers);

			cout << "Computer: " << CurrPlayer << " had to draw a new card \n";
			Sleep(3000);

			continue;
		}
		else if (Needs_Draw == false)
		{
			if (m_state != GAME_SCORE)
			{
				Check_Peek();
				Is_Reversed();
				Is_Skip();
			}
		}
		Turn_end = false;

	} while (Turn_end);
}

void Game::Is_Reversed()
{
	if (m_reversed)
	{
		if (wild)
		{
			----m_currPlayer;
			wild = false;
		}
		else
		{
			m_currPlayer--;
			wild = false;
		}
		if (m_numPlayers == 1 && m_currPlayer <= -1)
		{
			m_currPlayer = 1;
		}
		else if (m_numPlayers == 2 && m_currPlayer <= -1)
		{
			m_currPlayer = 2;
		}
		else if (m_numPlayers == 3 && m_currPlayer <= -1)
		{
			m_currPlayer = 3;
		}
	}
	else if (m_reversed == false)
	{
		if (wild)
		{
			++++m_currPlayer;
			wild = false;
		}
		else
		{
			m_currPlayer++;
			wild = false;
		}
		if (m_numPlayers == 1 && m_currPlayer >= 2)
		{
			if (m_numPlayers == 1 && m_currPlayer == 3)
			{
				m_currPlayer = 1;
			}
			else
				m_currPlayer = 0;
		}
		else if (m_numPlayers == 2 && m_currPlayer >= 3)
		{
			m_currPlayer = 0;
		}
		else if (m_numPlayers == 3 && m_currPlayer == 5)
		{
			m_currPlayer = 1;
		}
		else if (m_numPlayers == 3 && m_currPlayer >= 4)
		{
			m_currPlayer = 0;
		}
	}
}

void Game::Is_Skip()
{
	if (skip)
	{
		if (!m_reversed)
		{
			m_currPlayer++;
		}
		if (m_numPlayers == 1 && m_currPlayer == 2)
		{
			m_currPlayer = 0;
		}
		else if (m_numPlayers == 2 && m_currPlayer == 3)
		{
			m_currPlayer = 0;
		}
		else if (m_numPlayers == 3 && m_currPlayer == 4)
		{
			m_currPlayer = 0;
		}
		if (m_reversed)
		{
			m_currPlayer--;
		}
		if (m_numPlayers == 1 && m_currPlayer == -2)
		{
			m_currPlayer = 0;
		}
		else if (m_numPlayers == 2 && m_currPlayer == -3)
		{
			m_currPlayer = 2;
		}
		else if (m_numPlayers == 3 && m_currPlayer == -4)
		{
			m_currPlayer = 3;
		}
	}
}

void Game::Check_Peek()
{
	if (m_Discard.Peek()->GetFace() == 10)
	{
		if (m_reversed)
		{
			m_currPlayer--;

			if (m_numPlayers == 1 && m_currPlayer <= -1)
			{
				m_currPlayer = 1;
			}
			else if (m_numPlayers == 2 && m_currPlayer <= -1)
			{
				m_currPlayer = 2;
			}
			else if (m_numPlayers == 3 && m_currPlayer <= -1)
			{
				m_currPlayer = 3;
			}
		}
		else if (m_reversed == false)
		{
			m_currPlayer++;

			if (m_numPlayers == 1 && m_currPlayer >= 2)
			{
				m_currPlayer = 0;
			}
			else if (m_numPlayers == 2 && m_currPlayer >= 3)
			{
				m_currPlayer = 0;
			}
			else if (m_numPlayers == 3 && m_currPlayer >= 4)
			{
				m_currPlayer = 0;
			}
		}

		for (int i = 0; i < 2; i++)
		{
			m_Deck.Draw(C_obj);
			m_players[m_currPlayer]->AddCard(C_obj);
		}

		if (m_reversed == false)
		{
			m_currPlayer--;

			if (m_numPlayers == 1 && m_currPlayer <= -1)
			{
				m_currPlayer = 1;
			}
			else if (m_numPlayers == 2 && m_currPlayer <= -1)
			{
				m_currPlayer = 2;
			}
			else if (m_numPlayers == 3 && m_currPlayer <= -1)
			{
				m_currPlayer = 3;
			}
		}
		else if (m_reversed == true)
		{
			m_currPlayer++;

			if (m_numPlayers == 1 && m_currPlayer >= 2)
			{
				m_currPlayer = 0;
			}
			else if (m_numPlayers == 2 && m_currPlayer >= 3)
			{
				m_currPlayer = 0;
			}
			else if (m_numPlayers == 3 && m_currPlayer >= 4)
			{
				m_currPlayer = 0;
			}
		}
	}

	else if (m_Discard.Peek()->GetFace() == 11)
	{
		if (m_numPlayers == 1)
		{
			m_reversed = false;
		}
		else if (m_numPlayers != 1)
		{
			m_reversed = true;
			count++;

			if (count % 2 == 0)
			{
				m_reversed = false;
			}
		}

	}

	else if (m_Discard.Peek()->GetFace() == 12)
	{
		skip = true;
	}

	else if (m_Discard.Peek()->GetFace() == 13)
	{
		if (m_currPlayer == 0)
		{
			cout << "Please select a color of a card you want to lay down \n";
			cout << "(";
			Console::ForegroundColor(Blue);
			cout << "'b'=blue, ";
			Console::ForegroundColor(Red);
			cout << "'r' = red, ";
			Console::ForegroundColor(Green);
			cout << "'g' = green, ";
			Console::ForegroundColor(Yellow);
			cout << "'y' = yellow";
			Console::ResetColor();
			cout << ") \n";
			cout << "Enter your card color. \n";
			cout << "Enter: ";
			cin >> player_color_choice;

			while (player_color_choice != 'b' && player_color_choice != 'r' && player_color_choice != 'g' && player_color_choice != 'y' && player_color_choice != 'n')
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');

				cout << "Invalid Entry";
				Sleep(1000);

				Score_Track(m_numPlayers);

				cout << "(";
				Console::ForegroundColor(Blue);
				cout << "'b'=blue, ";
				Console::ForegroundColor(Red);
				cout << "'r' = red, ";
				Console::ForegroundColor(Green);
				cout << "'g' = green, ";
				Console::ForegroundColor(Yellow);
				cout << "'y' = yellow";
				Console::ResetColor();
				cout << ") \n";
				cout << "Enter your card color.\n";
				cout << "Enter: ";
				cin >> player_color_choice;
			}
		}
		for (int i = 0; i < m_players[m_currPlayer]->GetNumCards(); i++)
		{
			m_players[m_currPlayer]->GetCard(i, C_obj);

			if (m_currPlayer == 0)
			{
				if (tolower(C_obj.GetSuit()) == tolower(player_color_choice))
				{
					m_Discard.Push(C_obj);
					m_players[m_currPlayer]->Discard(i, C_obj);
					break;
				}
			}
			else
			{
				m_Discard.Push(C_obj);
				m_players[m_currPlayer]->Discard(i, C_obj);
				break;
			}
		}
	}

	else if (m_Discard.Peek()->GetFace() == 14)
	{
		if (m_currPlayer == 0)
		{
			cout << "(";
			Console::ForegroundColor(Blue);
			cout << "'b'=blue, ";
			Console::ForegroundColor(Red);
			cout << "'r' = red, ";
			Console::ForegroundColor(Green);
			cout << "'g' = green, ";
			Console::ForegroundColor(Yellow);
			cout << "'y' = yellow";
			Console::ResetColor();
			cout << ") \n";
			cout << "Enter your card color.\n";
			cout << "Enter: ";
			cin >> player_color_choice;

			while (player_color_choice != 'b' && player_color_choice != 'r' && player_color_choice != 'g' && player_color_choice != 'y' && player_color_choice != 'n')
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');

				cout << "Invalid Entry";
				Sleep(1000);

				Score_Track(m_numPlayers);

				cout << "(";
				Console::ForegroundColor(Blue);
				cout << "'b'=blue, ";
				Console::ForegroundColor(Red);
				cout << "'r' = red, ";
				Console::ForegroundColor(Green);
				cout << "'g' = green, ";
				Console::ForegroundColor(Yellow);
				cout << "'y' = yellow";
				Console::ResetColor();
				cout << ") \n";
				cout << "Enter your card color.\n";
				cout << "Enter: ";
				cin >> player_color_choice;
			}
			for (int i = 0; i < m_players[m_currPlayer]->GetNumCards(); i++)
			{
				m_players[m_currPlayer]->GetCard(i, C_obj);


				if (tolower(C_obj.GetSuit()) == tolower(player_color_choice))
				{
					m_Discard.Push(C_obj);
					m_players[m_currPlayer]->Discard(i, C_obj);

					if (m_reversed)
					{
						m_currPlayer--;

						if (m_numPlayers == 1 && m_currPlayer <= -1)
						{
							m_currPlayer = 1;
						}
						else if (m_numPlayers == 2 && m_currPlayer <= -1)
						{
							m_currPlayer = 2;
						}
						else if (m_numPlayers == 3 && m_currPlayer <= -1)
						{
							m_currPlayer = 3;
						}
					}
					if (m_reversed == false)
					{
						m_currPlayer++;

						if (m_numPlayers == 1 && m_currPlayer >= 2)
						{
							m_currPlayer = 0;
						}
						else if (m_numPlayers == 2 && m_currPlayer >= 3)
						{
							m_currPlayer = 0;
						}
						else if (m_numPlayers == 3 && m_currPlayer >= 4)
						{
							m_currPlayer = 0;
						}
					}

					for (int i = 0; i < 4; i++)
					{
						m_Deck.Draw(C_obj);
						m_players[m_currPlayer]->AddCard(C_obj);
					}

					wild = true;
					if (m_reversed)
					{
						m_currPlayer++;

						if (m_numPlayers == 1 && m_currPlayer >= 2)
						{
							m_currPlayer = 1;
						}
						else if (m_numPlayers == 2 && m_currPlayer >= 3)
						{
							m_currPlayer = 1;
						}
						else if (m_currPlayer >= 4)
						{
							m_currPlayer = 0;
						}
					}
					if (m_reversed == false)
					{
						m_currPlayer--;

						if (m_numPlayers == 1 && m_currPlayer <= -1)
						{
							m_currPlayer = 0;
						}
						else if (m_numPlayers == 3 && m_currPlayer >= 4)
						{
							m_currPlayer = 0;
						}
					}
					break;
				}
			}
		}
		else
		{
			for (int i = 0; i < m_players[m_currPlayer]->GetNumCards(); i++)
			{
				m_players[m_currPlayer]->GetCard(i, C_obj);

				m_Discard.Push(C_obj);
				m_players[m_currPlayer]->Discard(i, C_obj);

				if (m_reversed)
				{
					m_currPlayer--;

					if (m_numPlayers == 1 && m_currPlayer <= -1)
					{
						m_currPlayer = 1;
					}
					else if (m_numPlayers == 2 && m_currPlayer <= -1)
					{
						m_currPlayer = 2;
					}
					else if (m_numPlayers == 3 && m_currPlayer <= -1)
					{
						m_currPlayer = 3;
					}
				}
				if (m_reversed == false)
				{
					m_currPlayer++;

					if (m_numPlayers == 1 && m_currPlayer >= 2)
					{
						m_currPlayer = 0;
					}
					else if (m_numPlayers == 2 && m_currPlayer >= 3)
					{
						m_currPlayer = 0;
					}
					else if (m_numPlayers == 3 && m_currPlayer >= 4)
					{
						m_currPlayer = 0;
					}
				}

				for (int i = 0; i < 4; i++)
				{
					m_Deck.Draw(C_obj);
					m_players[m_currPlayer]->AddCard(C_obj);
				}

				wild = true;
				if (m_reversed)
				{
					m_currPlayer++;

					if (m_numPlayers == 1 && m_currPlayer >= 2)
					{
						m_currPlayer = 0;
					}
					else if (m_numPlayers == 2 && m_currPlayer >= 3)
					{
						m_currPlayer = 1;
					}
					else if (m_currPlayer >= 4)
					{
						m_currPlayer = 0;
					}
				}
				if (m_reversed == false)
				{
					m_currPlayer--;

					if (m_numPlayers == 1 && m_currPlayer <= -1)
					{
						m_currPlayer = 1;
					}
					else if (m_numPlayers == 3 && m_currPlayer >= 4)
					{
						m_currPlayer = 0;
					}

				}
				break;
			}
		}
	}
}

void Game::Score_Track(int Total_Players)
{
	if (Total_Players == 1)
	{
		Console::Clear();
		m_players[0]->Show();
		cout << "\nScore: " << m_players[0]->GetScore() << endl << endl;
		m_players[1]->Show();
		cout << "\nScore: " << m_players[1]->GetScore() << endl << endl;

		if (first_turn)
		{
			while (m_Discard.Peek()->GetFace() >= 10)
			{
				m_Deck.Draw(C_obj);
				m_Discard.Push(C_obj);
			}

			cout << "The card on the Discard pile is " << *(m_Discard.Peek()) << endl << endl;
		}
		else
			cout << "The card on the Discard pile is " << *(m_Discard.Peek()) << endl << endl;


	}

	else if (Total_Players == 2)
	{
		Console::Clear();
		m_players[0]->Show();
		cout << "\nScore: " << m_players[0]->GetScore() << endl << endl;
		m_players[1]->Show();
		cout << "\nScore: " << m_players[1]->GetScore() << endl << endl;
		m_players[2]->Show();
		cout << "\nScore: " << m_players[2]->GetScore() << endl << endl;


		if (first_turn)
		{
			while (m_Discard.Peek()->GetFace() >= 10)
			{
				m_Deck.Draw(C_obj);
				m_Discard.Push(C_obj);
			}

			cout << "The card on the Discard pile is " << *(m_Discard.Peek()) << endl << endl;
		}
		else
			cout << "The card on the Discard pile is " << *(m_Discard.Peek()) << endl << endl;

	}

	else if (Total_Players == 3)
	{
		Console::Clear();
		m_players[0]->Show();
		cout << "\nScore: " << m_players[0]->GetScore() << endl << endl;
		m_players[1]->Show();
		cout << "\nScore: " << m_players[1]->GetScore() << endl << endl;
		m_players[2]->Show();
		cout << "\nScore: " << m_players[2]->GetScore() << endl << endl;
		m_players[3]->Show();
		cout << "\nScore: " << m_players[3]->GetScore() << endl << endl;


		if (first_turn)
		{
			while (m_Discard.Peek()->GetFace() >= 10)
			{
				m_Deck.Draw(C_obj);
				m_Discard.Push(C_obj);
			}

			cout << "The card on the Discard pile is " << *(m_Discard.Peek()) << endl << endl;
		}
		else
			cout << "The card on the Discard pile is " << *(m_Discard.Peek()) << endl << endl;

	}
}