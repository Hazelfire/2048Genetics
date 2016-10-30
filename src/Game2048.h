
class Game2048{
public:
	Game2048();
	void up();
	void left();
	void right();
	void down();
	void print();
	int score();
	bool lost();
private:
	void place();
	int board[4][4];
};
