#include "Blocksgame.h"

void BlocksGame::initWindow()
{
	this->videomode.height = 600;
	this->videomode.width = 800;
	
	this->window = new sf::RenderWindow(this->videomode, "BLOCKS GAME", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(100);
	this->window->setMouseCursorVisible(false);
}

void BlocksGame::initVariables()
{
    this->window = nullptr;

}

void BlocksGame::initHero()
{
	this->hero.setPosition(350.f,465.f);
	this->hero.setRadius(80);
	this->hero.setPointCount(8);
	this->hero.setScale(sf::Vector2f(0.5f,0.5f));
	this->hero.setFillColor(sf::Color(0,0,0,255));
	this->hero.setOutlineThickness(15.f);
	this->hero.setOutlineColor(sf::Color(150,60,100,150));
	

}

void BlocksGame::initBlocks()
{
	this->enemy.setSize(sf::Vector2f(30.f,30.f));
	this->enemy.setPosition(30.f, 10.f);
	this->enemy.setFillColor(sf::Color::Black);
	this->enemy.setOutlineColor(sf::Color::White);
	this->enemy.setOutlineThickness(5.f);
	this->enemy.setScale(sf::Vector2f(0.5f,0.5f));

}

void BlocksGame::initFriends()
{
	this->_friend.setRadius(30);
	this->_friend.setPosition(300.f,10.f);
	this->_friend.setFillColor(sf::Color(0,0,255));
	this->_friend.setOutlineColor(sf::Color(255,255,150));
	this->_friend.setOutlineThickness(5.f);
	this->_friend.setScale(sf::Vector2f(0.5f,0.5f));

}

BlocksGame::BlocksGame()
{
	this->initVariables();
	this->initWindow();
	this->initBlocks();
	this->initFriends();
	this->initHero();
}

BlocksGame::~BlocksGame()
{
	delete this->window; 
}

void BlocksGame::updategame()
{
	this->updateEvents();
	this->updateEnemies();
	this->updateFriends();
}

const bool BlocksGame::isrunning() const
{
	return this->window->isOpen();
}

void BlocksGame::updateHeroPosition(int key)
{
	if(key == 1)
	{	
		
			this->hero.move(8.f,0.f);
	}
	if(key == 0)
	{
		
		this->hero.setPosition(this->hero.getPosition() - sf::Vector2f(8.f,0.f));
	}
}

void BlocksGame::updateEvents()
{
	while(this->window->pollEvent(this->event))
	{
		switch(this->event.type)
		{
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::KeyReleased:
				switch(this->event.key.code)
				{
					case sf::Keyboard::Escape:
						this->window->close();
					case sf::Keyboard::Left:
						this->updateHeroPosition(0);
						break;
					case sf::Keyboard::Right:
						this->updateHeroPosition(1);
						break;
				}		
		}
	}
}

void BlocksGame::updateFriends()
{
	this->_friend.move(0.f,1.f);
}

void BlocksGame::renderFriends()
{
	this->window->draw(this->_friend);
}

void BlocksGame::updateEnemies()
{
	this->enemy.move(0.f,1.f);
}

void BlocksGame::renderEnemies()
{
	this->window->draw(this->enemy);
}

void BlocksGame::renderHero()
{
	this->window->draw(this->hero);
}

void BlocksGame::render()
{
	this->window->clear(sf::Color(170,50,120,255));

	this->renderHero();
	this->renderFriends();
	this->renderEnemies();

	this->window->display();

}

