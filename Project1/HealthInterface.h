#pragma once
class HealthInterface
{
public:
	virtual int GetHealth()=0;
	virtual int GetMaxHealth()=0;
	virtual void AdjustHealth(int h)=0;
};

