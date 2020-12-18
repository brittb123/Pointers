#include "Game.h"
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
	m_player1->attack(m_player2);
}

void Game::draw()
{
	std::cout << "Player2 health is: " << m_player2->getHealth() << std::endl;
}

void Game::end()
{
	delete m_player1;
	delete m_player2;
}

char name[8];
char name2[8];