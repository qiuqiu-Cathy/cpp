/*
   A. String Task
   time limit per test
   2 seconds
   memory limit per test
   256 megabytes
   input
   standard input
   output
   standard output

   Petya started to attend programming lessons. On the first lesson his task was to write a simple program. The program was supposed to do the following: in the given string, consisting if uppercase and lowercase Latin letters, it:

       deletes all the vowels,
	       inserts a character "." before each consonant,
		       replaces all uppercase consonants with corresponding lowercase ones. 

			   Vowels are letters "A", "O", "Y", "E", "U", "I", and the rest are consonants. The program's input is exactly one string, it should return the output as a single string, resulting after the program's processing the initial string.

			   Help Petya cope with this easy task.
			   Input

			   The first line represents input string of Petya's program. This string only consists of uppercase and lowercase Latin letters and its length is from 1 to 100, inclusive.
			   Output

			   Print the resulting string. It is guaranteed that this string is not empty.
			   Examples
			   Input

			   tour

			   Output

			   .t.r

			   Input

			   Codeforces

			   Output

			   .c.d.f.r.c.s

			   Input

			   aBAcAba

			   Output

			   .b.c.b
 */
#include <bits/stdc++.h>
using namespace std;
//thanks to tl~
int main()
{
	char s[105];
	char c[210];
	while(cin >> s)
	{
		int l=strlen(s);
		for(int i=0;i<l;i++)
		{
			s[i]=tolower(s[i]);
		//	cout << s[i] << endl;
		}
		for(int i=0;i<l;i++)
		{
			if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y')
			{
				continue;
			}
			else
			{
				cout << '.' << s[i] ;
			}
		}
		cout << endl;
	}
	return 0;
}
