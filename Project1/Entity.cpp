#include "Entity.h"
#include "Visualisation.h"
#include "SDL.h"

Entity::Entity(std::string Name, int maxhp, int attackvalue)
{
	m_name = Name;
	m_maxhealth = maxhp;
	m_damage = attackvalue;
	m_health = m_maxhealth;
	
}

void Entity::PerformAttack(Entity* e)
{
}

std::string Entity::GetName()
{
	return m_name;
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
