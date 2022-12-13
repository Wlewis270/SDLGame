#include "Entity.h"
#include "Visualisation.h"
#include "SDL.h"

Entity::Entity(std::string Name, int maxhp, int attackvalue)
{
}

void Entity::PerformAttack(Entity* e)
{
}

std::string Entity::GetName()
{
	return std::string();
}

void Entity::TakeDamge()
{
}

void Entity::IsDead()
{
}

int Entity::GetHealth()
{
	return 0;
}

int Entity::GetMaxHealth()
{
	return 0;
}

void Entity::AdjustHealth(int h)
{
}
