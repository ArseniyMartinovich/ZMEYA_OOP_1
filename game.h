#pragma once
#include "settings.h"
#include "player.h"


class Game {
private:
	sf::RenderWindow window;
	Player player;
	Apple apple;

	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();
	}

	void reset_field() {
		for (int j = 0; j < field_size_y; j++) {
			for (int i = 0; i < field_size_x; i++) {
				field[j][i] = FIELD_CELL_TYPE_NONE;
			}
		}
		for (int i = 0; i < player.getLenth(); i++) {
			field[player.getPlayerPosY][player.getPlayerPosX - i] = player.getLenth() - i;
		}
		spawn_apple();
	}

	void update() {
		
		player.update();
	}

	void draw() {
		window.clear(sf::Color(183, 212, 168));
		sf::Texture none_texture;
		none_texture.loadFromFile("images\\none1.png");
		sf::Sprite none;
		none.setTexture(none_texture);

		/*sf::Texture snake_texture;
		snake_texture.loadFromFile("images\\snake.png");
		sf::Sprite snake;
		snake.setTexture(snake_texture);*/

		sf::Texture apple_texture;
		apple_texture.loadFromFile("images\\apple.png");
		sf::Sprite apple;
		apple.setTexture(apple_texture);



		for (int j = 0; j < field_size_y; j++) {
			for (int i = 0; i < field_size_x; i++) {
				switch (field[j][i]) {
				case FIELD_CELL_TYPE_NONE:
					none.setPosition(float(i * cell_size), float(j * cell_size));
					window.draw(none);
					break;
				case FIELD_CELL_TYPE_APPLE:
					/*apple.setPosition(float(i * cell_size), float(j * cell_size));
					window.draw(apple);*/
					apple.draw(window);
					break;
				default:
					/*snake.setPosition(float(i * cell_size), float(j * cell_size));
					window.draw(snake);*/
					player.draw(window);
				}
			}
		}
		window.display();
	}
public:
	Game() :
		window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Close)
	{
		window.setFramerateLimit(FPS);
	}
	void play() {
		while (/*window.isOpen() && */game_over = false)
		{
			checkEvents();
			update();
			draw();
		}
	}
};