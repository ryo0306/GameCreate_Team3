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

// �����ϊ�
// �X�L���I�����
// �^�C�g��
// ���U���g
// �O�̍�������ɂǂ�𑀍삵�Ă��邩�I���ł���悤�ɂ���
// �R���X�g���N�^�ŏ����ʒu��ݒ肷��悤�ɂ���B
// �����蔻����ɓ����Ă���΃_���[�W�����炤
// ������ς����悤�ɂ���
// �{�X���悯�Ă����悤�ɂ���B�i�{�X�ɏd�Ȃ�Ȃ��悤�Ɂj

// �ł����
// ��ʂ���߂��悤�ɂ���B
