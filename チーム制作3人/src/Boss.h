#pragma once
#include "Struct.h"
#include "ScreenMake.h"
#include <ctime>
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


//TODO:�����蔻���mapchip�ł���
//TODO:�^�C�v�܂��͑��������邩�ǂ���
//TODO:AI��player�̈ʒu���擾����
//     �ɉ����čU���p�^�[����ς���
//TODO:���Ȃ��Ă��p�^�[����3�i�\��j

class Boss
{
public:
  //1:�R���X�g���N�^:�����ň��������炢����������
	Boss();

  void SetUp(Vec2i def_pos_);

  //2:player�̍��W��o�^
  void SetPlayerPos(Vec2i player1_pos_, Vec2i player2_pos_, Vec2i player3_pos_);

  //3:AI player�̈ʒu�ɂ���ăp�^�[����ς���
  void AI();

  void DamageCalculation();

  //�^����_���[�W���擾���v�Z������
  Damege GiveDamage();

  //�T:�󂯂�_���[�W���擾���v�Z������hp�ɔ��f
  void GivenDamage(Damege damage_){ given_damage = damage_; };

  //�`��
  void Draw();

  void ModeChange(Mode next_);

  Mode GetMode(){ return mode; }

  //����:for����3*3���
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
  Vec2i player_pos[3];     //  �U������Ƃ��Ɍ���v���C���[�̃|�W�V����
  Vec2i pos[3][3];            //  �ʒu
  Status basic_status;      //  �X�e�[�^�X
  Mode mode = Mode::TYPESELECT;               //  ���݂̏��
  Damege damege;
  Damege give_damage;
  Damege given_damage;
  //DEBUG
  Color boss_color;        //�{�X�̐F
  Random rand;
  
  int player_num = 0;
  //�{�X�̍U���p�^�[��
  enum Boss_type
  {
	  STRAIGHT,
	  BACK,
	  LEFT,
	  RIGHT,
	  ALL
  };
  Boss_type boss_type;
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