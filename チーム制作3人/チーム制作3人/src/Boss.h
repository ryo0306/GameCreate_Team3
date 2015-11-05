#pragma once
#include "Struct.h"
#include "ScreenMake.h"

//------------------//
//     命名規則     //
//-----------------//
// ○ 関数
//
// ex) void GetPos(int pos_);
//
//----------------------------------
// ○ 変数
//
// ex) int object_num = 100;
//
//----------------------------------
// ○ 構造体
//
// ex) struct Status
//     {
//        int x;
//     }
//
//------------------------------------
// ○ enum&#define
//
// ex) #define WINDOW_WIDTH 500
// ex) enum Scene
//     {
//       TITLE.
//       MAIN,
//       RESULT
//     }
//
//---------------------------------------
// ○ ネスト
//
// ex) if(true)
//     {
//       //処理
//     }
//
//-----------------------------------------------------------------



// 番号順に関数を作る
// ネストが3つ以上になったら要相談
// 10分以上考えても分かんなかったら相談！
// これが必要じゃないかと思ったら相談！


//TODO:あたり判定はmapchipでする
//TODO:タイプまたは属性をつけるかどうか
//TODO:AIはplayerの位置を取得し状況
//     に応じて攻撃パターンを変える
//TODO:少なくてもパターンは3つ（予定）

class Boss
{
public:
  //1:コンストラクタ:ここで引数をもらい初期化する
	Boss();

  void SetUp();

  //2:playerの座標を登録
  void SetPlayerPos(Vec2i player1_pos_, Vec2i player2_pos_, Vec2i player3_pos_);

  //3:AI playerの位置によってパターンを変える
  void AI();

  //4:タイプによってスキルの攻撃力が変わる処理を作る
  void DamageCalculation();

  //５:受けるダメージを取得し計算をしてhpに反映
  void GivenDamege();

  //描写
  void Draw();

private:
  //Type type;
  Vec2i player_pos[3];     //  攻撃するときに見るプレイヤーのポジション
  Vec2i boss_pos;          //  位置
  Status boss_status;      //  ステータス
};