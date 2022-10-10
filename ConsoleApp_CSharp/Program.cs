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
			try
			{
				string[] a;
				using (StreamReader reader = new StreamReader(@"Y:\source\youtube-programmercpp\sample.txt"))
				{
					for (var list = new System.Collections.Generic.List<string>(); ; )
					{
						var s = reader.ReadLine();
						if (s == null)
						{
							a = list.ToArray();
							break;
						}
						else
							list.Add(s);
					}
				}
				foreach (var s in a)
				{
					System.Diagnostics.Debug.WriteLine(s);
				}
			}
			catch (System.Exception e)
			{
				System.Console.WriteLine(e.Message);
			}
		}
	}
}
