#pragma once
class Character
{
public:
	Character();
	Character(float health, float damage, char m_name[8]);
	

	void attack(Character* other);
	float takeDamage(float damageAmount);

	float getDamage() { return m_damage; }
	float getHealth() { return m_health; }


	float m_health;
	float m_damage;
	char m_name[8];
	
	
};