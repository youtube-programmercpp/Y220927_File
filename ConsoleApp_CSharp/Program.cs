using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp_CSharp
{
	internal class Program
	{
		static void Main(string[] args)
		{
			using (StreamWriter sw = new StreamWriter("Test.txt"))
			{
				sw.WriteLine("TEST");
				
			}
		}
	}
}
