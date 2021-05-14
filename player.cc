#include "player.h"

#include "cpputils/graphics/image.h"
#include "game_element.h"
#include "opponent.h"

graphics::Color Pblack(0, 0, 0);
graphics::Color Pred(255, 0, 0);
graphics::Color Pblue(0, 0, 255);
graphics::Color Pgreen(0, 255, 0);
graphics::Color Pyellow(255, 255, 0);
graphics::Color Pcyan(0, 255, 255);
graphics::Color Pmagenta(255, 0, 255);

void Player::Draw(graphics::Image &player) {
  // player.DrawRectangle(11, 11, 26, 25, Pyellow);
  // player.DrawRectangle(14, 8, 6, 2, Pblue);
  // player.DrawRectangle(27, 8, 6, 2, Pblue);
  // player.DrawRectangle(15, 17, 18, 0, Pcyan);
  // player.SaveImageBmp("player.bmp");

  graphics::Image play;
  play.Load("player.bmp");
  for (int i = 0; i < GetWidth(); i++) {
    for (int j = 0; j < GetHeight(); j++) {
      player.SetColor(GetX() + i, GetY() + j, play.GetColor(i, j));
    }
  }
}

void PlayerProjectile::Draw(graphics::Image &player_proj) {
  // player_proj.DrawRectangle(0, 0, 5, 5, Pblue);
  // player_proj.SaveImageBmp("playerProjectile.bmp");

  graphics::Image play_proj;
  play_proj.Load("playerProjectile.bmp");
  for (int i = 0; i < GetWidth(); i++) {
    for (int j = 0; j < GetHeight(); j++) {
      player_proj.SetColor(GetX() + i, GetY() + j, play_proj.GetColor(i, j));
    }
  }
}

void Player::Move(const graphics::Image &image) {}

void PlayerProjectile::Move(const graphics::Image &image) {
  SetY(GetY() - 2);
  if (IsOutOfBounds(image)) {
    SetIsActive(false);
  } else {
    SetIsActive(true);
  }
}

// for (int i = 0; i < kHeight_; i++) {
// for (int j = 0; j < kWidth_; j++) {
// image.SetColor(x_ + j, y_ + i, play.GetColor(i, j));
//}
//}

// bool Player::IntersectsWith(Opponent &opponent) {
//   int x = opponent.GetX();
//   int y = opponent.GetY();
//   int width = opponent.GetWidth();
//   int height = opponent.GetHeight();
//   if (GetX() >= x && GetY() <= (x + width) && GetY() >= y &&
//       GetY() <= (y + height)) {
//     return true;
//   } else if ((GetX() + GetWidth()) >= x &&
//              (GetX() + GetWidth()) <= (x + width) && GetY() >= y &&
//              GetY() <= (y + height)) {
//     return true;
//   } else if (GetX() >= x && GetX() <= (x + width) &&
//              (GetY() + GetHeight()) >= y &&
//              (GetY() + GetHeight()) <= (y + height)) {
//     return true;
//   } else if ((GetX() + GetWidth()) >= x &&
//              (GetX() + GetWidth()) <= (x + width) &&
//              (GetY() + GetHeight()) >= y &&
//              (GetY() + GetHeight()) <= (y + height)) {
//     return true;
//   } else {
//     return false;
//   }
// }
// bool Player::IntersectsWith(OpponentProjectile &projectile) {
//   int x = projectile.GetX();
//   int y = projectile.GetY();
//   int width = projectile.GetWidth();
//   int height = projectile.GetHeight();
//   if (GetX() >= x && GetY() <= (x + width) && GetY() >= y &&
//       GetY() <= (y + height)) {
//     return true;
//   } else if ((GetX() + GetWidth()) >= x &&
//              (GetX() + GetWidth()) <= (x + width) && GetY() >= y &&
//              GetY() <= (y + height)) {
//     return true;
//   } else if (GetX() >= x && GetX() <= (x + width) &&
//              (GetY() + GetHeight()) >= y &&
//              (GetY() + GetHeight()) <= (y + height)) {
//     return true;
//   } else if ((GetX() + GetWidth()) >= x &&
//              (GetX() + GetWidth()) <= (x + width) &&
//              (GetY() + GetHeight()) >= y &&
//              (GetY() + GetHeight()) <= (y + height)) {
//     return true;
//   } else {
//     return false;
//   }
// }

// bool PlayerProjectile::IntersectsWith(Opponent &opponent) {
//   int x = opponent.GetX();
//   int y = opponent.GetY();
//   int width = opponent.GetWidth();
//   int height = opponent.GetHeight();
//   if (GetX() >= x && GetY() <= (x + width) && GetY() >= y &&
//       GetY() <= (y + height)) {
//     return true;
//   } else if ((GetX() + GetWidth()) >= x &&
//              (GetX() + GetWidth()) <= (x + width) && GetY() >= y &&
//              GetY() <= (y + height)) {
//     return true;
//   } else if (GetX() >= x && GetX() <= (x + width) &&
//              (GetY() + GetHeight()) >= y &&
//              (GetY() + GetHeight()) <= (y + height)) {
//     return true;
//   } else if ((GetX() + GetWidth()) >= x &&
//              (GetX() + GetWidth()) <= (x + width) &&
//              (GetY() + GetHeight()) >= y &&
//              (GetY() + GetHeight()) <= (y + height)) {
//     return true;
//   } else {
//     return false;
//   }
// }
