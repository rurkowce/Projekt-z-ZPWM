#include "player.h"

Player::Player(int x, int y)
{
  position_x_ = x;
  position_y_ = y;
}


Player::~Player()
{
}

int Player::return_position_x()const
{
  return position_x_;
}

int Player::return_position_y()const
{
  return position_y_;
}

void Player::move_up()
{
  if (position_x_ < 80 || position_x_>1205 || position_y_ < 31 || position_y_ >550 ||
    (position_x_ > 227 && position_x_ < 356 && position_y_>249 && position_y_ < 385) ||
    (position_y_ > 438 && position_x_ > 521 && position_x_ < 744) ||
    (position_y_ > 211 && position_y_ < 275 && position_x_>246 && position_x_ < 671)||
     (position_y_>493 && position_x_>439)|| (position_y_>391 && position_x_> 1064) ||
     (position_y_<105 && position_x_>343 && position_x_<490)||
     (position_y_<117 && position_x_> 764 && position_x_< 896)|| (position_x_>1120 && position_y_>334)||
     (position_y_>263 && position_y_<290 && position_x_>713 && position_x_<993)||
     (position_y_>255 && position_y_<328 && position_x_>221 && position_x_<451)||
     (position_y_<348 && position_y_>266 && position_x_>841 && position_x_<915)||
     (position_y_>208 && position_y_<241 && position_x_<1034 && position_x_>987)||
    (position_x_<243 && position_x_>218 && position_y_>184 && position_y_<429))
    position_y_ = position_y_ - (0.2*speed);
  else
    position_y_ = position_y_ - speed;
}

void Player::move_right()
{
  if (position_x_ < 80 || position_x_>1205 || position_y_ < 31 || position_y_ >550 ||
    (position_x_ > 227 && position_x_ < 356 && position_y_>249 && position_y_ < 385) ||
    (position_y_ > 438 && position_x_ > 521 && position_x_ < 744) ||
    (position_y_ > 211 && position_y_ < 275 && position_x_>246 && position_x_ < 671) ||
    (position_y_>493 && position_x_>439) || (position_y_>391 && position_x_> 1064) ||
    (position_y_<105 && position_x_>343 && position_x_<490) ||
    (position_y_<117 && position_x_> 764 && position_x_< 896) || (position_x_>1120 && position_y_>334) ||
    (position_y_>263 && position_y_<290 && position_x_>713 && position_x_<993) ||
    (position_y_>255 && position_y_<328 && position_x_>221 && position_x_<451) ||
    (position_y_<348 && position_y_>266 && position_x_>841 && position_x_<915) ||
    (position_y_>208 && position_y_<241 && position_x_<1034 && position_x_>987) ||
    (position_x_<243 && position_x_>218 && position_y_>184 && position_y_<429))
    position_x_ = position_x_ + (0.2*speed);
  else
    position_x_ = position_x_ + speed;
}

void Player::move_left()
{
  if (position_x_ < 80 || position_x_>1205 || position_y_ < 31 || position_y_ >550 ||
    (position_x_ > 227 && position_x_ < 356 && position_y_>249 && position_y_ < 385) ||
    (position_y_ > 438 && position_x_ > 521 && position_x_ < 744) ||
    (position_y_ > 211 && position_y_ < 275 && position_x_>246 && position_x_ < 671) ||
    (position_y_>493 && position_x_>439) || (position_y_>391 && position_x_> 1064) ||
    (position_y_<105 && position_x_>343 && position_x_<490) ||
    (position_y_<117 && position_x_> 764 && position_x_< 896) || (position_x_>1120 && position_y_>334) ||
    (position_y_>263 && position_y_<290 && position_x_>713 && position_x_<993) ||
    (position_y_>255 && position_y_<328 && position_x_>221 && position_x_<451) ||
    (position_y_<348 && position_y_>266 && position_x_>841 && position_x_<915) ||
    (position_y_>208 && position_y_<241 && position_x_<1034 && position_x_>987) ||
    (position_x_<243 && position_x_>218 && position_y_>184 && position_y_<429))
    position_x_ = position_x_ - (0.2*speed);
  else
    position_x_ = position_x_ - speed;
}

void Player::move_down()
{
  if (position_x_ < 80 || position_x_>1205 || position_y_ < 31 || position_y_ >550 ||
    (position_x_ > 227 && position_x_ < 356 && position_y_>249 && position_y_ < 385) ||
    (position_y_ > 438 && position_x_ > 521 && position_x_ < 744) ||
    (position_y_ > 211 && position_y_ < 275 && position_x_>246 && position_x_ < 671) ||
    (position_y_>493 && position_x_>439) || (position_y_>391 && position_x_> 1064) ||
    (position_y_<105 && position_x_>343 && position_x_<490) ||
    (position_y_<117 && position_x_> 764 && position_x_< 896) || (position_x_>1120 && position_y_>334) ||
    (position_y_>263 && position_y_<290 && position_x_>713 && position_x_<993) ||
    (position_y_>255 && position_y_<328 && position_x_>221 && position_x_<451) ||
    (position_y_<348 && position_y_>266 && position_x_>841 && position_x_<915) ||
    (position_y_>208 && position_y_<241 && position_x_<1034 && position_x_>987) ||
    (position_x_<243 && position_x_>218 && position_y_>184 && position_y_<429))
    position_y_ = position_y_ + (0.2*speed);
  else
    position_y_ = position_y_ + speed;
}
