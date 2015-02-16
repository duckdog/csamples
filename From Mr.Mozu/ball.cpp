
#include "ball.h"

typedef cBall  ball;


cBall::cBall() {

  // 乱数の初期化
  rand_.setSeed(u_int(time(nullptr)));
}


// TIPS: クリックされたらボールを表示
void ball::create(AppEnv &env) {

  // TIPS: １０個以上は表示しない
  //if (ball_.size() >= BALL_MAX) { return; }

  // TIPS: 仮のデータを用意
  sBallData temp;

  temp.pos_ = env.mousePosition();

  temp.speed_.x() = rand_.fromFirstToLast(-3.0f, 3.0f);
  temp.speed_.y() = rand_.fromFirstToLast(-3.0f, 3.0f);

  temp.color_.red() = rand_.fromFirstToLast(0.25f, 1.0f);
  temp.color_.blue() = rand_.fromFirstToLast(0.25f, 1.0f);
  temp.color_.green() = rand_.fromFirstToLast(0.25f, 1.0f);

  // TIPS: 配列に用意した仮データをつっこむ
  ball_.push_back(temp);
}


// ボールの更新
void ball::update() {

  // TIPS: コンテナが空っぽなら処理をスキップ
  if (ball_.empty()) { return; }

  // TIPS: 画面端の情報
  // FIXME: もう少しいい方法がありそうな気がする
  const float leftEdge = -WIDTH / 2;
  const float rightEdge = WIDTH / 2;
  const float topEdge = HEIGHT / 2;
  const float bottomEdge = -HEIGHT / 2;

  // TIPS: コンテナにも使える
  for (auto& it : ball_) {
    it.pos_.x() += it.speed_.x();
    it.pos_.y() += it.speed_.y();

    // TIPS: 画面端（ｘ方向）
    if (it.pos_.x() < leftEdge || it.pos_.x() > rightEdge) {

      // TIPS: 画面端と現在の位置を比較、
      // * 左端より小さければ左端に戻す (std::max())
      // * 右端より大きければ右端に戻す (std::min())
      it.pos_.x() =
        std::min(rightEdge,
        std::max(it.pos_.x(), leftEdge));

      // * それぞれ、比較した結果、大きいほう、小さいほうを返す
      // * 左端より小さい = 左側にはみ出る = 左端が「大きい」
      // * 右端より大きい = 右側にはみ出る = 右端が「小さい」
      // * ややこしいけど、使いこなせれば便利な関数なので、
      // * ぜひ覚えておこう

      // * ちなみに、先生のサンプル、camera でも使用している

      // TIPS: 反射の処理
      it.speed_.x() *= -1;
    }

    // TIPS: 画面端（ｙ方向）
    if (it.pos_.y() < bottomEdge || it.pos_.y() > topEdge) {

      // TIPS: 上に同じ
      it.pos_.y() =
        std::min(topEdge,
        std::max(it.pos_.y(), bottomEdge));

      it.speed_.y() *= -1;
    }
  }
}

void ball::addGravity(){

	// TIPS: コンテナが空っぽなら処理をスキップ
	if (ball_.empty()) { return; }
	
	//TIPS: 重力を加える.
	for (auto& it : ball_){
		const float g = 1.0f;
		it.speed_.y() += -g;
	}
}


void ball::draw() {

  

  // TIPS: コンテナにも使える
  // * 値は書き換えないが、コピーでメモリを使うので参照
  for (const auto& it : ball_) {
    drawFillCircle(it.pos_.x(), it.pos_.y(),
                   10, 10, 20, it.color_);
  }
}
