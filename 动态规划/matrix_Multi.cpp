#include "iostream"
using namespace std;

void MatrixChain(int *p, int n, int** m, int** s)//p[i]��ʾ��������
{
    for(int i=0; i<n; i++)
        m[i][i] = 0;
    for(int r=1; r<n; r++)//���
    {
        for(int i=0; i+r<n; i++)//��ʼλ��
        {
            int j = i+r;//����λ��
            m[i][j] = m[i][i] + m[i+1][j] + p[i]*p[i+1]*p[j+1];
            s[i][j] = i;
            for(int k=i+1; k<j; k++)
            {
                int temp = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
                if(temp < m[i][j])
                {
                    m[i][j] = temp;
                    s[i][j] = k;
                }
            }
        }
    }
}


void Traceback(int i, int j, int** s)
{
    if(i==j)
        return;
    Traceback(i, s[i][j], s);
    Traceback(s[i][j]+1, j, s);
    cout<<"A"<<i<<"��A"<<j<<"���"<<endl;
}

int main()
{
     int n=6;//����ĸ���
     int *p=new int[n+1];
     //p[0]:��һ�����������
     //p[1]:��һ��������������ڶ������������
     //p[2]:�ڶ�����������������������������
     p[0]=30;
     p[1]=35;
     p[2]=15;
     p[3]=5;
     p[4]=10;
     p[5]=20;
     p[6]=25;
 
     int **m,**s;
     m=new int*[n];
     for( int i=0;i<n;i++)
         m[i]=new int[n];
 
     s=new int*[n];
     for(int i=0;i<n;i++)
         s[i]=new int[n];  
 
     MatrixChain(p,n,m,s);
     Traceback(0,n-1,s);
     return 0;
}


