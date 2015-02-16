
#include "ball.h"

typedef cBall  ball;


cBall::cBall() {

  // �����̏�����
  rand_.setSeed(u_int(time(nullptr)));
}


// TIPS: �N���b�N���ꂽ��{�[����\��
void ball::create(AppEnv &env) {

  // TIPS: �P�O�ȏ�͕\�����Ȃ�
  //if (ball_.size() >= BALL_MAX) { return; }

  // TIPS: ���̃f�[�^��p��
  sBallData temp;

  temp.pos_ = env.mousePosition();

  temp.speed_.x() = rand_.fromFirstToLast(-3.0f, 3.0f);
  temp.speed_.y() = rand_.fromFirstToLast(-3.0f, 3.0f);

  temp.color_.red() = rand_.fromFirstToLast(0.25f, 1.0f);
  temp.color_.blue() = rand_.fromFirstToLast(0.25f, 1.0f);
  temp.color_.green() = rand_.fromFirstToLast(0.25f, 1.0f);

  // TIPS: �z��ɗp�ӂ������f�[�^��������
  ball_.push_back(temp);
}


// �{�[���̍X�V
void ball::update() {

  // TIPS: �R���e�i������ۂȂ珈�����X�L�b�v
  if (ball_.empty()) { return; }

  // TIPS: ��ʒ[�̏��
  // FIXME: ���������������@�����肻���ȋC������
  const float leftEdge = -WIDTH / 2;
  const float rightEdge = WIDTH / 2;
  const float topEdge = HEIGHT / 2;
  const float bottomEdge = -HEIGHT / 2;

  // TIPS: �R���e�i�ɂ��g����
  for (auto& it : ball_) {
    it.pos_.x() += it.speed_.x();
    it.pos_.y() += it.speed_.y();

    // TIPS: ��ʒ[�i�������j
    if (it.pos_.x() < leftEdge || it.pos_.x() > rightEdge) {

      // TIPS: ��ʒ[�ƌ��݂̈ʒu���r�A
      // * ���[��菬������΍��[�ɖ߂� (std::max())
      // * �E�[���傫����ΉE�[�ɖ߂� (std::min())
      it.pos_.x() =
        std::min(rightEdge,
        std::max(it.pos_.x(), leftEdge));

      // * ���ꂼ��A��r�������ʁA�傫���ق��A�������ق���Ԃ�
      // * ���[��菬���� = �����ɂ͂ݏo�� = ���[���u�傫���v
      // * �E�[���傫�� = �E���ɂ͂ݏo�� = �E�[���u�������v
      // * ��₱�������ǁA�g�����Ȃ���Ε֗��Ȋ֐��Ȃ̂ŁA
      // * ���Њo���Ă�����

      // * ���Ȃ݂ɁA�搶�̃T���v���Acamera �ł��g�p���Ă���

      // TIPS: ���˂̏���
      it.speed_.x() *= -1;
    }

    // TIPS: ��ʒ[�i�������j
    if (it.pos_.y() < bottomEdge || it.pos_.y() > topEdge) {

      // TIPS: ��ɓ���
      it.pos_.y() =
        std::min(topEdge,
        std::max(it.pos_.y(), bottomEdge));

      it.speed_.y() *= -1;
    }
  }
}

void ball::addGravity(){

	// TIPS: �R���e�i������ۂȂ珈�����X�L�b�v
	if (ball_.empty()) { return; }
	
	//TIPS: �d�͂�������.
	for (auto& it : ball_){
		const float g = 1.0f;
		it.speed_.y() += -g;
	}
}


void ball::draw() {

  

  // TIPS: �R���e�i�ɂ��g����
  // * �l�͏��������Ȃ����A�R�s�[�Ń��������g���̂ŎQ��
  for (const auto& it : ball_) {
    drawFillCircle(it.pos_.x(), it.pos_.y(),
                   10, 10, 20, it.color_);
  }
}
