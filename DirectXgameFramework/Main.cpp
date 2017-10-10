// DirectX Game Framework 0.92 
// 2017/05/05�@Added Japanese comment
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


// �G���g���|�C���g Entry point
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    if (!XMVerifyCPUSupport())
        return 1;
	// COM���C�u����������������
    if (FAILED(CoInitializeEx(nullptr, COINITBASE_MULTITHREADED)))
        return 1;

	// Game�N���X
	unique_ptr<Game> game;

	// �E�B���h�E�T�C�Y
	int width = 1024;
	int height = 768;

	// Game�I�u�W�F�N�g�𐶐�����
	game = std::make_unique<Game>(width, height);
	// Game�I�u�W�F�N�g������������
	game->Initialize(width, height);

	// �Q�[�����X�V����
	MSG msg = game->Run();

    // Game�I�u�W�F�N�g��j������
	game.reset();

	// Com���C�u�������I����������
    CoUninitialize();
    return (int) msg.wParam;
}
