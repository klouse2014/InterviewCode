#include "iostream"
#include "math.h"
using namespace std;
//输出字符串所有的组合
void select(char *arr, int len)
{
	int max = pow(2, len) - 1;
	
	for(int i=1; i<=max; i++)
	{
		for(int j=0; j<len; j++)
		{
			if(i & (0x1<<j))
				cout<<arr[j];
		}
		cout<<endl;
	}
}
	
		

int main()
{
	char c[] = "abcd";
	select(c, 4);
	return 0;
	
}