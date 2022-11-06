// C# サンプルプログラム：ファイルを介したC++プログラムとの連携 Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
//
// 【関係するファイル群】
// ファイル１：file1.csv
// ファイル２：file2.txt
// C# プログラム実行ファイル：ConsoleApp_CSharp2.exe
// C++プログラム実行ファイル：ConsoleApplication_Cpp2.exe
// 【全体の流れ】
// C#プログラムはファイル１に CSV 形式で１行につき２個の整数データを書き込む。
// C++プログラムはファイル１を読み込んで２個の整数データを足した結果をファイル２に書き出す。（１件につき改行を１個出力）
// C#プログラムはファイル２を読み込んで内容をコンソールに出力する。
// 【前提条件】
// ファイル１、ファイル２、C#プログラムの実行ファイル、C++プログラムの実行ファイルはすべて同一ディレクトリ内に配置されるものとする。
namespace ConsoleApp_CSharp2
{
	internal class Program
	{
		static void Main(string[] args)
		{
			//ファイル１，ファイル２は共にシフトJISでエンコードされるものとする。
			var encoding_sjis = System.Text.Encoding.GetEncoding("shift-jis");
			//ファイル１にデータを書き込む
			System.Console.WriteLine("ファイル１にデータを書き込みます。");
			using (var file1 = new System.IO.StreamWriter(@"file1.csv", false, encoding_sjis))
			{
				file1.WriteLine("12,34");
				file1.WriteLine("56,78");
			}
			//C++プログラムを起動し、ファイル１を処理させる。
			System.Console.WriteLine("C++プログラムを呼び出します。");
			using (var process = new System.Diagnostics.Process())
			{
				//C++プログラムのファイル名を設定する
				process.StartInfo.FileName = "ConsoleApplication_Cpp2";
				//C++プログラム実行時のウィンドウを非表示にする
				process.StartInfo.WindowStyle = System.Diagnostics.ProcessWindowStyle.Hidden;
				//C++プログラムを起動する
				process.Start();
				//C++プログラムが終わるまで待つ
				process.WaitForExit();
			}
			//ファイル２からデータ読み出す
			System.Console.WriteLine("ファイル２からデータを読み出します。");
			using (var file2 = new System.IO.StreamReader(@"file2.txt", encoding_sjis)) {
				for (; ;)
				{
					//計算結果を得る
					var s = file2.ReadLine();
					if (s == null)
						break;//ファイルの終わりに到達した
					else
					{
						//文字列から数値に変換する（この応用例ではあまり意味が無いが）
						var result_value = int.Parse(s);
						//計算結果を出力する
						System.Console.WriteLine(result_value);
					}
				}
			}

			System.Console.WriteLine("終わりました。画面を閉じるにはどれかのキーを押してください。");
			System.Console.ReadKey();
		}
	}
}
