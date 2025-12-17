#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

//window
constexpr unsigned int kWindowWidth = 800;//using unsigned as videoMode() function takes unsigned int as parameters
constexpr unsigned int kWindowHeight = 600;

//player
constexpr float kPlayerWidth = 50.f;
constexpr float kPlayerHeight = 100.f;
constexpr float kPlayerSpeed=200.f;
constexpr float kGravity =  1200.f;
constexpr float kJumpSpeed = 600.f;
constexpr int kPlayerHealth = 100;

//enemy
constexpr float kEnemyWidth = 80;
constexpr float kEnemyHeight = 150;
constexpr int kEnemyHealth = 50;
constexpr int kAttackDamage = 5;

#endif