#pragma once
#ifndef MYGAME
#define MYGAME

#include "../Game.h"

class MyGame : public Game
{
public:
	//コンストラクタ	
	MyGame(int width , int heigth);
	//MyGameオブジェクトの初期化
	void Initialize(int width, int height) override;
	// 基本ゲームループ Basic game loop
	void Update(const DX::StepTimer& timer) override;
	// 画面をクリアする
	void Clear() override;
	// シーンを描画
	void Render(const DX::StepTimer& timer) override;
	// バックバッファをスクリーンに送る
	void Present() override;
	// 終了処理
	void Finalize() override;
private:
	//キーボード
	std::unique_ptr<Keyboard> keyboard;
	// デバッグカメラ DebugCamera
	std::unique_ptr<DebugCamera>	camera;
	// グリッドフロア GridFloor
	std::unique_ptr<GridFloor> gridFloor;
	// モデル Model
	std::unique_ptr<Model> cup;
	// ワールド world
	DirectX::SimpleMath::Matrix world;
	// スケール scale
	float scale;
};
#endif //MYGAME
