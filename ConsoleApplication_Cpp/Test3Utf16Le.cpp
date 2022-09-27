#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>

int main()
{
	static const char filename[] = R"(Y:\source\youtube-programmercpp\Y220927_File\ConsoleApplication_C\file.txt)";
	if (std::ifstream file{filename}) {
		char bom[2];
		if (file.read(bom, sizeof bom)) {
			std::wstring s;
			for (;;) {
				wchar_t ch;
				if (file.read((char*)&ch, sizeof ch))
					s.push_back(ch);
				else
					break;
			}
			OutputDebugStringW(s.c_str());
			OutputDebugStringW(L"\n");
		}
	}
}
