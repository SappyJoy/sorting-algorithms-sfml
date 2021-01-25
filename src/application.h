//
// Created by sappy-joy on 26/01/2021.
//

#ifndef SORTING_ALGORITHMS_SRC_APPLICATION_H_
#define SORTING_ALGORITHMS_SRC_APPLICATION_H_
#include <SFML/Graphics.hpp>

class Application {
 public:
  Application();
  void run();

 private:
  void process_events();
  void update(sf::Time);
  void render();

  void handle_player_input(sf::Keyboard::Key key, bool is_pressed);
  int *create_random_array(size_t size);
  sf::RectangleShape *create_rectangle_array(size_t size);

 private:
  sf::RenderWindow  window;
  sf::RectangleShape *rectangle_array;

  static const sf::Time time_per_frame;
  bool next;

  static const unsigned int DISPLAY_WIDTH = 720;
  static const unsigned int DISPLAY_HEIGHT = 405;
  static const size_t ARRAY_LENGTH = 50;
  static const int64_t MAX_VALUE = 100;
};

#endif //SORTING_ALGORITHMS_SRC_APPLICATION_H_
