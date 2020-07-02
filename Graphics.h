#pragma once
#include "Road.h"

class Graphics
{
public:
	Graphics();
	~Graphics();
	roadObj getRoadAt(sf::Vector2f Loc);
private:
	roadObj nroad;
};

inline Graphics::Graphics() : nroad("road_3.jpg", {0.12,0.08})
{
	
}

inline Graphics::~Graphics()
{
}

inline roadObj Graphics::getRoadAt(sf::Vector2f Loc)
{
	nroad.setPosition(Loc);
	return nroad;
}
