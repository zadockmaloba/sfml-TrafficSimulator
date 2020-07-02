#pragma once
#include <SFML/Graphics.hpp>

class roadObj : public sf::Sprite
{
public:
	roadObj(std::string fname, sf::Vector2f nscale = { 1,1 });
	~roadObj();

private:
	const std::string texture_dir = { "Textures/roadText/" };
	sf::Texture bgText;
	sf::Image img;
};

inline roadObj::roadObj(std::string fname, sf::Vector2f nscale)
{
	img.loadFromFile(texture_dir + fname);
	bgText.loadFromImage(img);
	this->setTexture(bgText);
	this->scale(nscale);
	this->setOrigin(40,20);
}

inline roadObj ::~roadObj()
{
}
