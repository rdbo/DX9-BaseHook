#include <pch.h>
#include <base.h>

//Data
HMODULE           Base::Data::hModule    = (HMODULE)NULL;
void*             Base::Data::pDeviceTable[D3DDEV9_LEN];
LPDIRECT3DDEVICE9 Base::Data::pDxDevice9 = (LPDIRECT3DDEVICE9)NULL;
HWND              Base::Data::hWindow    = (HWND)NULL;
mem::voidptr_t    Base::Data::pEndScene  = (mem::voidptr_t)NULL;
EndScene_t        Base::Data::oEndScene  = (EndScene_t)NULL;
WndProc_t         Base::Data::oWndProc   = (WndProc_t)NULL;
#if defined(MEM_86)
mem::size_t       Base::Data::szEndScene = 7;
#elif defined(MEM_64)
mem::size_t       Base::Data::szEndScene = 15;
#endif
UINT              Base::Data::WmKeys[0xFF];
bool              Base::Data::Detached   = false;
bool              Base::Data::ToDetach   = false;
bool              Base::Data::ShowMenu   = true;
bool              Base::Data::InitImGui  = false;


//Functions

bool Base::Init()
{
	Hooks::Init();
	return true;
}

bool Base::Shutdown()
{
	Hooks::Shutdown();
	return true;
}

bool Base::Detach()
{
	Base::Shutdown();
	CreateThread(nullptr, 0, ExitThread, Data::hModule, 0, nullptr);
	return true;
}