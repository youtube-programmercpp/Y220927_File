#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE* fp;
	if (fopen_s(&fp, "file.txt", "r") == 0) {
		//�I�[�v������
		for (;;) {
			const int ch = getc(fp);
			if (ch == EOF)
				break;//�t�@�C���I���
			else
				putchar(ch);
		}
		fclose(fp);
		return EXIT_SUCCESS;
	}
	else {
		//�I�[�v�����s
		return EXIT_FAILURE;
	}
}
