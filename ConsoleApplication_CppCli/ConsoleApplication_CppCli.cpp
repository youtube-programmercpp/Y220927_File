//
//  C++/CLI �Ƃ�������
// 
// C++ �ł���Ȃ��� .NET ����
// C# �Ɠ������Ƃ��o����
// ���R�AC++ �Ɠ������Ƃ��o����
// 
// ��񂪔��ɏ��Ȃ�
//
#include "pch.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	System::IO::StreamWriter sw("Test.txt");
	sw.WriteLine("TEST");
    return 0;
}
