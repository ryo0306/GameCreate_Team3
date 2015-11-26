#pragma once
#include "ScreenMake.h"

class AttackPatternBase
{
public:
  virtual int GetMapData(int x, int y){ return 0; };

  virtual Vec2i GetSize(){ return Vec2i(0, 0); }

  virtual Vec2i GetPos(Vec2i pos_){ return pos_; }

private:


};

// 方向変換
// スキル選択画面
// タイトル
// リザルト
// 三体作った時にどれを操作しているか選択できるようにする
// コンストラクタで初期位置を設定するようにする。
// あたり判定内に入っていればダメージをくらう
// 方向を変えれるようにする
// ボスをよけていくようにする。（ボスに重ならないように）

// できれば
// 画面を一つ戻れるようにする。
