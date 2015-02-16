
#pragma once
#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include "lib/random.hpp"
#include <ctime>
#include <vector>


enum Window {
  WIDTH = 512,
  HEIGHT = 512
};


// TIPS: 最初についてる c は、class の c
class cBall {
  Random rand_;

  enum {
    BALL_MAX = 10,
  };

  // TIPS: 追加された要素しか結局描画しないので、bool を削除
  struct sBallData {
    Vec2f pos_;
    Vec2f speed_;
    Color color_;
  };
  //配列をコンテナのヴェクターで用意.
  std::vector<sBallData> ball_;

public:
  cBall();

  void create(AppEnv& env);
  void addGravity();
  void update();
  void draw();
};
