#pragma once
#ifndef MYGAME
#define MYGAME

#include "../Game.h"

class MyGame : public Game
{
public:
	//�R���X�g���N�^	
	MyGame(int width , int heigth);
	//MyGame�I�u�W�F�N�g�̏�����
	void Initialize(int width, int height) override;
	// ��{�Q�[�����[�v Basic game loop
	void Update(const DX::StepTimer& timer) override;
	// ��ʂ��N���A����
	void Clear() override;
	// �V�[����`��
	void Render(const DX::StepTimer& timer) override;
	// �o�b�N�o�b�t�@���X�N���[���ɑ���
	void Present() override;
	// �I������
	void Finalize() override;
private:
	//�L�[�{�[�h
	std::unique_ptr<Keyboard> keyboard;
	// �f�o�b�O�J���� DebugCamera
	std::unique_ptr<DebugCamera>	camera;
	// �O���b�h�t���A GridFloor
	std::unique_ptr<GridFloor> gridFloor;
	// ���f�� Model
	std::unique_ptr<Model> cup;
	// ���[���h world
	DirectX::SimpleMath::Matrix world;
	// �X�P�[�� scale
	float scale;
};
#endif //MYGAME
