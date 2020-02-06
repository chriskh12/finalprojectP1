#include <iostream>
#include <fstream>
#include <string>

char board[3][3] = { { '1','2','3' }, { '4','5','6' }, { '7','8','9' } }; //3x3 table
char turn = 'X';
int row, column;
bool draw = false;

using namespace std;

ifstream inFile;
ofstream outFile;

class account
{
	string username1, username2, password1, password2;
	int arrR[24];
	float balance;
	int a, b, c, d, nb, e, k, nn;//c for number of digits e for code readed from file d for code entered   nb for number of code in the file
	float g;
public: //using public to be able to access the functions from the main function.
	void play_game(); //play tic tac toe game
	void main_menu(); //function to login to your account
	void display_board(); // funtion to display the board for the game
	void player_turn();// to check if its p1 turn or p2
	bool game_over(); // to check draw/wins
};

/*void account::create_account() {
	system("cls");
	cout << "\tRegister a new account !";
	cout << "\n\tCreate a username: " ;
	cin >> username1;
	cout << "\n\tCreate a password ";
	cin >> password1;
	do {
		cout << "\n\tEnter the amount you want to deposit :";
		cin >> balance;
	} while (balance < 0);
}*/

void account::main_menu() {
	//register
	int aa, bb, cc, dd;
	cc = 0;
	int total, total1, total2;
	total = 0;
	total1 = 0;
	total2 = 0;
	cout << "\tRegister a new account !";
	cout << "\n\tCreate a username: ";
	cin >> username1;
	cout << "\n\tCreate a password ";
	cin >> password1;
	do {
		cout << "\n\tEnter the amount you want to deposit :";
		cin >> balance;
	} while (balance < 0);
	//login
	system("cls");
	cout << "\tLogin to your account !";
	int i = 0;
	do
	{
		for (i = 0; i < 52; i++)
		{
			cout << "\n\tEnter your username: ";
			cin >> username2;
			if (username2 == username1)
			{
				cout << "\tCorrect username " << endl;
				int ii = 0;
				do
				{
					cout << "\tPlease enter your password ";
					cin >> password2;
					for (ii = 0; ii < 52; ii++)
					{
						if (password2 == password1)
						{

							cout << "\tCorrect password " << endl;
							cout << "\tYour current balance is: " << balance << "$" << endl;
							g = balance;

							do
							{
								cout << "\n\tPlease choose an option " << endl << "\t1. deposit" << endl << "\t2. withdraw" << endl;
								cout << "\tPick a number: ";
								cin >> b;
								while (b != 1 && b != 2)
								{
									cout << "\tPlease choose carefully the option " << endl;
									cout << "\t1. deposit" << endl;
									cout << "\t2. withdraw" << endl;
									cout << "\tPick a number: ";
									cin >> b;
								}
								if (b == 1)
								{
									cout << "\n\tPlease enter number of digits of the code for the check banker : ";
									cout << endl;
									cin >> c;
									while (c != 7 && c != 8 && c != 9)
									{
										cout << "\tIncorrect number of digits !" << endl;
										cout << "\tPlease re-enter number of digits: ";
										cin >> c;
									}
									cout << endl;
									int iii = 0;
									do
									{
										cout << "\n\tPlease enter the code : ";
										cin >> d;
										cout << endl;
										cout << endl;
										nb = 25;

										int aa;
										ifstream reader("checkbanker.txt");
										//ofstream writer("checkbanker.txt");
										for (aa = 0; aa < nb; aa++)
										{
											reader >> e;
											arrR[aa] = e;
										}

										for (iii = 0; iii < nb + 2; iii++)
										{

											if (arrR[iii] == d)
											{
												k = iii;

												if (c == 7)
												{
													cout << "10$ will be added to your balance " << endl;
													nb = nb - 1;
													g += 10;
												}
												if (c == 8)
												{
													cout << "20$ will be added to your balance " << endl;
													nb = nb - 1;
													g += 20;
												}
												if (c == 9)
												{
													cout << "30$ will be added to your balance " << endl;
													nb = nb - 1;
													g += 30;
												}
												balance = g;
												arrR[k] = 0;


												ofstream writer("checkbanker.txt");
												for (int m = 0; m < 23; m++)
												{
													writer << arrR[m] << endl;
												}
												writer.close();

												break;
											}
											if (iii == nb + 1)
											{
												cout << "\tIncorrect code!" << endl;
												break;
											}
										}
									} while (iii == nb + 1);
									cout << "\n\tYour balance is " << g << "$" << endl;

									outFile.close();
								}
								else {
									cout << "\tWithdraw" << endl;
									cout << "Your balance is " << balance << "$" << endl;
									do
									{
										bb = 0;
										system("cls");
										cout << "1-Purchase" << endl;
										cout << "2-Total" << endl;
										cin >> aa;
										while (aa != 1 && aa != 2)
										{
											system("cls");
											cout << "Please enter the correct number  " << endl;
											cout << "1-Purchase" << endl;
											cout << "2-Total" << endl;
											cin >> aa;
										}
										system("cls");

										do
										{
											bb = 0;
											cc = 0;
											system("cls");
											if (aa == 1)
											{

												cout << "1-Sandwiches/Snacks" << endl;
												cout << "2-Games" << endl;
												cout << "3-Return" << endl;
												cin >> bb;
												while (bb != 1 && bb != 2 && bb != 3)
												{
													cout << "Please choose the correct number " << endl;
													cout << "1-Sandwiches/Snacks" << endl;
													cout << "2-Games" << endl;
													cout << "3-Return" << endl;
													cin >> bb;
												}


												if (bb == 1)
												{
													do
													{

														system("cls");
														cout << "sandwiches" << endl;
														cout << "1- chicken & cheese (4$)" << endl;
														cout << "2-sausage egg and cheese (5$)" << endl;
														cout << "3- tuna & salad (3$)" << endl;
														cout << "4- ham & egg (3$)" << endl;
														cout << "5- grilled pork (5$)" << endl;
														cout << endl;
														cout << "Snacks" << endl;
														cout << "6- candy(1$)" << endl;
														cout << "7- cookies(1$)" << endl;
														cout << "8- dried fruit(1$)" << endl;
														cout << "9- gum(0.5$)" << endl;
														cout << "10- nuts(1$)" << endl;
														cout << "11- to return" << endl;
														//system("pause");
														cin >> cc;
														while (cc < 1 || cc>11)
														{
															system("cls");
															cout << "sandwiches";
															cout << "1- chicken & cheese (4$)" << endl;
															cout << "2-sausage egg and cheese (5$)" << endl;
															cout << "3- tuna & salad (3$)" << endl;
															cout << "4- ham & egg (3$)" << endl;
															cout << endl;
															cout << "5- grilled pork (5$)" << endl;
															cout << "Snacks" << endl;
															cout << "6- candy(1$)" << endl;
															cout << "7- cookies(1$)" << endl;
															cout << "8- dried fruit(1$)" << endl;
															cout << "9- gum(0.5$)" << endl;
															cout << "10- nuts(1$)" << endl;
															cout << "11- to return" << endl;
															//system("pause");
															cin >> cc;
														}
														if (cc == 1)
															total1 = total1 + 4;
														if (cc == 2)
															total1 = total1 + 5;
														if (cc == 3)
															total1 = total1 + 3;
														if (cc == 4)
															total1 = total1 + 3;
														if (cc == 5)
															total1 = total1 + 5;
														if (cc == 6)
															total1 = total1 + 1;
														if (cc == 7)
															total1 = total1 + 1;
														if (cc == 8)
															total1 = total1 + 1;
														if (cc == 9)
															total1 = total1 + 0.5;
														if (cc == 10)
															total1 = total1 + 1;
														cout << "your total in this section  is : " << total1 << "$" << endl;
														cout << "0-To make more purchase " << endl;
														cout << "11-Return" << endl;
														cin >> cc;
														while (cc != 0 && cc != 11)
														{
															cout << "0-To make more purchases " << endl;
															cout << "11-Return" << endl;
															cin >> cc;
														}


													} while (cc == 0);

												}
												if (bb == 2)
												{
													do
													{
														system("cls");
														cout << "1- counter-stike  (1$)" << endl;
														cout << "2- Player Unkown BattleGround (2$)" << endl;
														cout << "3- Need For Speed (2$)" << endl;
														cout << "4- Fortnite (2$)" << endl;

														cout << "5- to return " << endl;
														cin >> dd;
														while (dd < 1 || dd>5)
														{
															cout << "1- counter-stike  (1$)" << endl;
															cout << "2- Player Unkown BattleGround (2$)" << endl;
															cout << "3- Need For Speed (2$)" << endl;
															cout << "4- Fortnite (2$)" << endl;

															cout << "5- to return" << endl;
															cin >> dd;
														}
														if (dd == 1)
															total2 += 1;;
														if (dd == 2)
															total2 += 2;
														if (dd == 3)
															total2 += 2;
														if (dd == 4)
															total2 += 2;
														cout << "your total in this section  is : " << total2 << "$" << endl;
														cout << "0-To make more purchases" << endl;
														cout << "5-Return" << endl;
														cin >> dd;
														while (dd != 0 && dd != 5)
														{
															cout << "0-To make more purchases" << endl;
															cout << "5-Return" << endl;
														}
													} while (dd == 0);
												}


											}
										} while (cc == 11 || cc == 5);
										if (aa == 2)
										{
											total = total1 + total2;
											cout << "Your total is :" << total << " $" << endl;
											if (balance >= total)
											{
												cout << total << "$ will be deducted from your balance " << endl;
												balance -= total;
												cout << "Your new balance is : " << balance << "$" << endl;
											}
											else
											{
												cout << "Unfortunately the total of purchase is higher than your balance " << endl;
												total = 0;
												total1 = 0;
												total2 = 0;
												cout << "Kindly check your balance before purchasing " << endl;
											}
										}

									} while (bb == 3);
								}

							} while (b == 1 || b == 2);

						}
						if (ii == 51) {
							cout << "\tIncorrect password " << endl;
							break;
						}
					}
					//break;
					//system("cls");
				} while (password2 != password1);

			}
			if (i == 51)
				cout << "\n\tIncorrect username " << endl;
		}
	} while (i != 51);
}

void account::play_game()
{
	char ans;
	system("cls");
	while (game_over())
	{
		display_board();

		player_turn();

		game_over();
		//GamePlay();

	}
	if (turn == 'X' && draw == false)
	{
		cout << "Player2 [0] wins !\n";
	}
	else if (turn == '0' && draw == false)
	{
		cout << "Player1 [X] wins !\n";
	}
	else
	{
		cout << "Game Draw ! \n";
	}
	do {
		cout << "Press '0' to Exit :";
		cin >> ans;
	} while (ans != '0');
}

void account::display_board() {
	system("cls");
	cout << "				Welcome to Tic Tac Toe !" << endl;
	cout << "\tPlayer1 [X] \n\tPlayer2 [0]\n\n";
	cout << "\t\t     |     |     \n";  // using \t for distance and \n for a new line or line feed
	cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "   \n";
	cout << "\t\t_____|_____|_____\n";
	cout << "\t\t     |     |     \n";
	cout << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "   \n";
	cout << "\t\t_____|_____|_____\n";
	cout << "\t\t     |     |     \n";
	cout << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "   \n";
	cout << "\t\t     |     |     \n";
}

void account::player_turn() {

	int choice;

	do {

		if (turn == 'X')
			cout << "\n\tPlayer1 [X] turn: ";

		if (turn == '0')
			cout << "\n\tPlayer2 [0] turn: ";

		cin >> choice;
	} while (choice < 1 || choice > 9);


	switch (choice)
	{
	case 1: row = 0; column = 0; break;
	case 2: row = 0; column = 1; break;
	case 3: row = 0; column = 2; break;
	case 4: row = 1; column = 0; break;
	case 5: row = 1; column = 1; break;
	case 6: row = 1; column = 2; break;
	case 7: row = 2; column = 0; break;
	case 8: row = 2; column = 1; break;
	case 9: row = 2; column = 2; break;
	default:
		cout << "Invalid Choice.\n";
		break;
	}
	if (turn == 'X' && board[row][column] != 'X' && board[row][column] != '0')
	{
		board[row][column] = 'X';
		turn = '0';
	}
	else if (turn == '0' && board[row][column] != 'X' && board[row][column] != '0')
	{
		board[row][column] = '0';
		turn = 'X';
	}
	else {
		cout << "This box is already checked!\n Please try again: \n\n"; //to tell the user that the box is already checked 
		player_turn();
	}
	display_board();

}

bool account::game_over() { //check who won p1 or p2
	//check win
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
			return false;
		}
		if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
			return false;
		}


	}
	//if there is any box not filled
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] != 'X' && board[i][j] != '0')
				return true;

		}
	}

	//check draw
	draw = true;
	return false;
}

int main()
{
	account bankacc;
	int choice;
	do
	{
		system("cls");
		cout << "\n\tMain Menu";
		cout << "\n\t1. Sign up and then Sign in";
		cout << "\n\t2. Play Tick Tac Toe";
		cout << "\n\tPick a number: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			bankacc.main_menu();
			break;
		case 2:
			bankacc.play_game();
			break;
		default:
			break;
		}
	} while (choice < 1 || choice >3);
	return 0;
}



/**/