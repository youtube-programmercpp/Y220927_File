#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
int main()
{
	static const char filename[] = "Y:\\source\\youtube-programmercpp\\sample.txt_";
	FILE* const fp = fopen(filename, "r");
	if (fp) {
		for (;;) {
			char buf[512];
			if (fgets(buf, sizeof buf, fp))
				OutputDebugStringA(buf);
			else
				break;
		}
		fclose(fp);
	}
	else {
		perror("fopen");
		fprintf(stderr, "ファイル「%s」をオープンすることが出来ませんでした。\n", filename);
	}
}
