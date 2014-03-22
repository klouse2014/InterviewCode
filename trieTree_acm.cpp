#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
using namespace std;
const int maxn = 1000000 + 10;
const int max1 = 10 + 2;

struct node {
    int next[26];
    int id;
    node () {
        id = -1;
        memset(next, 0, sizeof(next));
    }
};

vector<node> trie;
int a[maxn], cnt[maxn];
int n;
char s1[12], s2[12];

int insert(char *s) {
    int now = 0;
    for (int i = 0; s[i]; ++i) {
        int x = s[i] - 'a';
        if (trie[now].next[x]) {
            now = trie[now].next[x];
        } else {
            trie[now].next[x] = trie.size();
            now = trie[now].next[x];
            trie.push_back(node());
        }
    }
    if (trie[now].id == -1) trie[now].id = n++;
    return trie[now].id;
}

int find(int x) {
    int root = x;
    while (a[root] != -1) root = a[root];
    int k;
    while (root != x) {
        k = a[x];
        a[x] = root;
        x = k;
    }
    return root;
}

int main() {
    n = 0;
    memset(a, -1, sizeof(a));
    memset(cnt, 0, sizeof(cnt));
    trie.push_back(node());
    while (scanf("%s%s", s1, s2) == 2) {
        int x1 = insert(s1), x2 = insert(s2);
        ++cnt[x1];
        ++cnt[x2];
        x1 = find(x1);
        x2 = find(x2);
        if (x1 != x2) a[x2] = x1;
    }
    int odd = 0;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] % 2) ++odd;
        if (i > 0 && find(i) != find(i - 1)) ok = false;
    }
    if (odd != 0 && odd != 2) ok = false;
    if (ok) printf("Possible\n");
    else printf("Impossible\n");
    return 0;
}

