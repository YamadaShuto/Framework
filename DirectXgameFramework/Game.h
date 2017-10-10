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
//**追加文
#include <algorithm>
//**追加文end

#include "StepTimer.h"
//**追加文
//#include "dx.h"
//**追加文end
#include "Window.h"
#include "Graphics.h"
#include "DebugCamera.h"
#include "Grid.h"

class Window;

// D3D11デバイスを生成し、ゲームループを提供する基本ゲーム実装
// A basic game implementation that creates a D3D11 device and provides a game loop.
class Game
{
public:

	MSG Game::Run();
	//**追加文
	// コンストラクタ Constructor
	//Game(HINSTANCE hInstance, int nCmdShow);
	Game(int width, int height);
	// 初期化と管理 Initialization and management
    //void Initialize(int width, int height);
    virtual void Initialize(int width, int height);
	// 基本ゲームループ Basic game loop
	//MSG Update();
	virtual void Update(const DX::StepTimer& timer);
	// 画面をクリアする
	virtual void Clear();
	// シーンを描画
	virtual void Render(const DX::StepTimer& timer);
	// バックバッファをスクリーンに送る
	virtual void Present();
	// 終了処理
	//void Finalize();
	virtual void Finalize();
	//**追加文end

    // メッセージ Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // プロパティ Properties
    void GetDefaultSize(int& width, int& height) const;

//private:
	// ゲームを更新する Update game
    //void Update(StepTimer const& timer);
    // シーンを描画する Render scene
	//void Render();
	// 画面をクリアする Clear screen
    //void Clear();
	// バックバッファをスクリーンに送る
    //void Present();
	// FPSを描画する Draw FPS
	void DrawFPS();

private:
	HINSTANCE hInstance;
	int nCmdShow;
    // デバイスリソース Device resources.
    HWND hWnd;
	// 出力幅 Output width
    int width;
	// 出力高 Output height
    int height;

	// ウィンドウ Window
	unique_ptr<Window> window;
	// グラフィックス Graphics
	unique_ptr<Graphics> graphics;
	// 機能レベル Feature level
    D3D_FEATURE_LEVEL featureLevel;
protected:
    // ループタイマーを描画する Rendering loop timer
    DX::StepTimer timer;

	// キーボード Keyboard
	//unique_ptr<Keyboard> keyboard;
	// スプライトバッチ SpriteBatch
	unique_ptr<SpriteBatch>	spriteBatch;
	// デバッグカメラ DebugCamera
	unique_ptr<DebugCamera>	camera;
	// グリッドフロア GridFloor
	//unique_ptr<GridFloor> gridFloor;
	// フォント Font
	unique_ptr<SpriteFont> font;

	// エフェクトファクトリインターフェース IEffectFactory
	unique_ptr<IEffectFactory> fxFactory;
	// コモンステート CommonStates
	unique_ptr<CommonStates> commonStates;
	// モデル Model
	//unique_ptr<Model> cup;
	// ワールド world
	//DirectX::SimpleMath::Matrix world;
	// スケール scale
	//float scale;

	//unique_ptr<GeometricPrimitive> box;

};

#endif	// GAME
