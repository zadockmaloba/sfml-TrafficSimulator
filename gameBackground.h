#pragma once
#include <SFML/Graphics.hpp>

class gameBackground : public sf::Sprite
{
public:
	gameBackground(std::string fname, sf::Vector2f nscale = {1,1});
	~gameBackground ();

private:
	const std::string texture_dir = { "Textures/roadText/" };
	sf::Texture bgText;
	sf::Image img;
};

inline gameBackground ::gameBackground (std::string fname, sf::Vector2f nscale)
{
	img.loadFromFile(texture_dir + fname);
	bgText.loadFromImage(img);
	this->setTexture(bgText);
	this->scale(nscale);
}

inline gameBackground ::~gameBackground ()
{
}
