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
  void swap_rectangles(sf::RectangleShape &shape1, sf::RectangleShape &shape2);

 private:
  sf::RenderWindow  window;
  int *array;
  sf::RectangleShape *rectangle_array;

  static const sf::Time time_per_frame;
  static const sf::Time time_per_move;
  bool next;
  bool sort;
  bool sorting;
  std::vector<std::pair<unsigned, unsigned>>* moves;

  static const unsigned int DISPLAY_WIDTH = 720;
  static const unsigned int DISPLAY_HEIGHT = 405;
  static const size_t ARRAY_LENGTH = 50;
  static const int64_t MAX_VALUE = 100;
};

#endif //SORTING_ALGORITHMS_SRC_APPLICATION_H_
