#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	private:
		char sign;
	public:
		Player();
		Player(char sign);
		void setSign(char sign);
		char getSign();
};
#endif