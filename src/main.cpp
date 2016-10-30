#include <iostream>
#include "Game2048.h"
#include <string>

int main(){
	Game2048 game;
	while(!game.lost()){
		game.print();
		std::string control;
		do{
		control = "";
		std::cin >> control;
		if (control == "r") {
			game.right();
		}
		else if (control == "u") {
			game.up();
		}
		else if (control == "d") {
			game.down();
		}
		else if (control == "l") {
			game.left();
		}
		else{
			continue;
		}
		break;
		} while (true);
	}

	return 0;
}
