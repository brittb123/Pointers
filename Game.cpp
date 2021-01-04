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

	Character Jim1 = Character();

	file.open("save.txt", std::ios::in, std::ios::binary);

	if (!file.is_open())
	{
		return false;
	}

	file.seekg(sizeof(Character) * 2, std::ios::beg);

	file.read((char*)&Jim2, sizeof(Character));

	file.close();

	return true;

}

void Game::start()
{
	m_player1 = new Character(10, 10);
	m_player2 = new Character(10, 10);
	BinaryFile();
}

void Game::update()
{
	std::cout << "Player 1 do you want to attack or defend?" << std::endl;
	std::cout << "Press z to attack or x to defend" << std::endl;
	answer = ' ';
	std::cin >> answer;
	if (answer == 'z' | 'Z')
	{
		m_player1->attack(m_player2);
		end();
	}
	else if(answer == 'x' | 'X')
	{
		m_player2->m_damage -= 5;
	}
	system("CLS");
}

void Game::draw()
{
	std::cout << "Player2 health is: " << m_player2->getHealth() << std::endl;
}

void Game::end()
{
	
}
