#ifndef OPPONENT_H
#define OPPONENT_H

#include <vector>

#include "cpputils/graphics/image.h"
#include "cpputils/graphics/image_event.h"
#include "game_element.h"

class Opponent : public GameElement {
 public:
  Opponent() : Opponent(0, 0) {}
  Opponent(int x, int y) : GameElement(x, y, 50, 50) {}
  void Draw(graphics::Image &opponent);
  void Move(const graphics::Image &image);
};

class OpponentProjectile : public GameElement {
 public:
  OpponentProjectile() : OpponentProjectile(0, 0) {}
  OpponentProjectile(int x, int y) : GameElement(x, y, 5, 5) {}
  void Draw(graphics::Image &opponent_proj);
  void Move(const graphics::Image &image);
};

class OpponentShield : public GameElement {
 public:
  OpponentShield() : OpponentShield(0, 0) {}
  OpponentShield(int x, int y) : GameElement(x, y, 5, 5) {}
  void Draw(graphics::Image &opponent_shield);
  //  bool IntersectsWith(Opponent &opponent);
 private:
  void PadPoints(std::vector<int> &points, int pad_x, int pad_y);
  const graphics::Color kBlue{0, 0, 255};
};

#endif
