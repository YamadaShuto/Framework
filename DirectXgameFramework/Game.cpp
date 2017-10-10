//
// Game.cpp
//

#include "pch.h"
#include "Game.h"

void ExitGame();

using namespace DirectX;
using namespace DX;
using Microsoft::WRL::ComPtr;


// コンストラクタ Constructor
Game::Game(int width, int heigth)
	: 
	hWnd(0), width(width), height(heigth), featureLevel(D3D_FEATURE_LEVEL_9_1) {

	//スタートアップ情報
	STARTUPINFO si{};
	//インスタンスハンドルの取得
	this->hInstance = ::GetModuleHandle(NULL);
	//STARTUPINFO構造体の内容を取得する
	this->nCmdShow = si.dwFlags & STARTF_USESHOWWINDOW ? si.wShowWindow : SW_SHOWDEFAULT;
	
	// Windowオブジェクトを生成する
	this->window = std::make_unique<Window>(hInstance, nCmdShow);
	
}

MSG Game::Run()
{
	// メインメッセージループ Main message loop
	MSG msg = { 0 };
	while (WM_QUIT != msg.message) {
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			// ゲームを更新する Update game
			this->timer.Tick([&]() { Update(this->timer); });
			// シーンを描画する Draw scene
			this->timer.Tick([&]() { Render(this->timer); });
		}
	}
	return msg;
}

// 実行に必要となるDirect3Dリソースを初期化する
// Initialize the Direct3D resources required to run.
void Game::Initialize(int width, int height)
{

    this->width = std::max(width, 1);
    this->height = std::max(height, 1);

	// Windowオブジェクトを初期化する
	window->Initialize(this->width, this->height);
	//ウィンドウハンドルを取得する
    this->hWnd = this->window->HWnd();

	auto& graphics = Graphics::Get();

	graphics.HWnd(this->hWnd);
	graphics.Width(this->width);
	graphics.Height(this->height);

	// デバイスを生成する Create Device
	graphics.CreateDevice();
	// リソースを生成する Create Resources
	graphics.CreateResources();

    // TODO: デフォルト変数timestepモード以外のものが必要な場合タイマー設定を変更する
	// 例えば 60 FPS固定タイムステップ更新ロジックに対しては以下を呼び出す
	// Change the timer settings if you want something other than the default variable timestep mode.
    // e.g. for 60 FPS fixed timestep update logic, call:
    
    // this->timer.SetFixedTimeStep(true);
    // this->timer.SetTargetElapsedSeconds(1.0 / 60);

	// Keyboardオブジェクトを生成する Create Keyboard object
	//this->keyboard = std::make_unique<Keyboard>();

	// DebugCameraオブジェクトを生成する Create DebugCamera object
	//this->camera = std::make_unique<DebugCamera>(this->outputWidth, this->outputHeight);
	
	// SpriteBatchオブジェクトを生成する Create SpriteBatch object
	this->spriteBatch = std::make_unique<SpriteBatch>(graphics.Context().Get());
	// GridFloorオブジェクトを生成する Create GridFloor object
	//this->gridFloor = std::make_unique<GridFloor>(graphics.Device(), graphics.Context(), 20.0f, 20);
	// Fontオブジェクトを生成する Create Font object
	this->font = std::make_unique<SpriteFont>(graphics.Device().Get(), L"myfile.spritefont");

	// CommonStatesを生成する Create CommonState object
	this->commonStates = std::make_unique<CommonStates>(graphics.Device().Get());
	// EffectFactoryオブジェクトを生成する
	this->fxFactory = std::make_unique<EffectFactory>(graphics.Device().Get());
	// CMOファイルからオブジェクトを生成する Create from CMO
	//this->cup = Model::CreateFromCMO(graphics.Device().Get(), L"cup.cmo", *this->fxFactory);

	//this->box = GeometricPrimitive::CreateBox(graphics.Context().Get(), XMFLOAT3(10, 10, 10), true, true);
}

// 終了処理
void Game::Finalize() 
{
	//EffectFactryオブジェクトをリセットする
	this->fxFactory.reset();
	//CommonStateをリセットする
	this->commonStates.reset();
	//Fontオブジェクトをリセット
	this->font.reset();
	//SpriteBatchオブジェクトをリセット
	this->spriteBatch.reset();
	//Graphicsオブジェクトのディスポーズ

	// Windowオブジェクトを破棄する
	window.reset();
}

//
void Game::Update(const StepTimer& timer)
{
 //   float elapsedTime = float(timer.GetElapsedSeconds());

 //   // TODO: ゲームロジックを追加する Add your game logic here
	//auto keyboard = this->keyboard->GetState();

	//if (keyboard.Right)
	//	scale += 0.1f;

	//if (keyboard.Left)
	//	scale -= 0.1f;

	//// カメラを更新する Update camera
	//this->camera->Update();
}

// シーンを描画する Draws the scene
void Game::Render(const StepTimer& timer)
{
 //   // 最初の更新の前は何も描画しないようにする
	//// Don't try to render anything before the first Update.
 //   if (this->timer.GetFrameCount() == 0) {
 //       return;
 //   }

 //   Clear();

 //   // TODO: レンダリングコードを追加する Add your rendering code here

	//this->spriteBatch->Begin();

	//// カメラ行列を更新する
	//SimpleMath::Matrix view = this->camera->GetCameraMatrix();
	//// 射影行列を作る
	//SimpleMath::Matrix projection = SimpleMath::Matrix::CreatePerspectiveFieldOfView(
	//	DirectX::XMConvertToDegrees(60.0f),
	//	(float)this->outputWidth / (float)this->outputHeight, 
	//	1.0f, 
	//	100.0f);
	//// グリッドを描画する
	//this->gridFloor->Render(view, projection);

	//// FPSを描画する
	//DrawFPS();
	//// ワールド行列を初期化する
	//DirectX::SimpleMath::Matrix world = DirectX::SimpleMath::Matrix::Identity;
	//// スケールを変更する Change scale
	//world = SimpleMath::Matrix::CreateScale(scale);
	//// モデルを描画する Draw model
	//this->cup->Draw(Graphics::Get().Context().Get(), *this->commonStates, world, view, projection);

	//this->spriteBatch->End();

 //   Present();
}

// FPSを描画する Draw FPS
void Game::DrawFPS() 
{
	// FPS文字列を生成する Create FPS string
	wstring fpsString = L"fps = " + std::to_wstring((unsigned int)this->timer.GetFramesPerSecond());
	// FPSを描画する Draw FPS
	this->font->DrawString(spriteBatch.get(), fpsString.c_str(), SimpleMath::Vector2(0, 0), Colors::White);
}

// バックバッファをクリアするためのヘルパー関数 Helper method to clear the back buffers
void Game::Clear()
{
    // Graphicsクラスのインスタンスを取得する
	auto& graphics = Graphics::Get();
	// レンダーターゲットをクリアする Clear Render target view
	graphics.Context()->ClearRenderTargetView(graphics.RenderTargetView().Get(), Colors::Black);
	// デプスステンシルビューを設定する Set depth stencil view
	graphics.Context()->ClearDepthStencilView(graphics.DepthStencilView().Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
	// レンダータッゲートを設定する Set render target
	graphics.Context()->OMSetRenderTargets(1, graphics.RenderTargetView().GetAddressOf(), graphics.DepthStencilView().Get());
    // ビューポートを設定する Set viewport
    CD3D11_VIEWPORT viewport(0.0f, 0.0f, static_cast<float>(this->width), static_cast<float>(this->height));
	graphics.Context()->RSSetViewports(1, &viewport);
}

// バックバッファをスクリーンに送る Presents the back buffer contents to the screen
void Game::Present()
{
    // The first argument instructs DXGI to block until VSync, putting the application
    // to sleep until the next VSync. This ensures we don't waste any cycles rendering
    // frames that will never be displayed to the screen.

	// Graphicsクラスのインスタンスを取得する
	auto& graphics = Graphics::Get();
	HRESULT hr = graphics.SwapChain()->Present(1, 0);

    // デバイスがリセットされた場合レンダラを再初期化する必要がある 
	// If the device was reset we must completely reinitialize the renderer
    if (hr == DXGI_ERROR_DEVICE_REMOVED || hr == DXGI_ERROR_DEVICE_RESET) {
		graphics.OnDeviceLost();
    }
    else {
        ThrowIfFailed(hr);
    }
}

// メッセージハンドラ Message handlers
void Game::OnActivated()
{
    // TODO: ゲームがアクティブなウィンドウになる Game is becoming active window.
}

void Game::OnDeactivated()
{
    // TODO: ゲームがバックグラウンドウィンドウになる Game is becoming background window.
}

void Game::OnSuspending()
{
    // TODO: ゲームがパワーサスペンデッドになる Game is being power-suspended (or minimized).
}

void Game::OnResuming()
{
	this->timer.ResetElapsedTime();

    // TODO: ゲームがパワーレジュームになる Game is being power-resumed (or returning from minimize).
}

void Game::OnWindowSizeChanged(int width, int height)
{
    this->width = std::max(width, 1);
    this->height = std::max(height, 1);
	
	Graphics::Get().CreateResources();
    // TODO: ゲームウィンドウのサイズが再変更される Game window is being resized.
}

// プロパティ Properties
void Game::GetDefaultSize(int& width, int& height) const
{
    // TODO: 任意のデフォルトウィンドウサイズに変更する(最小サイズは320x200) 
	// Change to desired default window size (note minimum size is 320x200).
    width = 800;
    height = 600;
}

// Exitヘルパー関数 Exit helper
void ExitGame() {
	PostQuitMessage(0);
}
