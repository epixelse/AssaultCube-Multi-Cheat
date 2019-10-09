#include <iostream>
#include <Windows.h>

using namespace std;

int main(void){
	
	HWND hWnd = FindWindowA(NULL, "AssaultCube");
	
	if(hWnd == NULL){
		cout << "First you need open the game: AssaultCube" << endl;
		Sleep(3000);
		exit(-1);
	}else{
		DWORD procID;
		GetWindowThreadProcessId(hWnd, &procID);
		HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
		
		if(!handle){
			cout << "Something wrong re-open your game!" << endl;
		}else{
			
			// Infinite Ammo
			WriteProcessMemory(handle, (LPVOID)0x04637E9, "\x90\x90", 2, NULL);
			
			// No recoil
			WriteProcessMemory(handle, (LPVOID)0x463786, "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90", 10, NULL);
			
			// Rapid Fire
			WriteProcessMemory(handle, (LPVOID)0x4637E4, "\x90\x90", 2, NULL);
			
			cout << "Memory has been Written and Cheat has working!" << endl;
		}
		CloseHandle(handle);
	}
	Sleep(4000);
}
