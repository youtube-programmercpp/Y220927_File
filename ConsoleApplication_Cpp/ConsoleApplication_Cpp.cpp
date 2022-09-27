#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	if (FILE* const fp = fopen("file.txt", "w")) {
		for (int i = 0; i < 100; ++i)
			fprintf(fp, "%d\n", 1 + i);
		//ファイルオープン成功
		fclose(fp);
	}
	else {
		//ファイルオープン失敗
	}
}
