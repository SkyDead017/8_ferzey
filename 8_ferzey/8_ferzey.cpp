#include<iostream>
#include<clocale>
using namespace std;
int board[8][8];
void putqueen(int i, int j) {
	for (int x = 0; x <= 7; ++x) {
		++board[x][j];
		++board[i][x];
		int m;
		m = j - i + x;
		if (m >= 0 && m <= 7) ++board[x][m];
		m = j + i - x;
		if (m >= 0 && m <= 7) ++board[x][m];
	}
	board[i][j] = -1;
}
void removequeen(int i, int j) {
	for (int x = 0; x <= 7; ++x) {
		--board[x][j];
		--board[i][x];
		int m;
		m = j - i + x;
		if (m >= 0 && m <= 7) --board[x][m];
		m = j + i - x;
		if (m >= 0 && m <= 7) --board[x][m];
	}
	board[i][j] = 0;
}
bool tryqueen(int i) {
	bool result = false;
	for (int j = 0; j <= 7; ++j) {
		if (board[i][j] == 0) {
			putqueen(i, j);
			if (i == 7) result = true;
			else {
				result = tryqueen(i + 1);
				if (result==false) removequeen(i, j);
			}
		}
	}
	return result;
}
int main(){
	setlocale(LC_ALL,"Ru");
	for (int i = 0; i <= 7; ++i) {
		for (int j = 0; j <= 7; ++j) {
			board[i][j] = 0;
		}
	}
	tryqueen(0);
	for (int i = 0; i <= 7; ++i) {
		for (int j = 0; j <= 7; ++j) {
			if (board[i][j] == -1)
				cout << "Q";
			else
				cout << "*";
		}
		cout << endl;
	}
	return 0;
}