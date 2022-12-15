#include <string>
#include "Object.h"
class Entity;
class Game;
class Player;

class Bullet: public Object
{
public:
	Bullet(Player*player);
	~Bullet();
	std::string Getname();
	void Initialise();
	void Update();
	bool Collision();
private:
	Game* ent_game = nullptr;
	Player* ent_player;
};
