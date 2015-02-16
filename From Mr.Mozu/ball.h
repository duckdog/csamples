
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


// TIPS: �ŏ��ɂ��Ă� c �́Aclass �� c
class cBall {
  Random rand_;

  enum {
    BALL_MAX = 10,
  };

  // TIPS: �ǉ����ꂽ�v�f�������Ǖ`�悵�Ȃ��̂ŁAbool ���폜
  struct sBallData {
    Vec2f pos_;
    Vec2f speed_;
    Color color_;
  };
  //�z����R���e�i�̃��F�N�^�[�ŗp��.
  std::vector<sBallData> ball_;

public:
  cBall();

  void create(AppEnv& env);
  void addGravity();
  void update();
  void draw();
};
