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

  void SetUp();

  //2:player�̍��W��o�^
  void SetPlayerPos(Vec2i player1_pos_, Vec2i player2_pos_, Vec2i player3_pos_);

  //3:AI player�̈ʒu�ɂ���ăp�^�[����ς���
  void AI();

  //4:�^�C�v�ɂ���ăX�L���̍U���͂��ς�鏈�������
  void DamageCalculation();

  //�T:�󂯂�_���[�W���擾���v�Z������hp�ɔ��f
  void GivenDamege();

  //�`��
  void Draw();

private:
  //Type type;
  Vec2i player_pos[3];     //  �U������Ƃ��Ɍ���v���C���[�̃|�W�V����
  Vec2i boss_pos;          //  �ʒu
  Status boss_status;      //  �X�e�[�^�X
};