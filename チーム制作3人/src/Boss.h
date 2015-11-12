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

  void SetUp(Vec2i def_pos_);

  //2:playerの座標を登録
  void SetPlayerPos(Vec2i player1_pos_, Vec2i player2_pos_, Vec2i player3_pos_);

  //3:AI playerの位置によってパターンを変える
  void AI();

  //4:タイプによってスキルの攻撃力が変わる処理を作る
  void DamageCalculation();

  //与えるダメージを取得し計算をする
  void GiveDamage();

  //５:受けるダメージを取得し計算をしてhpに反映
  void GivenDamage();

  //描写
  void Draw();

  void ModeChange();

  Mode GetMode(){ return mode; }

  //注意:for文を9回回す
  Vec2i GetPos(int x, int y)
  {
	  return pos[x][y];
  };

  void SetPos(Vec2i def_pos_)
  {
	  for (int x = 0; x < 3; x++)
	  {
		  for (int y = 0; y < 3; y++)
		  {
			  pos[x][y] = Vec2i(def_pos_.x() + x, def_pos_.y() + y);
		  }
	  }
  }

  private:
  //Type type;
  Vec2i player_pos[3];     //  攻撃するときに見るプレイヤーのポジション
  Vec2i pos[3][3];            //  位置
  Status boss_status;      //  ステータス
  Mode mode = Mode::TYPESELECT;               //  現在の状態
  Damege damege;
  //DEBUG
  Color boss_color;        //ボスの色
};




//----------------------------------//
//         全体的な流れ              //
//----------------------------------//
//
// ○ ゲームスタート！
//         
//---------------------------------------
//　　　　　　プレイヤーターン
//---------------------------------------
//
// ○ プレイヤーがタイプを選択
//         ↓
// ○ プレイヤーが移動する位置を選択
//         ↓
// ○      移動
//         ↓
// ○ 発動するスキルを選択
//         ↓
// ○      発動
//         ↓
// ○   ダメージ演算
//         ↓
// ○   敵のターンへ

//-----------------------------------------
//　　　　　　エネミーターン
//-----------------------------------------

// ○ プレイヤーの位置を補足
//         ↓
// ○ 発動するスキルをAIで決定
//         ↓
// ○      発動
//         ↓
// ○   ダメージ演算
//         ↓
// ○   プレイヤーのターンへ（タイプ選択または移動選択へ）





//----------------------------------------
//         戦闘以外の流れ
//----------------------------------------

// ○    タイトル
//         ↓
// ○   *セーブデータ選択（ステージが多くなったら）
//         ↓
// ○   *ステージセレクト
//         ↓
// ○  　 ゲーム
//         ↓
// ○ リザルト（最短ターン数、*ユニットの追加）
//         ↓
// ○ 次のステージかタイトル（またはセレクト）を選ぶ
//         ↓
// ○ ループ(ゲームまたはセレクトまたはタイトルへ)

//* はできたらまたは未定のもの