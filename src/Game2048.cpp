#include "Game2048.h"
#include <iostream>
#include <string>

Game2048::Game2048(){
	for(int x = 0; x < 4; x++){
		for(int y = 0; y < 4; y++){
			board[x][y] = 0;
		}
	}

	place();
}


void Game2048::place(){
	int x, y;
	do{
		x = rand() % 4;
		y = rand() % 4;
	}while(board[x][y] != 0);
	board[x][y] = (rand() % 2 + 1) * 2;

}

int Game2048::score(){
	int score = 0;
	for(int x = 0;  x < 4; x++){
		for(int y = 0; y < 4; y++ ){
			score += board[x][y];	
		}
	}

	return score;
}

void Game2048::print() {
	for (int y = 3; y >= 0; y--) {
		for(int x = 0; x < 4; x++){
			std::cout << board[x][y] << "\t";
		}
		std::cout << std::endl;
	}
}

void Game2048::down(){
	
	for(int x = 0; x < 4; x++){
		for(int y = 1; y < 4; y++){
			int fally = y - 1;
			while(fally >= 0 && board[x][fally] == 0){
				fally--;
			}
			
			// If we hit the bottom 
			if(fally == -1){
				board[x][0] = board[x][y];
				board[x][y] = 0;
			}

			// Otherwise, we hit a tile, is it the same as us?
			else if(board[x][y] == board[x][fally]){
				// It is!! we should add them together
				board[x][fally] = board[x][fally] * 2;
				board[x][y] = 0;
			}

			// Otherwise we hit a tile that is not the same
			else{
				board[x][fally + 1] = board[x][y];
				if(y != fally + 1){
					board[x][y] = 0;
				}
			}
			
		}
	}

	// finally, place another tile
	place();
}

void Game2048::up() {

	for (int x = 0; x < 4; x++) {
		for (int y = 2; y <= 0; y--) {
			int fally = y + 1;
			while (fally < 4 && board[x][fally] == 0) {
				fally++;
			}

			// If we hit the top 
			if (fally == 4) {
				board[x][3] = board[x][y];
				board[x][y] = 0;
			}

			// Otherwise, we hit a tile, is it the same as us?
			else if (board[x][y] == board[x][fally]) {
				// It is!! we should add them together
				board[x][fally] = board[x][fally] * 2;
				board[x][y] = 0;
			}

			// Otherwise we hit a tile that is not the same
			else {
				board[x][fally - 1] = board[x][y];
				if (y != fally - 1) {
					board[x][y] = 0;
				}
			}

		}
	}

	// finally, place another tile
	place();
}

void Game2048::right() {

	for (int y = 0; y < 4; y++) {
		for (int x = 2; x >= 0; x--) {
			int fallx = x + 1;
			while (fallx < 4 && board[fallx][y] == 0) {
				fallx++;
			}

			// If we hit the right 
			if (fallx == 4) {
				board[3][y] = board[x][y];
				board[x][y] = 0;
			}

			// Otherwise, we hit a tile, is it the same as us?
			else if (board[x][y] == board[fallx][y]) {
				// It is!! we should add them together
				board[fallx][y] = board[fallx][y] * 2;
				board[x][y] = 0;
			}

			// Otherwise we hit a tile that is not the same
			else {
				board[fallx  - 1][y] = board[x][y];
				if (x != fallx - 1) {
					board[x][y] = 0;
				}
			}

		}
	}

	// finally, place another tile
	place();
}

void Game2048::left() {

	for (int y = 0; y < 4; y++) {
		for (int x = 1; x < 4; x++) {
			int fallx = x - 1;
			while (fallx >= 0 && board[fallx][y] == 0) {
				fallx--;
			}

			// If we hit the left 
			if (fallx == -1) {
				board[0][y] = board[x][y];
				board[x][y] = 0;
			}

			// Otherwise, we hit a tile, is it the same as us?
			else if (board[x][y] == board[fallx][y]) {
				// It is!! we should add them together
				board[fallx][y] = board[fallx][y] * 2;
				board[x][y] = 0;
			}

			// Otherwise we hit a tile that is not the same
			else {
				board[fallx + 1][y] = board[x][y];
				if (x != fallx + 1) {
					board[x][y] = 0;
				}
			}

		}
	}

	// finally, place another tile
	place();
}

bool Game2048::lost(){
	for(int x = 0; x < 4; x++){
		for(int y = 0; y < 4; y++){
			if(board[x][y] == 0){
				return false;
			}
		}
	}
}
