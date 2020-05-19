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

void BlocksGame::initBlocks()
{

}

BlocksGame::BlocksGame()
{
	this->initVariables();
	this->initWindow();
	this->initBlocks();
}

BlocksGame::~BlocksGame()
{
	delete this->window; 
}

void BlocksGame::updategame()
{
	this->updateEvents();
}

const bool BlocksGame::isrunning() const
{
	return this->window->isOpen();
}

void BlocksGame::updateHeroPosition()
{

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
				}		
		}
	}
}

void BlocksGame::render()
{
	this->window->clear(sf::Color(170,50,120,255));

	this->window->display();

}
