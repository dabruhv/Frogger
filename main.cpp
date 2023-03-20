#include<SFML/Graphics.hpp>
#include<iostream>
#include"globals.h"
#include"frog.h"
using namespace std;

int main() {//LEFT OFF AT SLIDE 16!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	srand(time(NULL));
	bool keys[] = { false,false,false,false };
	int timer = 0;

	sf::RenderWindow screen(sf::VideoMode(1000, 1000), "Frogger!");

	frog player;//instantiate fwog

	while (screen.isOpen()) {//game loop/////////////////////////////////////////////////////////////////////////////////////////
		sf::Event event;
		while (screen.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				screen.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				keys[UP] = true;
			}
			else keys[UP] = false;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				keys[DOWN] = true;
			}
			else keys[DOWN] = false;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				keys[LEFT] = true;
			}
			else keys[LEFT] = false;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				keys[RIGHT] = true;
			}
			else keys[RIGHT] = false;
		}
		//physics section---------------------------------------
		timer++;
		if (timer > 200) {
			player.jump(keys);
			timer = 0;
		}
		//render section----------------------------------------
		screen.clear();
		player.draw(screen);
		screen.display();


	}//end game loop////////////////////////////////////////////////////////////////////////////////////////////////////////////
	cout << "game over." << endl;
	return 0;

}
