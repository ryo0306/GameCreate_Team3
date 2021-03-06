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
  void Move(Vec2i mouse_pos_);

  //動ける範囲を見る
  void CheckMapRange();
  //5:与えるダメージを取得できる
  Damege GiveDamege();
  //7:タイプによってスキルの攻撃力が変わる処理を作る
  void DamageCalculation();

  void Calculation();

  //
  

  //スキル選択
  //void SkillSelect();
  //スキル選択のSwitchの中身
  //void SkillSelectKey(Skill next_skill);

  void SkillSelect();
  void DecisionSkill();
  void ChangeSkillRight();
  void ChangeSkillLeft();
  void DrawSkill();


  void Heal();
  void Defence();

  //6:受けるダメージを取得し計算をしてhpに反映
  void GivenDamege(Damege damage_){ given_damage = damage_; };
  
  //処理が終了したかどうか 
  //bool CheckFinished();

  //タイプを選ぶ処理
  //もしかしたらセレクト用のクラスを作るべき？
  void Select();


  //タイプによって色を変える
  void ChangeColor(Type type);

  //  現在の処理の段階を確認
  Mode GetMode(){ return mode; }

  void ModeChange(Mode next_);

  Vec2i GetPos(){ return pos; }

  int GetAttackPattern(){ return attack_pattern; }

  bool IsEnd(){ return is_end; }

  void SetBossPos( Vec2i boss_pos_ = Vec2i(4,10)){
	  int k = 0;
	  for (int i = 0; i < 3; i++)
	  {
		  for (int j = 0; j < 3; j++)
		  {
			  boss_pos[k] = Vec2i(boss_pos_.x() + i, boss_pos_.y() + j);
			  k++;
		  }
	  }
  }

  //ボスと重なっていないかチェックする
  bool CheckCanMove(Vec2i mouse_pos);

private:


  Type type;
  Status basic_status;
  Mode  mode = Mode::TYPESELECT;
  Vec2i  pos;
  int    size;
  bool is_finish;
  int attack_pattern = 0;
  Color color = Color::black;
  Vec2i next_move_position;
  Font font_p = Font("res/meiryo.ttc");
  Vec2i move_count;

  Vec2f skill_select_point;
  Skill skill=ATTACK;
  Skill next_skill;

  Vec2i  boss_pos[9];

  Damege damage;
  Damege give_damage;
  Damege given_damage;
  int skill_attack =100;
  Vec2f skill_pos =Vec2f(0,0);

  std::string skill_1 = "防御";
  std::string skill_2 = "攻撃";
  std::string skill_3 = "回復";

  Color skill_color_1 = Color::blue;
  Color skill_color_2 = Color::red;
  Color skill_color_3 = Color::green;

  bool is_end = false;
  


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