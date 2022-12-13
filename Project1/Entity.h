#pragma once
#include <string>
#include "Object.h"
#include"HealthInterface.h"

class Entity : public Object, public HealthInterface
{
	Entity(std::string Name, int maxhp,  int attackvalue);
	void PerformAttack(Entity* e);
	std::string GetName();
	void TakeDamge();
	void IsDead();
	// Inherited via HealthInterface
	virtual int GetHealth() override;

	virtual int GetMaxHealth() override;


	virtual void AdjustHealth(int h) override;


	
protected:
	std::string m_name;
	int m_damage;
	int m_maxhealth;
	int m_health;
	
};
