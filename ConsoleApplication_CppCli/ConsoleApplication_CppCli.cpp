//
//  C++/CLI という言語
// 
// C++ でありながら .NET 言語
// C# と同じことが出来る
// 当然、C++ と同じことも出来る
// 
// 情報が非常に少ない
//
#include "pch.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	System::IO::StreamWriter sw("Test.txt");
	sw.WriteLine("TEST");
    return 0;
}
