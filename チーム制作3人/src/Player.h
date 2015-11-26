#pragma once
#include "Struct.h"
#include "ScreenMake.h"



//------------------//
//     �����K��     //
//-----------------//
// �� �֐�
//
// ex) void GetPos(int pos_);
//
//----------------------------------
// �� �ϐ�
//
// ex) int object_num = 100;
//
//----------------------------------
// �� �\����
//
// ex) struct Status
//     {
//        int x;
//     }
//
//------------------------------------
// �� enum&#define
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
// �� �l�X�g
//
// ex) if(true)
//     {
//       //����
//     }
//
//-----------------------------------------------------------------


// �ԍ����Ɋ֐������
// �l�X�g��3�ȏ�ɂȂ�����v���k
// 10���ȏ�l���Ă�������Ȃ������瑊�k�I
// ���ꂪ�K�v����Ȃ����Ǝv�����瑊�k�I


//TODO:enum�^�̈����Ń^�C�v���ς��悤�ɂ���
//TODO:�����蔻���mapchip�ł��(�ړ���)
//TODO:��_����������邩�ǂ���

//�ł�����
//�J�[�h�̎�ނ��擾���A���̃J�[�h�Ɉ�v����U��������
//ex)�����U��,�U�����@,�h�䖂�@


// �s���v�f
// �����蔻��
// �V���ɂ����蔻��pmapchip�����
// �v�Z����Ƃ��ɔ��肷��


class Player
{
public:
  //1:�R���X�g���N�^:�����ň��������炢����������
	Player(Type type){ size = MAPCHIP_SIZE; type = (Type)1; };
  //2:�^�C�v�Ŋ�{�X�e�[�^�X��ݒ�
  void SetUp(Type type,Vec2i player_pos);
  //3�@Draw
  void Draw();
  //4:�ړ�����(�ł���Ύ΂߂�)
  void Move(Vec2i mouse_pos_);

  //������͈͂�����
  void CheckMapRange();
  //5:�^����_���[�W���擾�ł���
  Damege GiveDamege();
  //7:�^�C�v�ɂ���ăX�L���̍U���͂��ς�鏈�������
  void DamageCalculation();

  void Calculation();

  //
  

  //�X�L���I��
  //void SkillSelect();
  //�X�L���I����Switch�̒��g
  //void SkillSelectKey(Skill next_skill);

  void SkillSelect();
  void DecisionSkill();
  void ChangeSkillRight();
  void ChangeSkillLeft();
  void DrawSkill();


  void Heal();
  void Defence();

  //6:�󂯂�_���[�W���擾���v�Z������hp�ɔ��f
  void GivenDamege(Damege damage_){ given_damage = damage_; };
  
  //�������I���������ǂ��� 
  //bool CheckFinished();

  //�^�C�v��I�ԏ���
  //������������Z���N�g�p�̃N���X�����ׂ��H
  void Select();


  //�^�C�v�ɂ���ĐF��ς���
  void ChangeColor(Type type);

  //  ���݂̏����̒i�K���m�F
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

  //�{�X�Əd�Ȃ��Ă��Ȃ����`�F�b�N����
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

  std::string skill_1 = "�h��";
  std::string skill_2 = "�U��";
  std::string skill_3 = "��";

  Color skill_color_1 = Color::blue;
  Color skill_color_2 = Color::red;
  Color skill_color_3 = Color::green;

  bool is_end = false;
  


};



//----------------------------------//
//         �S�̓I�ȗ���              //
//----------------------------------//
//
// �� �Q�[���X�^�[�g�I
//         
//---------------------------------------
//�@�@�@�@�@�@�v���C���[�^�[��
//---------------------------------------
//
// �� �v���C���[���^�C�v��I��
//         ��
// �� �v���C���[���ړ�����ʒu��I��
//         ��
// ��      �ړ�
//         ��
// �� ��������X�L����I��
//         ��
// ��      ����
//         ��
// ��   �_���[�W���Z
//         ��
// ��   �G�̃^�[����

//-----------------------------------------
//�@�@�@�@�@�@�G�l�~�[�^�[��
//-----------------------------------------

// �� �v���C���[�̈ʒu��⑫
//         ��
// �� ��������X�L����AI�Ō���
//         ��
// ��      ����
//         ��
// ��   �_���[�W���Z
//         ��
// ��   �v���C���[�̃^�[���ցi�^�C�v�I���܂��͈ړ��I���ցj





//----------------------------------------
//         �퓬�ȊO�̗���
//----------------------------------------

// ��    �^�C�g��
//         ��
// ��   *�Z�[�u�f�[�^�I���i�X�e�[�W�������Ȃ�����j
//         ��
// ��   *�X�e�[�W�Z���N�g
//         ��
// ��  �@ �Q�[��
//         ��
// �� ���U���g�i�ŒZ�^�[�����A*���j�b�g�̒ǉ��j
//         ��
// �� ���̃X�e�[�W���^�C�g���i�܂��̓Z���N�g�j��I��
//         ��
// �� ���[�v(�Q�[���܂��̓Z���N�g�܂��̓^�C�g����)

//* �͂ł�����܂��͖���̂���