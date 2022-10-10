#include "pch.h"

int main(array<System::String ^> ^args)
{
	try
	{
		array<System::String^>^ a;
		System::IO::StreamReader reader(LR"(Y:\source\youtube-programmercpp\sample.txt)");
		for (System::Collections::Generic::List<System::String^> list;;) {
			auto s = reader.ReadLine();
			if (s)
				list.Add(s);
			else {
				a = list.ToArray();
				break;
			}
		}
		for each(auto s in a) {
			System::Diagnostics::Debug::WriteLine(s);
		}
	}
	catch (System::Exception^ e)
	{
		System::Console::WriteLine(e->Message);
	}
    return 0;
}
