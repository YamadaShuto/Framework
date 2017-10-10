// DirectX Game Framework 0.92 
// 2017/05/05　Added Japanese comment
// 2017/05/08  Added Graphics singleton class
// 2017/05/13  Added Window class
// 2017/05/20  Functioning WinMain function
// 2017/05/25  Change global Game object to local Game object
// 2017/05/25  Create Window object inside Game object

#include "pch.h"
#include "Game.h"
#include "Window.h"

using namespace DirectX;
using namespace std;


// エントリポイント Entry point
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    if (!XMVerifyCPUSupport())
        return 1;
	// COMライブラリを初期化する
    if (FAILED(CoInitializeEx(nullptr, COINITBASE_MULTITHREADED)))
        return 1;

	// Gameクラス
	unique_ptr<Game> game;

	// ウィンドウサイズ
	int width = 1024;
	int height = 768;

	// Gameオブジェクトを生成する
	game = std::make_unique<Game>(width, height);
	// Gameオブジェクトを初期化する
	game->Initialize(width, height);

	// ゲームを更新する
	MSG msg = game->Run();

    // Gameオブジェクトを破棄する
	game.reset();

	// Comライブラリを終了処理する
    CoUninitialize();
    return (int) msg.wParam;
}
