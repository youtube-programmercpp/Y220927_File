#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//C言語の main 関数は成功すると 0、失敗すると 1 あるいは 2、あるいは… 0 以外の値を返す
int main()
{
	//書き込み用にファイルをオープンする
	FILE* const fp = fopen("file.txt", "w");
	if (fp) {
		//オープン成功 
		fputs("%%%%\n", fp);
		//ファイルをクローズする
		fclose(fp);
		return EXIT_SUCCESS;
	}
	else {
		fprintf(stderr, "ファイルのオープンに失敗しました。\n");
		return EXIT_FAILURE;//失敗したという意味
	}
}
