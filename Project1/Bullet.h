#include <string>
#include "Object.h"
class Entity;
class Game;

class Bullet: public Object
{
public:
	Bullet(Entity*player);
	std::string Getname();
	void Initialise();
	void Update();
private:
	Game* ent_game = nullptr;
};
