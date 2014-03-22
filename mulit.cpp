#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "iostream"
using namespace std;
#define Max 1000
void multiply(char* a,char* b,char* c)
{
    int i,j,ca,cb,*s;
    ca=strlen(a);
    cb=strlen(b);
    s=(int*)malloc(sizeof(int)*(ca+cb));
    for (i=0;i<ca+cb;i++)
        s[i]=0;
    for (i=0;i<ca;i++)
        for (j=0;j<cb;j++)
            s[i+j+1]+=(a[i]-'0')*(b[j]-'0');
			
    for (i=ca+cb-1;i>=0;i--)
	{
        if (s[i]>=10)
        {
            s[i-1]+=s[i]/10;
            s[i]%=10;
        }
	}
    i=0;
    while (s[i]==0)
        i++;
	for (j=0;i<ca+cb;i++,j++)
		c[j]=s[i]+'0';
    c[j]='\0';
    free(s);
}

int main()
{

   char *c;
   
   int length1,length2;
   char a[] ="123";
   char b[] ="456";
   
   length1=strlen(a);
   length2=strlen(b);
 
   c=(char *)malloc(sizeof(char)*(length1+length2));
   
   multiply(a,b,c);
   puts(c);
   return 0;
}
