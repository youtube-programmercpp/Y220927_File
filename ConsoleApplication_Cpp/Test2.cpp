#include <fstream> //ファイル読み書きの際に使用
#include <iostream>
#include <stdio.h>
int main()
{
	if (std::ofstream file{ "file.txt" }) {
		//オープン成功
		for (int i = 0;i < 100;++i)
			file << 2 * (1 + i) << '\n';
		return EXIT_SUCCESS;
	}
	else {
		//オープン失敗
		std::cerr << "ファイルのオープンに失敗しました。\n";
		return EXIT_FAILURE;
	}
}
