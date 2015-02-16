
#include "ball.h"

//
// サンプル vector版
//

int main() {
  AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);
  cBall ball;

  while (env.isOpen()) {

	  ball.update();
    if (env.isPushButton(Mouse::LEFT)) {
		ball.create(env);
    }
	if (env.isPressKey('G')){
		ball.addGravity();
	}

    env.setupDraw();

    ball.draw();

    env.update();
  }
}
