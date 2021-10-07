#include "opponent.h"

#include "cpputils/graphics/image.h"
#include "game_element.h"

graphics::Color black(0, 0, 0);
graphics::Color red(255, 0, 0);
graphics::Color blue(0, 0, 255);
graphics::Color green(0, 255, 0);
graphics::Color yellow(255, 255, 0);
graphics::Color cyan(0, 255, 255);
graphics::Color magenta(255, 0, 255);

void Opponent::Draw(graphics::Image &opponent) {
  // opponent.DrawRectangle(11, 11, 26, 25, red);
  // opponent.DrawRectangle(24, 13, 0, 22, black);
  // opponent.DrawRectangle(13, 23, 22, 0, black);
  // opponent.DrawRectangle(22, 6, 4, 4, magenta);
  // opponent.SaveImageBmp("opponent.bmp");

  graphics::Image opp;
  opp.Load("opponent.bmp");
  for (int i = 0; i < GetWidth(); i++) {
    for (int j = 0; j < GetHeight(); j++) {
      opponent.SetColor(GetX() + i, GetY() + j, opp.GetColor(i, j));
    }
  }
}

void OpponentProjectile::Draw(graphics::Image &opponent_proj) {
  opponent_proj.DrawRectangle(0, 0, 10, 10, red);
  opponent_proj.DrawRectangle(3, 0, 4, 6, red);
  opponent_proj.SaveImageBmp("opponentProjectile.bmp");
  
  // graphics::Image opp_proj;
  // opp_proj.Load("opponentProjectile.bmp");
  // for (int i = 0; i < GetWidth(); i++) {
  //   for (int j = 0; j < GetHeight(); j++) {
  //     opponent_proj.SetColor(GetX() + i, GetY() + j, opp_proj.GetColor(i, j));
  //   }
  // }
}

void OpponentShield::Draw(graphics::Image &opponent_shield) {
  opponent_shield.DrawRectangle(15, 15, 20, 20, black);
  opponent_shield.DrawRectangle(30, 13, 0, 15, magenta);
  opponent_shield.SaveImageBmp("opponentShield.bmp");

  // graphics::Image opp;
  // opp.Load("opponentShield.bmp");
  // for (int i = 0; i < GetWidth(); i++) {
  //   for (int j = 0; j < GetHeight(); j++) {
  //     opponent_shield.SetColor(GetX() + i, GetY() + j, opp.GetColor(i, j));
  //   }
  // }
}

void Opponent::Move(const graphics::Image &image) {
  SetY(GetY() + 1);
  SetX(GetX() + 1);
  if (IsOutOfBounds(image)) {
    SetIsActive(false);
  } else {
    SetIsActive(true);
  }
}

void OpponentProjectile::Move(const graphics::Image &image) {
  SetY(GetY() + 3);
  if (IsOutOfBounds(image)) {
    SetIsActive(false);
  } else {
    SetIsActive(true);
  }
}
