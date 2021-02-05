//
// Created by sappy-joy on 26/01/2021.
//
#include <random>
#include <iostream>
#include "application.h"
#include "algorithms.h"
#include <algorithm>

const sf::Time Application::time_per_frame = sf::seconds(1.f / 60.f);
const sf::Time Application::time_per_move = sf::seconds(1.f / 60.f);

Application::Application() :
window(sf::VideoMode(DISPLAY_WIDTH, DISPLAY_HEIGHT), "Sorting", sf::Style::Close),
rectangle_array(create_rectangle_array(ARRAY_LENGTH)),
next(false),
sort(false)
{}

void Application::run() {
  sf::Clock clock;
  sf::Time time_since_last_update = sf::Time::Zero;
  while (window.isOpen()) {
    /* Делаем постоянное количество кадров в секунду */
    sf::Time elapsed_time = clock.restart();
    time_since_last_update += elapsed_time;
    while (time_since_last_update > time_per_frame) {
      time_since_last_update -= time_per_frame;
      process_events();
      update(time_per_frame);
      render();
    }
  }
}

void Application::process_events() {
  sf::Event event;
  while (window.pollEvent(event)) {
    switch (event.type) {
      case sf::Event::KeyPressed:handle_player_input(event.key.code, true);
        break;
      case sf::Event::KeyReleased:handle_player_input(event.key.code, false);
        break;
      case sf::Event::Closed:
        window.close();
        break;
    }
  }
}

void Application::swap_rectangles(sf::RectangleShape &shape1, sf::RectangleShape &shape2) {
  auto temp = shape1.getSize().y;
  shape1.setSize(sf::Vector2f(shape1.getSize().x, shape2.getSize().y));
  shape2.setSize(sf::Vector2f(shape2.getSize().x, temp));
}

void Application::update(sf::Time time) {
  // Необходимо, чтобы анимация происходила с определённой скоростью
  static sf::Time time_since_last_array_move = sf::Time::Zero;
  static int move_ind = 0;
  time_since_last_array_move += time;

  if (sort == 1) {
    // Сортируем массив и возвращаем массив действий
    sort = 2;
    moves = merge_sort(array, ARRAY_LENGTH);
  }

  if (sort == 2 && time_since_last_array_move > time_per_move) {
    time_since_last_array_move = sf::Time::Zero;

    swap_rectangles(rectangle_array[(*moves)[move_ind].first], rectangle_array[(*moves)[move_ind].second]);

    move_ind++;
    if (move_ind == moves->size())
      sort = 3;
  }
    /* Обновляем рабочий массив */
  if (next) {
    delete [] rectangle_array;
    delete [] array;
    delete moves;
    rectangle_array = create_rectangle_array(ARRAY_LENGTH);
    next = false;
    sort = 0;
    move_ind = 0;
  }
}

void Application::render() {
  window.clear(sf::Color::White);
  for (size_t i = 0; i < ARRAY_LENGTH; i++)
    window.draw(rectangle_array[i]);
  window.display();
}

void Application::handle_player_input(sf::Keyboard::Key key, bool is_pressed) {
  if (key == sf::Keyboard::Space) {
    next = is_pressed;
  }
  if (key == sf::Keyboard::S && is_pressed && sort != 2 && sort != 3) {
    sort = true;
  }
}

int * Application::create_random_array(size_t size) {
  int *array = new int[size];

  std::random_device r;
  std::mt19937 gen(r());
  std::uniform_int_distribution<> dist(1,MAX_VALUE);

  for (size_t i = 0; i < size; i++) {
    array[i] = dist(gen);
  }

  return array;
}


// For new rectangle array you need delete Application::array
sf::RectangleShape * Application::create_rectangle_array(size_t size) {
  array = create_random_array(ARRAY_LENGTH);
  sf::RectangleShape *rectangle_array = new sf::RectangleShape[ARRAY_LENGTH];

  // There will be 0.025 * DISPLAY_WIDTH margin from left and right
  // Around every rectangle will be 0.05 * width margins
  double rectangle_width = ((DISPLAY_WIDTH * 0.95) / ARRAY_LENGTH) * 0.9;
  double rectangle_margin = ((DISPLAY_WIDTH * 0.95) / ARRAY_LENGTH) * 0.05;

  for (size_t i = 0; i < ARRAY_LENGTH; i++) {
    rectangle_array[i].setSize(sf::Vector2f(rectangle_width, -(double)array[i] / MAX_VALUE * (DISPLAY_HEIGHT * 0.8)));
    rectangle_array[i].setFillColor(sf::Color(46, 63, 127)); // #2E3F7F
    rectangle_array[i].setPosition(0.025 * DISPLAY_WIDTH + (rectangle_width + 2 * rectangle_margin) * i + rectangle_margin, DISPLAY_HEIGHT);
  }

  return rectangle_array;
}