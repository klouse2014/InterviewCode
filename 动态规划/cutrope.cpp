//绳子长度为n,求切割方式使子绳子长度乘积最大

#include "iostream"
#include "vector"
using namespace std;


int max_cut(int start, int end, int** matrix)
{		
	if(matrix[start][end]!=0)
		return matrix[start][end];
	
	int max = end - start;
	for(int k=start+1; k<end; k++)
	{
		int temp = max_cut(start, k, matrix) * max_cut(k, end, matrix);
		if(max < temp)
			max = temp;
	}
	matrix[start][end] = max;
	return max;
}

int main()
{
	int n = 100;
	int** matrix = new int*[n+1];
	for(int i=0;i<n+1;i++)
		matrix[i] = new int[n+1];
	
	for(int i=0;i<n+1;i++)
		for(int j=0;j<n+1;j++)
			matrix[i][j] = 0;
	int result = max_cut(0, n, matrix);
	cout<<result<<endl;
	return 0;
}
	