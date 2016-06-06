#include <iostream>
#include <string>
#include "Windows.h"

int main() {
	std::string c;
	std::cout << "Queue - 'qlib',\nPriority queue - 'qwplib',\nelse any key: ";
	std::cin >> c;
	while (c == "qlib" || c == "qwplib") {
		HINSTANCE h;
		if (c == "qlib") h = LoadLibrary(L"qlib");
		if (c == "qwplib") h  = LoadLibrary(L"qwplib");
		if (h) {
			int n;
			std::cin >> n;
			for (int i = 0; i < n; i++) {
				std::string b;
				int c;
				std::cin >> b;

				if (b == "add") {
					std::cin >> c;
					typedef void s(int b);
					FARPROC add = (FARPROC)GetProcAddress((HMODULE)h, "add");
					((s*)add)(c);
				}

				if (b == "del") {
					FARPROC del = (FARPROC)GetProcAddress((HMODULE)h, "del");
					try {
						del();
					}
					catch (const char* a) {
						std::cout << a;
					}
				}

				if (b == "get") {
					FARPROC get = (FARPROC)GetProcAddress((HMODULE)h, "get");
					try {
						std::cout << get() << std::endl;
					}
					catch (const char* a) {
						std::cout << a;
					}
				}
			}
			FreeLibrary(h);
		}
		else std::cout << "Can't load library!\n";
		std::cout << "If you want to continue the work, reselect queue type,\nelse any key: ";
		std::cin >> c;
	}
	system("pause");
	return 0;
}