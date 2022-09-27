#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE* fp;
	if (fopen_s(&fp, "file.txt", "r") == 0) {
		//オープン成功
		for (;;) {
			const int ch = getc(fp);
			if (ch == EOF)
				break;//ファイル終わり
			else
				putchar(ch);
		}
		fclose(fp);
		return EXIT_SUCCESS;
	}
	else {
		//オープン失敗
		return EXIT_FAILURE;
	}
}
