#include "iostream"
#include "vector"
using namespace std;

int package01(int* array_vol, int* array_value, int Num, int Vol, int* picked)
{
	int i,j;
	vector<vector<int> > vetInt(Num+1, vector<int>(Vol+1));
	for(i=0;i<=Num;i++)
		vetInt[i][0]=0;
	for(i=0;i<=Vol;i++)
		vetInt[0][i]=0;

	for(i=1;i<=Num;i++)
	{
		for(j=1;j<=Vol;j++)
		{
			vetInt[i][j] = vetInt[i-1][j];
			if(j>=array_vol[i-1])
			{
				int temp = vetInt[i-1][j-array_vol[i-1]] + array_value[i-1];//array_vol,array_value start from 0
				if(vetInt[i-1][j] < temp)
					vetInt[i][j] = temp;
			}
		}
	}

	int x=Vol;
	for(i=Num;i>=1;i--)
	{
		if(vetInt[i][x] == vetInt[i-1][x])
			picked[i-1] = 0;
		else
		{
			picked[i-1] = 1;
			x = x - array_vol[i-1];
		}
	}

	return vetInt[Num][Vol];
}

int main()
{
	int array_vol[5] = {3,4,5,1,2};
	int array_value[5] = {4,5,6,3,5};
	int *p = new int[5];
	int x = package01(array_vol, array_value, 5, 10, p);
	cout<<x<<endl;
	for(int i=0;i<5;i++)
		cout<<p[i]<<" ";
	cout<<endl;
	delete[] p;
	return 0;
}


