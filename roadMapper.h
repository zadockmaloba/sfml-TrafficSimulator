#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Graphics.h"

class roadMapper
{
public:
	roadMapper(sf::RenderWindow* win);
	~roadMapper();
	std::vector<sf::Vector2f> coordGen(sf::Vector2f juctionPos = {300,300});
	void drawRoad();
	void initRoad();
	

private:
	sf::RenderWindow* cwin;
	std::vector<sf::Vector2f> mapCoordinates;
	std::vector<roadObj> elemTextures;
	const float imgScale = 0.03;
	Graphics gfx;

};

inline roadMapper::roadMapper(sf::RenderWindow* win) : cwin(win)
{
	mapCoordinates=coordGen();
	initRoad();
}

inline roadMapper::~roadMapper()
{
}

inline std::vector<sf::Vector2f> roadMapper::coordGen(sf::Vector2f juctionPos)
{
	std::vector<sf::Vector2f> coordVec;
	int numRoadsY = cwin->getSize().y / 40;
	int numRoadsX;
	for (int i = 0; i < numRoadsY/2; i++) {
		juctionPos += {0, 65};
		coordVec.push_back(juctionPos);
	}
	return coordVec;
}

inline void roadMapper::drawRoad()
{
	for (int i = 0; i < elemTextures.size(); i++)
	{
		cwin->draw(elemTextures[i]);
	}
}

inline void roadMapper::initRoad()
{
	for (int i = 0; i < mapCoordinates.size(); i++)
	{
		elemTextures.push_back(gfx.getRoadAt(mapCoordinates[i]));
	}
}
