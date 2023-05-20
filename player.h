#pragma once
#include "settings.h"
#include "apple.h"

class Player {
private:
	sf::Sprite snake;
	sf::Texture snake_texture;
	int player_position_x = field_size_x / 2;
	int player_position_y = field_size_y / 2;
	int snake_lenth = 4;
	int snake_direction = SNAKE_DIRECTION_RIGHT;

public:
	Player();
	void grow();
	void control();
	void move();
	void update();
	void draw(sf::RenderWindow& window);
	int getLenth() { return snake_lenth; }
	int getPlayerPosY() { return player_position_y; }
	int getPlayerPosX() { return player_position_x; }
};

Player::Player() {
	int snake_direction = SNAKE_DIRECTION_RIGHT;
	snake_texture.loadFromFile(IMAGES_FOLDER + PLAYER_FILE_NAME);
	snake.setTexture(snake_texture);
	snake.setPosition(player_position_x , player_position_y );
}

void Player::update() {
	grow();
	move();
	control();
}

void Player:: draw(sf::RenderWindow& window) {
	for (int j = 0; j < field_size_y; j++) {
		for (int i = 0; i < field_size_x; i++) {
			snake.setPosition(float(i * cell_size), float(j * cell_size));
			window.draw(snake);
		}
	}
}

void Player::grow() {
	for (int j = 0; j < field_size_y; j++) {
		for (int i = 0; i < field_size_x; i++) {
			if (field[j][i] > FIELD_CELL_TYPE_NONE) {
				field[j][i] ++;
			}
		}
	}
}

void Player::control() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (snake_direction != SNAKE_DIRECTION_DOWN) {
			snake_direction = SNAKE_DIRECTION_UP;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (snake_direction != SNAKE_DIRECTION_LEFT) {
			snake_direction = SNAKE_DIRECTION_RIGHT;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (snake_direction != SNAKE_DIRECTION_UP) {
			snake_direction = SNAKE_DIRECTION_DOWN;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (snake_direction != SNAKE_DIRECTION_RIGHT) {
			snake_direction = SNAKE_DIRECTION_LEFT;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		game_over = true;
	}
}

void Player::move() {
	switch (snake_direction) {
	case SNAKE_DIRECTION_UP:
		player_position_y--;
		if (player_position_y < 0) {
			player_position_y = field_size_y - 1;
		}
		break;


	case SNAKE_DIRECTION_RIGHT:
		player_position_x++;
		if (player_position_x > field_size_x - 1) {
			player_position_x = 0;
		}
		break;


	case SNAKE_DIRECTION_DOWN:
		player_position_y++;
		if (player_position_y > field_size_y - 1) {
			player_position_y = 0;
		}
		break;


	case SNAKE_DIRECTION_LEFT:
		player_position_x--;
		if (player_position_x < 0) {
			player_position_x = field_size_x - 1;
		}
		break;
	}


	if (field[player_position_y][player_position_x] != FIELD_CELL_TYPE_NONE) {
		switch (field[player_position_y][player_position_x]) {
		case FIELD_CELL_TYPE_APPLE:
			snake_lenth++;
			grow();
			spawn();
			break;
		default:
			game_over = true;
		}
	}

	field[player_position_y][player_position_x] = snake_lenth + 1;

	for (int j = 0; j < field_size_y; j++) {
		for (int i = 0; i < field_size_x; i++) {
			if (field[j][i] > FIELD_CELL_TYPE_NONE) {
				field[j][i]--;
			}
		}
	}
}

