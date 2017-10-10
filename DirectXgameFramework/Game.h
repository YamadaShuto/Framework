// Game.h

#pragma once
#ifndef GAME
#define GAME

#include <windows.h>
#include <iostream>
#include <string>
#include <iomanip>

#include <d3d11.h>
#include <SimpleMath.h>
#include <SpriteBatch.h>
#include <SpriteFont.h>
#include <Model.h>
#include <Keyboard.h>
#include <GeometricPrimitive.h>
#include <WICTextureLoader.h>
//**�ǉ���
#include <algorithm>
//**�ǉ���end

#include "StepTimer.h"
//**�ǉ���
//#include "dx.h"
//**�ǉ���end
#include "Window.h"
#include "Graphics.h"
#include "DebugCamera.h"
#include "Grid.h"

class Window;

// D3D11�f�o�C�X�𐶐����A�Q�[�����[�v��񋟂����{�Q�[������
// A basic game implementation that creates a D3D11 device and provides a game loop.
class Game
{
public:

	MSG Game::Run();
	//**�ǉ���
	// �R���X�g���N�^ Constructor
	//Game(HINSTANCE hInstance, int nCmdShow);
	Game(int width, int height);
	// �������ƊǗ� Initialization and management
    //void Initialize(int width, int height);
    virtual void Initialize(int width, int height);
	// ��{�Q�[�����[�v Basic game loop
	//MSG Update();
	virtual void Update(const DX::StepTimer& timer);
	// ��ʂ��N���A����
	virtual void Clear();
	// �V�[����`��
	virtual void Render(const DX::StepTimer& timer);
	// �o�b�N�o�b�t�@���X�N���[���ɑ���
	virtual void Present();
	// �I������
	//void Finalize();
	virtual void Finalize();
	//**�ǉ���end

    // ���b�Z�[�W Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // �v���p�e�B Properties
    void GetDefaultSize(int& width, int& height) const;

//private:
	// �Q�[�����X�V���� Update game
    //void Update(StepTimer const& timer);
    // �V�[����`�悷�� Render scene
	//void Render();
	// ��ʂ��N���A���� Clear screen
    //void Clear();
	// �o�b�N�o�b�t�@���X�N���[���ɑ���
    //void Present();
	// FPS��`�悷�� Draw FPS
	void DrawFPS();

private:
	HINSTANCE hInstance;
	int nCmdShow;
    // �f�o�C�X���\�[�X Device resources.
    HWND hWnd;
	// �o�͕� Output width
    int width;
	// �o�͍� Output height
    int height;

	// �E�B���h�E Window
	unique_ptr<Window> window;
	// �O���t�B�b�N�X Graphics
	unique_ptr<Graphics> graphics;
	// �@�\���x�� Feature level
    D3D_FEATURE_LEVEL featureLevel;
protected:
    // ���[�v�^�C�}�[��`�悷�� Rendering loop timer
    DX::StepTimer timer;

	// �L�[�{�[�h Keyboard
	//unique_ptr<Keyboard> keyboard;
	// �X�v���C�g�o�b�` SpriteBatch
	unique_ptr<SpriteBatch>	spriteBatch;
	// �f�o�b�O�J���� DebugCamera
	unique_ptr<DebugCamera>	camera;
	// �O���b�h�t���A GridFloor
	//unique_ptr<GridFloor> gridFloor;
	// �t�H���g Font
	unique_ptr<SpriteFont> font;

	// �G�t�F�N�g�t�@�N�g���C���^�[�t�F�[�X IEffectFactory
	unique_ptr<IEffectFactory> fxFactory;
	// �R�����X�e�[�g CommonStates
	unique_ptr<CommonStates> commonStates;
	// ���f�� Model
	//unique_ptr<Model> cup;
	// ���[���h world
	//DirectX::SimpleMath::Matrix world;
	// �X�P�[�� scale
	//float scale;

	//unique_ptr<GeometricPrimitive> box;

};

#endif	// GAME
