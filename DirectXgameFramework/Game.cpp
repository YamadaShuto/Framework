//
// Game.cpp
//

#include "pch.h"
#include "Game.h"

void ExitGame();

using namespace DirectX;
using namespace DX;
using Microsoft::WRL::ComPtr;


// �R���X�g���N�^ Constructor
Game::Game(int width, int heigth)
	: 
	hWnd(0), width(width), height(heigth), featureLevel(D3D_FEATURE_LEVEL_9_1) {

	//�X�^�[�g�A�b�v���
	STARTUPINFO si{};
	//�C���X�^���X�n���h���̎擾
	this->hInstance = ::GetModuleHandle(NULL);
	//STARTUPINFO�\���̂̓��e���擾����
	this->nCmdShow = si.dwFlags & STARTF_USESHOWWINDOW ? si.wShowWindow : SW_SHOWDEFAULT;
	
	// Window�I�u�W�F�N�g�𐶐�����
	this->window = std::make_unique<Window>(hInstance, nCmdShow);
	
}

MSG Game::Run()
{
	// ���C�����b�Z�[�W���[�v Main message loop
	MSG msg = { 0 };
	while (WM_QUIT != msg.message) {
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			// �Q�[�����X�V���� Update game
			this->timer.Tick([&]() { Update(this->timer); });
			// �V�[����`�悷�� Draw scene
			this->timer.Tick([&]() { Render(this->timer); });
		}
	}
	return msg;
}

// ���s�ɕK�v�ƂȂ�Direct3D���\�[�X������������
// Initialize the Direct3D resources required to run.
void Game::Initialize(int width, int height)
{

    this->width = std::max(width, 1);
    this->height = std::max(height, 1);

	// Window�I�u�W�F�N�g������������
	window->Initialize(this->width, this->height);
	//�E�B���h�E�n���h�����擾����
    this->hWnd = this->window->HWnd();

	auto& graphics = Graphics::Get();

	graphics.HWnd(this->hWnd);
	graphics.Width(this->width);
	graphics.Height(this->height);

	// �f�o�C�X�𐶐����� Create Device
	graphics.CreateDevice();
	// ���\�[�X�𐶐����� Create Resources
	graphics.CreateResources();

    // TODO: �f�t�H���g�ϐ�timestep���[�h�ȊO�̂��̂��K�v�ȏꍇ�^�C�}�[�ݒ��ύX����
	// �Ⴆ�� 60 FPS�Œ�^�C���X�e�b�v�X�V���W�b�N�ɑ΂��Ă͈ȉ����Ăяo��
	// Change the timer settings if you want something other than the default variable timestep mode.
    // e.g. for 60 FPS fixed timestep update logic, call:
    
    // this->timer.SetFixedTimeStep(true);
    // this->timer.SetTargetElapsedSeconds(1.0 / 60);

	// Keyboard�I�u�W�F�N�g�𐶐����� Create Keyboard object
	//this->keyboard = std::make_unique<Keyboard>();

	// DebugCamera�I�u�W�F�N�g�𐶐����� Create DebugCamera object
	//this->camera = std::make_unique<DebugCamera>(this->outputWidth, this->outputHeight);
	
	// SpriteBatch�I�u�W�F�N�g�𐶐����� Create SpriteBatch object
	this->spriteBatch = std::make_unique<SpriteBatch>(graphics.Context().Get());
	// GridFloor�I�u�W�F�N�g�𐶐����� Create GridFloor object
	//this->gridFloor = std::make_unique<GridFloor>(graphics.Device(), graphics.Context(), 20.0f, 20);
	// Font�I�u�W�F�N�g�𐶐����� Create Font object
	this->font = std::make_unique<SpriteFont>(graphics.Device().Get(), L"myfile.spritefont");

	// CommonStates�𐶐����� Create CommonState object
	this->commonStates = std::make_unique<CommonStates>(graphics.Device().Get());
	// EffectFactory�I�u�W�F�N�g�𐶐�����
	this->fxFactory = std::make_unique<EffectFactory>(graphics.Device().Get());
	// CMO�t�@�C������I�u�W�F�N�g�𐶐����� Create from CMO
	//this->cup = Model::CreateFromCMO(graphics.Device().Get(), L"cup.cmo", *this->fxFactory);

	//this->box = GeometricPrimitive::CreateBox(graphics.Context().Get(), XMFLOAT3(10, 10, 10), true, true);
}

// �I������
void Game::Finalize() 
{
	//EffectFactry�I�u�W�F�N�g�����Z�b�g����
	this->fxFactory.reset();
	//CommonState�����Z�b�g����
	this->commonStates.reset();
	//Font�I�u�W�F�N�g�����Z�b�g
	this->font.reset();
	//SpriteBatch�I�u�W�F�N�g�����Z�b�g
	this->spriteBatch.reset();
	//Graphics�I�u�W�F�N�g�̃f�B�X�|�[�Y

	// Window�I�u�W�F�N�g��j������
	window.reset();
}

//
void Game::Update(const StepTimer& timer)
{
 //   float elapsedTime = float(timer.GetElapsedSeconds());

 //   // TODO: �Q�[�����W�b�N��ǉ����� Add your game logic here
	//auto keyboard = this->keyboard->GetState();

	//if (keyboard.Right)
	//	scale += 0.1f;

	//if (keyboard.Left)
	//	scale -= 0.1f;

	//// �J�������X�V���� Update camera
	//this->camera->Update();
}

// �V�[����`�悷�� Draws the scene
void Game::Render(const StepTimer& timer)
{
 //   // �ŏ��̍X�V�̑O�͉����`�悵�Ȃ��悤�ɂ���
	//// Don't try to render anything before the first Update.
 //   if (this->timer.GetFrameCount() == 0) {
 //       return;
 //   }

 //   Clear();

 //   // TODO: �����_�����O�R�[�h��ǉ����� Add your rendering code here

	//this->spriteBatch->Begin();

	//// �J�����s����X�V����
	//SimpleMath::Matrix view = this->camera->GetCameraMatrix();
	//// �ˉe�s������
	//SimpleMath::Matrix projection = SimpleMath::Matrix::CreatePerspectiveFieldOfView(
	//	DirectX::XMConvertToDegrees(60.0f),
	//	(float)this->outputWidth / (float)this->outputHeight, 
	//	1.0f, 
	//	100.0f);
	//// �O���b�h��`�悷��
	//this->gridFloor->Render(view, projection);

	//// FPS��`�悷��
	//DrawFPS();
	//// ���[���h�s�������������
	//DirectX::SimpleMath::Matrix world = DirectX::SimpleMath::Matrix::Identity;
	//// �X�P�[����ύX���� Change scale
	//world = SimpleMath::Matrix::CreateScale(scale);
	//// ���f����`�悷�� Draw model
	//this->cup->Draw(Graphics::Get().Context().Get(), *this->commonStates, world, view, projection);

	//this->spriteBatch->End();

 //   Present();
}

// FPS��`�悷�� Draw FPS
void Game::DrawFPS() 
{
	// FPS������𐶐����� Create FPS string
	wstring fpsString = L"fps = " + std::to_wstring((unsigned int)this->timer.GetFramesPerSecond());
	// FPS��`�悷�� Draw FPS
	this->font->DrawString(spriteBatch.get(), fpsString.c_str(), SimpleMath::Vector2(0, 0), Colors::White);
}

// �o�b�N�o�b�t�@���N���A���邽�߂̃w���p�[�֐� Helper method to clear the back buffers
void Game::Clear()
{
    // Graphics�N���X�̃C���X�^���X���擾����
	auto& graphics = Graphics::Get();
	// �����_�[�^�[�Q�b�g���N���A���� Clear Render target view
	graphics.Context()->ClearRenderTargetView(graphics.RenderTargetView().Get(), Colors::Black);
	// �f�v�X�X�e���V���r���[��ݒ肷�� Set depth stencil view
	graphics.Context()->ClearDepthStencilView(graphics.DepthStencilView().Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
	// �����_�[�^�b�Q�[�g��ݒ肷�� Set render target
	graphics.Context()->OMSetRenderTargets(1, graphics.RenderTargetView().GetAddressOf(), graphics.DepthStencilView().Get());
    // �r���[�|�[�g��ݒ肷�� Set viewport
    CD3D11_VIEWPORT viewport(0.0f, 0.0f, static_cast<float>(this->width), static_cast<float>(this->height));
	graphics.Context()->RSSetViewports(1, &viewport);
}

// �o�b�N�o�b�t�@���X�N���[���ɑ��� Presents the back buffer contents to the screen
void Game::Present()
{
    // The first argument instructs DXGI to block until VSync, putting the application
    // to sleep until the next VSync. This ensures we don't waste any cycles rendering
    // frames that will never be displayed to the screen.

	// Graphics�N���X�̃C���X�^���X���擾����
	auto& graphics = Graphics::Get();
	HRESULT hr = graphics.SwapChain()->Present(1, 0);

    // �f�o�C�X�����Z�b�g���ꂽ�ꍇ�����_�����ď���������K�v������ 
	// If the device was reset we must completely reinitialize the renderer
    if (hr == DXGI_ERROR_DEVICE_REMOVED || hr == DXGI_ERROR_DEVICE_RESET) {
		graphics.OnDeviceLost();
    }
    else {
        ThrowIfFailed(hr);
    }
}

// ���b�Z�[�W�n���h�� Message handlers
void Game::OnActivated()
{
    // TODO: �Q�[�����A�N�e�B�u�ȃE�B���h�E�ɂȂ� Game is becoming active window.
}

void Game::OnDeactivated()
{
    // TODO: �Q�[�����o�b�N�O���E���h�E�B���h�E�ɂȂ� Game is becoming background window.
}

void Game::OnSuspending()
{
    // TODO: �Q�[�����p���[�T�X�y���f�b�h�ɂȂ� Game is being power-suspended (or minimized).
}

void Game::OnResuming()
{
	this->timer.ResetElapsedTime();

    // TODO: �Q�[�����p���[���W���[���ɂȂ� Game is being power-resumed (or returning from minimize).
}

void Game::OnWindowSizeChanged(int width, int height)
{
    this->width = std::max(width, 1);
    this->height = std::max(height, 1);
	
	Graphics::Get().CreateResources();
    // TODO: �Q�[���E�B���h�E�̃T�C�Y���ĕύX����� Game window is being resized.
}

// �v���p�e�B Properties
void Game::GetDefaultSize(int& width, int& height) const
{
    // TODO: �C�ӂ̃f�t�H���g�E�B���h�E�T�C�Y�ɕύX����(�ŏ��T�C�Y��320x200) 
	// Change to desired default window size (note minimum size is 320x200).
    width = 800;
    height = 600;
}

// Exit�w���p�[�֐� Exit helper
void ExitGame() {
	PostQuitMessage(0);
}