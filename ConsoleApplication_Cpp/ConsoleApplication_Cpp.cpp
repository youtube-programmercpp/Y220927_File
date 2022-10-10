#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
#include <list>
#include <vector>
#include <algorithm>
int main()
{
	static const char filename[] = R"(Y:\source\youtube-programmercpp\sample.txt)";
	if (std::ifstream file{ filename }) {
		std::vector<std::string> a;
		for (std::list<std::string> list;;) {
			std::string s;
			if (std::getline(file, s))
				list.push_back(std::move(s));
			else {
				a.resize(list.size());
				std::move(list.begin(), list.end(), a.begin());
				break;
			}
		}
		for (const auto& s : a) {
			OutputDebugStringA(s.c_str());
			OutputDebugStringA("\n");
		}
	}
	else
		std::cerr << "ファイル「" << filename << "」をオープンすることが出来ませんでした。\n";
}
