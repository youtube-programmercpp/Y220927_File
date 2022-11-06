// C++サンプルプログラム：ファイルを介した C# プログラムとの連携 Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <fstream>   //std::ifstream, std::ofstream を使うために必要
#include <stdexcept> //std::runtime_error を使うために必要
#include <iostream>  //std::cerr を使うために必要
#include <cstdlib>   //EXIT_SUCCESSなどを使うために必要（とはいえ、C#側では終了コードを見ていないが）
//全体の流れと実行の際の条件については ConsoleApp_CSharp2 の Programs.cs を見てください。
int main()
{
	try {
		//ファイル１を開く（読み出し用）
		if (std::ifstream file1{ "file1.csv" }) {
			//ファイル２を開く（書き込み用）
			if (std::ofstream file2{ "file2.txt" }) {
				for (;;) {
					int a, b;
					char comma;
					//整数データ２個を読み出す（間にコンマが入り、空白類は含まれない前提）
					if (file1 >> a >> comma >> b) {
						if (comma == ',')
							file2 << a + b << std::endl;
						else
							throw std::runtime_error(__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): Comma character was not found.");//コンマではない文字が見つかった
					}
					else
						return EXIT_SUCCESS;//正常終了
				}
			}
			else
				throw std::runtime_error(__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): std::ofstream::ofstream failed.");//ファイル２のオープン失敗
		}
		else
			throw std::runtime_error(__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): std::ofstream::ifstream failed.");//ファイル１のオープン失敗
	}
	catch (const std::exception& e) {
		//エラーメッセージを出力する
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;//異常終了
	}
}
