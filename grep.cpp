#include <iostream>
#include <assert.h>
using namespace std;

bool isMatch(const char *s, const char *p) {
  assert(s && p);
  if (*p == '\0') return *s == '\0';
 
  // next char is not '*': must match current character
  if (*(p+1) != '*') {
    assert(*p != '*');
    return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
  }
  // next char is '*'
  while ((*p == *s) || (*p == '.' && *s != '\0')) {
    if (isMatch(s, p+2)) return true;
    s++;
  }
  //仅匹配*对应0的时候
  return isMatch(s, p+2);
}

int main()
{
	char s[] = "ababbc";
	char p[] = "abab*.*";
	cout<<isMatch(s, p)<<endl;
	
	return 0;
}
	
	