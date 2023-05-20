#pragma once
#include <SFML/Graphics.hpp>

const std::string WINDOW_TITLE = "Snake";
const float FPS = 60.f;

const int field_size_x = 35;
const int field_size_y = 25;
const int cell_size = 32;
const int WINDOW_WIDTH = field_size_x * cell_size;
const int WINDOW_HEIGHT = field_size_y * cell_size;

int field[field_size_y][field_size_x];

const int FIELD_CELL_TYPE_NONE = 0;
const int FIELD_CELL_TYPE_APPLE = -1;

const int SNAKE_DIRECTION_UP = 0;
const int SNAKE_DIRECTION_RIGHT = 1;
const int SNAKE_DIRECTION_DOWN = 2;
const int SNAKE_DIRECTION_LEFT = 3;


bool game_over = false;

const std::string IMAGES_FOLDER{ "images\\" };
const std::string PLAYER_FILE_NAME = "snake.png";
const std::string APPLE_FILE_NAME = "apple.png";
