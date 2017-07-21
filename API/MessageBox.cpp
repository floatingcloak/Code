#include <cstdio>
#include <tchar.h>
#include <windows.h>

using namespace std;



int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {
	int sum = 0;
	for(int i = 1; i <= 10; ++i) sum += i;
	TCHAR str[256] = {0};
	wsprintf(str, _T("%d"), sum);
	MessageBox(NULL, str, _T("Tir"), MB_OK);
	return 0;
}