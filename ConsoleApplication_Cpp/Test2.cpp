#include <fstream> //�t�@�C���ǂݏ����̍ۂɎg�p
#include <iostream>
#include <stdio.h>
int main()
{
	if (std::ofstream file{ "file.txt" }) {
		//�I�[�v������
		for (int i = 0;i < 100;++i)
			file << 2 * (1 + i) << '\n';
		return EXIT_SUCCESS;
	}
	else {
		//�I�[�v�����s
		std::cerr << "�t�@�C���̃I�[�v���Ɏ��s���܂����B\n";
		return EXIT_FAILURE;
	}
}
