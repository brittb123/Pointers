#include "Character.h"

Character::Character()
{
	m_health = 100;
	m_damage = 10;
	m_name[7] = ' ';
}

Character::Character( float health, float damage, char name[8])
{
	m_health = health;
	m_damage = damage;
	m_name[7] = name[7];
	
}

void Character::attack(Character* other)
{
	other->takeDamage(getDamage());
}

float Character::takeDamage(float damageAmount)
{
	m_health -= damageAmount;
	return damageAmount;
}