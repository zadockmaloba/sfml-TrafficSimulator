#include <SFML/Graphics.hpp>
#include <future>
#include "resourcesDir.h"
#include "gameBackground.h"
#include "roadMapper.h"

static const sf::Vector2i WIN_SIZE{ 800,600 };
void gameLoop(sf::RenderWindow* win);

/*--------------------------------------------------------------------------------
  ---            SFML project by Zadock Maloba                                 ---
  ---                                                                          ---
  ---   E-mail: malobazadock@gmail.com || Tweeter: @Zadock_254                 ---
  --------------------------------------------------------------------------------
*/


int main()
{
	sf::RenderWindow win(sf::VideoMode(WIN_SIZE.x,WIN_SIZE.y), "Simple Traffic Simulator", sf::Style::Close | sf::Style::Resize);
	gameLoop(&win);
}

void gameLoop(sf::RenderWindow* win)
{
	//Declare objects not meant to be in the Loop here...
	gameBackground gbg("grass.jpg", { 0.6, 0.6 });
	roadMapper rdmp(win);

	//Decl_Objs
	while (win->isOpen())
	{
		win->clear();
		//Draw Game Objects Here...
		win->draw(gbg);
		rdmp.drawRoad();

		//Draw_Objs
		//Event Loop ...
		sf::Event evnts;
		while (win->pollEvent(evnts))
		{
			if (evnts.type == sf::Event::Closed) win->close();
		}//Event_loop
		win->display();
	}
}
