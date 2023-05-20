#include <SFML/Graphics.hpp>
#include "settings.h"
#include "player.h"
#include "apple.h"

using namespace sf;




void reset_field() {
	for (int j = 0; j < field_size_y; j++) {
		for (int i = 0; i < field_size_x; i++) {
			field[j][i] = FIELD_CELL_TYPE_NONE;
		}
	}
	for (int i = 0; i < snake_lenth; i++) {
		field[player_position_y][player_position_x - i] = snake_lenth - i;
	}
	spawn_apple();
}

void draw_field(RenderWindow& window) {
	sf::Texture none_texture;
	none_texture.loadFromFile("images\\none1.png");
	sf::Sprite none;
	none.setTexture(none_texture);

	sf::Texture snake_texture;
	snake_texture.loadFromFile("images\\snake.png");
	sf::Sprite snake;
	snake.setTexture(snake_texture);

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
				apple.setPosition(float(i * cell_size), float(j * cell_size));
				window.draw(apple);
				break;
			default:
				snake.setPosition(float(i * cell_size), float(j * cell_size));
				window.draw(snake);
			}
		}
	}
}


int main()
{

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake", sf::Style::Close);

	reset_field();

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		move();

		control();

		window.clear(sf::Color(183, 212, 168));
		draw_field(window);
		window.display();

		if (game_over) {
			window.close();
		}

		sf::sleep(milliseconds(100));
	}

	return 0;
}