// kousuan.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <time.h>
#include <iostream>

using namespace std;


// int _tmain(int argc, _TCHAR* argv[])
// {
// 	time_t now = time(NULL);
// 	srand(now);
// 	for (int i= 0; i < 400 ; ++i)
// 	{
// 		int a = rand() * 90 / RAND_MAX  + 10;
// 		int b = rand() * 90 / RAND_MAX + 10;
// 
// 		int op = rand() % 2;
// 
// 		if (op == 1 )
// 		{
// 			//减法
// 			if ( a < b )
// 			{
// 				int tmp = a;
// 				a = b;
// 				b = tmp;
// 			}
// 		}
// 		else
// 		{
// 			//加法
// 			if (a + b > 100)
// 				continue;
// 		}
// 		char o = op == 0 ? '+' : '-';
// 		cout << a << o << b << endl;
// 	}
// 	return 0;
// }

int _tmain(int argc, _TCHAR* argv[])
{
	time_t now = time(NULL);
	srand(now);
	int i =0;
	while (i < 400)
	{
		int a1 = rand() * 10 / RAND_MAX ;
		int a2 = rand() * 10 / RAND_MAX ;
		
		int b1 = rand() * 10 / RAND_MAX ;
		int b2 = rand() * 10 / RAND_MAX ;

		int a = a1* 10 + a2;
		int b = b1* 10 + b2;

		int result;
		int op = rand() % 2;

		if (op == 1 )
		{
			//减法
			if ( a < b )
				continue;
			if ( a2 >= b2)
				continue;
			if ( a <= 20)
				continue;
			result = a - b;
		}
		else
		{
			//加法
			if (a + b > 100)
				continue;
			if (a2 + b2 < 10)
				continue;
			if ( a + b <= 20)
				continue;
			result = a + b;
		}
		char o = op == 0 ? '+' : '-';
		char buf[100];
		sprintf(buf,"%2d %c %2d = ",a,o,b);
		cout << i << ',' << buf << ',' << result << endl;
		++i;
	}
	return 0;
}