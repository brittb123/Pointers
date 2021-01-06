#include "Game.h"
#include <fstream>
#include <iostream>

void Game::run()
{
	start();
	while (!getGameOver())
	{
		update();
		draw();
		system("pause");
	}

	end();
}

bool BinaryFile()
{
	Character Jim = Character();
	Jim.m_health = 100;
	Jim.m_damage = 14;

	Character Jim2 = Character();
	Jim2.m_health = 115;
	Jim2.m_damage = 9;

	Character Jim3 = Character();
	Jim3.m_health = 150;
	Jim3.m_damage = 5;

	std::fstream file;

	file.open("save.txt", std::ios::out | std::ios::binary | std::ios::app);

	if (!file.is_open())
	{
		return false;
	}
	file.write((char*)&Jim, sizeof(Character));
	file.write((char*)&Jim2, sizeof(Character));
	file.write((char*)&Jim3, sizeof(Character));

	file.close();


	return true;

}

bool BinaryLoad()
{
	
	Character player1 = Character();
	int index = 0;
	std::cout << "Which do you wish to load?" << std::endl;
	std::cin >> index;
	std::fstream file;
	file.open("save.txt", std::ios::in, std::ios::binary);

	if (!file.is_open())
	{
		return false;
	}

	file.seekg(sizeof(Character) * index, std::ios::beg);

	file.read((char*)&player1, sizeof(Character));

	file.close();
	std::cout << player1.m_health << std::endl;
	std::cout << player1.m_damage << std::endl;
	return true;

}


void Game::start()
{
	BinaryLoad();
	std::cout << "Player 1 what is your name?" << std::endl;
	char p1name[8];
	char p2name[8];
	std::cin >> p1name;
	std::cin >> p2name;
	
	m_player1 = new Character(100, 10, p1name);
	
	m_player2 = new Character(100, 10, p2name);
	std::cout << p2name << std::endl;
	/*BinaryFile();*/
	
}

void Game::update()
{
	
	std::cout << m_player1->m_name << std::endl;
	std::cout << "Press z to attack or x to defend" << std::endl;
	answer == ' ';
	std::cin >> answer;
	if (answer == 'z')
	{
		m_player1->attack(m_player2);
		end();
	}
	else if(answer == 'x')
	{
		m_player1->m_damage -= 5;
		std::cout << m_player2->m_name;
		std::cout << " Damage has fallen by 5" << std::endl;
	}
	std::cout << "Player Twos turn: " << std::endl;
	std::cin;

	std::cout << m_player2->m_name << std::endl;
	std::cout << "Press z to attack or x to defend" << std::endl;
	answer == ' ';
	std::cin >> answer;
	if (answer == 'z')
	{
		m_player2->attack(m_player1);
		end();
	}
	else if (answer == 'x')
	{
		m_player1->m_damage -= 5;
		std::cout << m_player1->m_name;
		std::cout << " Damage has fallen by 5" << std::endl;
	}
	system("CLS");
	if (m_player1->getHealth() <= 0 || m_player2->getHealth() <= 0)
	{
		setGameOver(true);
	}

}

void Game::draw()
{
	std::cout << "Player2 health is: " << m_player2->getHealth() << std::endl;
	std::cout << "Player1 health is: " << m_player1->getHealth() << std::endl;
}

void Game::end()
{
	
}

