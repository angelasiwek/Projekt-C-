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
	this->health = 5;
	this->points = 0;
	this->enemySpawnTimeMAX = 400.f;
	this->enemySpawnTime = this->enemySpawnTimeMAX;
	this->friendSpawnTimeMAX = 200.f;
	this->friendSpawnTime = this->friendSpawnTimeMAX;
	this->enemiesMAX = 3;
	this->friendsMAX = 5;
	this->gameover = false;	
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
	this->initFont();
	this->initText();
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
	this->updateText();
}

const bool BlocksGame::isrunning() const
{
	return this->window->isOpen();
}

int BlocksGame::isGameOver()
{
	if(this->gameover == true)
		{
			
			std::cout << "Game Over. Zakonczono gre z wynikiem: " << this->points << std::endl;
			return 1;

		}
	else
		return 0;
	
}

int BlocksGame::updateHeroPosition(int key)
{
	
	if(key == 0)
	{
		if(this->hero.getPosition().x <= 0)
			return 0;
	}
	if(key == 1)
		{
			if(this->hero.getPosition().x >= (this->window->getSize().x - this->hero.getRadius()) )
			{
				return 0;
			}
		}
	return 1;
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
						if(this->updateHeroPosition(0) == 1)
							{
								this->hero.setPosition(this->hero.getPosition() - sf::Vector2f(20.f,0.f));
								this->HeroPosition = hero.getPosition();
							}
						break;
					case sf::Keyboard::Right:
						if(this->updateHeroPosition(1) == 1)
						{
							this->hero.move(20.f,0.f);
							this->HeroPosition = hero.getPosition();
						}
						break;
				}		
		}
	}
}

void BlocksGame::updateFriends()
{
	if(this->friends.size() < this->friendsMAX)
	{
		if(this->friendSpawnTime >= this->friendSpawnTimeMAX)
		{
			this->spawnFriends();
			this->friendSpawnTime = 0.f;
		}
		else
		{
			this->friendSpawnTime += 1.f;
		}
		
	}

	for(int i = 0; i < this->friends.size(); i++)
	{
		bool deleted = false;
		this->friends[i].move(0.f,0.5f);
		if(this->hero.getGlobalBounds().contains(this->friends[i].getPosition()))
		{
			deleted = true; 
			this->points += 100.f;
		}
		if(this->friends[i].getPosition().y > this->window->getSize().y)
		{
			deleted = true;
		}
		if(deleted)
		{
			this->friends.erase(this->friends.begin() + i);
		}
	}

}

void BlocksGame::renderFriends()
{
	for( auto &f : this->friends )
	{
		this->window->draw(f);
	}
}

void BlocksGame::spawnFriends()
{
	this->_friend.setPosition( static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->_friend.getRadius())), 0.f);
	this->_friend.setFillColor(sf::Color::Cyan);
	this->friends.push_back(this->_friend);
}

void BlocksGame::updateEnemies()
{
	if(this->enemies.size() < this->enemiesMAX)
	{
		if(this->enemySpawnTime >= this->enemySpawnTimeMAX)
		{
			this->spawnEnemies();
			this->enemySpawnTime = 0.f;
		}
		else
		{
			this->enemySpawnTime += 1.f;
		}
		
	}

	for(int i = 0; i < this->enemies.size(); i++)
	{
		bool deleted = false;
		this->enemies[i].move(0.f,0.5f);
		if(this->hero.getGlobalBounds().contains(this->enemies[i].getPosition()))
		{
			deleted = true; 
			this->health -= 1;
			
		}
		if(this->enemies[i].getPosition().y > this->window->getSize().y)
		{
			deleted = true;
		}
		if(deleted)
		{
			this->enemies.erase(this->enemies.begin() + i);
		}
		if(this->health <= 0)
			this->gameover = true;
	}
}

void BlocksGame::renderEnemies()
{
	for( auto &e : this->enemies )
	{
		this->window->draw(e);
	}
}

void BlocksGame::spawnEnemies()
{	
	this->enemy.setPosition( static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)), 0.f);
	this->enemy.setFillColor(sf::Color::Black);
	this->enemies.push_back(this->enemy);

}

void BlocksGame::renderHero()
{
	this->window->draw(this->hero);
}

void BlocksGame::initFont()
{
	
	if(!this->font.loadFromFile("arial.ttf"));
	{
		std::cout << "ERROR: Can't load font. " << std::endl;
	}

}

void BlocksGame::initText()
{
	this->text.setFont(this->font);
	this->text.setFillColor(sf::Color::Black);
	this->text.setString("nothing");
	this->text.setCharacterSize(16);
	this->text.setPosition(sf::Vector2f(3.f,10.f));
}

void BlocksGame::render()
{
	this->window->clear(sf::Color(170,50,120,255));

	this->renderHero();
	this->renderFriends();
	this->renderEnemies();
	this->renderText();
	this->window->display();

}

void BlocksGame::renderText()
{
	this->window->draw(this->text);
}

void BlocksGame::updateText()
{
	std::stringstream s;
	s << "Points: " << this->points << " Health: " << this->health << "\n";
	this->text.setString(s.str());
}
