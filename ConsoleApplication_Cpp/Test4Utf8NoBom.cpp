static const char filename[] = R"(Y:\source\youtube-programmercpp\Y220927_File\ConsoleApplication_C\utf8text.txt)";
#include <fstream>
#include <string>
#include <Windows.h>
int main()
{
	if (std::ifstream file{ filename }) {
		for (;;) {
			std::string s;
			if (std::getline(file, s)) {
				if (s.empty())
					continue;
				else {
					std::wstring w(s.length(), L'\0');
					w.resize(MultiByteToWideChar(CP_UTF8, 0, s.c_str(), static_cast<int>(s.length()), &w.front(), static_cast<int>(w.size() + 1)));
					OutputDebugStringW(w.c_str());
					OutputDebugStringW(L"\n");
				}
			}
			else
				break;
		}
	}
}
