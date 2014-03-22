#include "iostream"
#include "vector"
using namespace std;

int LCS(char* str, char *str1, int len, int len1, int** &path)
{
	int i,j;
	vector<vector<int> > vetInt(len+1, vector<int>(len1+1));

	for(i=0;i<=len;i++)
		vetInt[i][0] = 0;
	for(i=0;i<=len1;i++)
		vetInt[0][i] = 0;
	
	for(i=1;i<=len;i++)
	{
		for(j=1;j<=len1;j++)
		{
			if(str[i-1] == str1[j-1])//str,str1 start from 0
			{	
				vetInt[i][j] = vetInt[i-1][j-1] + 1;
				path[i-1][j-1] = 0;
			}
			else
			{
				if(vetInt[i][j-1] > vetInt[i-1][j])
				{
					vetInt[i][j] = vetInt[i][j-1];
					path[i-1][j-1] = -1;
				}
				else
				{
					vetInt[i][j] = vetInt[i-1][j];
					path[i-1][j-1] = 1;
				}
			}
		}
	}

	return vetInt[len][len1];
}

void output_path(char* str, int x, int y, int** path)
{
	if(x==0&&y==0)
		return;
	if(path[x][y] == 0)
	{
		cout<<str[x]<<" ";
		output_path(str, x-1, y-1, path);
	}
	else if(path[x][y] == -1)
		output_path(str, x, y-1, path);
	else
		output_path(str, x-1, y, path);
}

int main()
{
	char str[5] = {'d','c','f','e','a'};
	char str1[7] = {'a','c','h','f','e','d','a'};
	int** path = new int*[5];
	for(int i=0;i<5;i++)
		path[i] = new int[7];
	int len = LCS(str, str1, 5, 7, path);
	cout<<len<<endl;
	output_path(str, 4, 6, path);
	cout<<endl;
	for(int i=0;i<5;i++)
		delete[] path[i];
	delete[] path;
	return 0;
}




