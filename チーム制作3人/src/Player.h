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


//TODO:enum型の引数でタイプが変わるようにする
//TODO:あたり判定はmapchipでやる(移動も)
//TODO:弱点属性をいれるかどうか

//できたら
//カードの種類を取得し、そのカードに一致する攻撃をする
//ex)物理攻撃,攻撃魔法,防御魔法


// 不安要素
// あたり判定
// 新たにあたり判定用mapchipを作り
// 計算するときに判定する


class Player
{
public:
  //1:コンストラクタ:ここで引数をもらい初期化する
	Player(Type type){ size = MAPCHIP_SIZE; type = (Type)1; };

  //2:タイプで基本ステータスを設定
  void SetUp(Type type,Vec2i player_pos);
  //3　Draw
  void Draw();
  //4:移動処理(できれば斜めも)
  void Move();

  //動ける範囲を見る
  void CheckMapRange();
  //5:与えるダメージを取得できる
  Damege GiveDamege();
  //7:タイプによってスキルの攻撃力が変わる処理を作る
  void DamageCalculation();

  //6:受けるダメージを取得し計算をしてhpに反映
  void GivenDamege();
  
  //処理が終了したかどうか 
  //bool CheckFinished();

  //タイプを選ぶ処理
  //もしかしたらセレクト用のクラスを作るべき？
  bool Select(){};

  //  現在の処理の段階を確認
  Mode GetMode(){ return mode; }

private:
  Type type;
  Status basic_status;
  Mode  mode = Mode::TYPESELECT;
  Vec2i  pos;
  int    size;
  bool is_finish;
 
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