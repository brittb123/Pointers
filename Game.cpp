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

void Game::start()
{
	m_player1 = new Character(10, 10);
	m_player2 = new Character(10, 10);
}

void Game::update()
{
	std::cout << "Player 1 do you want to attack or defend?" << std::endl;
	std::cout << "Press z to attack or x to defend" << std::endl;
	std::cin >> answer;
	if (answer = "z" || "Z")
	{
		m_player1->attack(m_player2);
	}
	
	system("CLS");
	
}

void Game::draw()
{
	std::cout << "Player2 health is: " << m_player2->getHealth() << std::endl;
}

void Game::end()
{
	std::fstream file;

	file.open("save.txt", std::ios::out);
	
		file << m_player2->m_damage << std::endl;
		file << m_player2->m_health;
		file.close();

	delete m_player1;
	delete m_player2;
}


