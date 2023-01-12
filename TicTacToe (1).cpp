#include <bits/stdc++.h>
using namespace std;

void Take_Input();
int Valid_Input();
bool Check_Winner();
void Print_Board();
void Reset_Board();

char board[9];

void Take_Input(string &name, int &pos_left){

	// Function to proceed the game forward //

	cout << name << "'s turn\nSelect your position(1-9) : ";
	int pos = Valid_Input();

	// For every turn of X, positions left will be an odd number //
 	board[pos-1] = (pos_left % 2 == 0) ? 'O' : 'X';

 	pos_left--;

 	// To show the updated game //
 	Print_Board();

 	return;
}

int Valid_Input(){

	// Function to take a valid position as input //

	int pos;
	while(true){
 			cin >> pos;
 			if(pos > 9 || pos < 0){

 				// If the input doesn't lie between 0 and 9 //
 				cout << "Please choose a valid number : ";
 				continue;
 			}
 			else if(board[pos-1] != ' '){

 				// If the input position is already chosen //
 				cout << "Please choose an available position: ";
 				continue;
 			} 
 			else break;
 		}
 		return pos;
}

bool Check_Winner(){

	// Function to check if the game ends //
	
	// Checking Rows //

	if(board[0] != ' ' && board[0] == board[1] && board[1] == board[2]) return true;
	if(board[3] != ' ' && board[3] == board[4] && board[4] == board[5]) return true;
	if(board[6] != ' ' && board[6] == board[7] && board[7] == board[8]) return true;
	
	// Checking Columns //

	if(board[0] != ' ' && board[0] == board[3] && board[3] == board[6]) return true;
	if(board[1] != ' ' && board[1] == board[4] && board[4] == board[7]) return true;
	if(board[2] != ' ' && board[2] == board[5] && board[5] == board[8]) return true;

	// Checking Diagonals //

	if(board[4] != ' ' && board[4] == board[0] && board[4] == board[8]) return true;
	if(board[4] != ' ' && board[4] == board[2] && board[4] == board[6]) return true;

	// If the game doesn't end //

	return false;

}

void Print_Board(){

	// Function to print the board //

	cout << "\n\n";
	cout << "       |     |     \n    " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  \n  _ _ _|_ _ _|_ _ _\n";
	cout << "       |     |     \n    " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  \n  _ _ _|_ _ _|_ _ _\n";
	cout << "       |     |     \n    " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  \n       |     |     \n";
	cout << "\n\n";
	return;
}
void Reset_Board(){

	// Function to reset the game //

	for(int i = 0; i < 9; i++) board[i] = '0' + (i+1);
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Reset_Board();
	string X, O;
	int pos_left = 9;

	// Printing the title of the game //
	cout << "\n=============================\n||       TIC TAC TOE       ||\n=============================\n\n";

	Print_Board();

	for(int i = 0; i < 9; i++) board[i] = ' ';
 
 	cout << "\n\nEnter the name of the first player(X) : ";
 	cin >> X;
 	cout << "\nEnter the name of the second player(O) : ";
 	cin >> O;

 	Print_Board();

 	while(true){

 		// For every odd turn, positions left will be odd //
 		(pos_left % 2 != 0) ? Take_Input( X, pos_left) : Take_Input( O, pos_left);

 		// If the game ends, we can exit the loop //
 		if(Check_Winner()){
 			(pos_left % 2 == 0) ? cout << X : cout << O;
 			cout << " Wins!!! \n";
 			break;
 		}

 		// If there is no winner //
 		if(!pos_left){
 			cout << "It's a Tie :( \n";
 			break; 
 		}
 	}
 	int ans;
 	cout << "\nWanna play again?\n";
 	cout << "1.YES\n2.NO\n";
 	cin >> ans;

 	// If the user wishes to play again then run the whole code again//
 	if(ans == 1) return main();

	return 0;
}

// END OF CODE //