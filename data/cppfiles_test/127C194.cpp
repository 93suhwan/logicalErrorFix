#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
vector<int> v[30];
int T;
char ans[456];
int main() {
  scanf("%d", &T);
  while (T--) {
    string a, b;
    int cnt = 0;
    memset(ans, 0, sizeof(ans));
    cin >> a >> b;
    for (int i = 0; i < 26; ++i) v[i].clear();
    for (int i = 0; i < a.size(); ++i) v[a[i] - 'a'].push_back(i);
    if ((v[0].size() == 0) || (v[1].size() == 0) || (v[2].size() == 0)) {
      for (int i = 0; i < 26; ++i)
        for (int j = 0; j < v[i].size(); ++j) ans[cnt++] = 'a' + i;
      printf("%s\n", ans);
      continue;
    }
    if (b[0] != 'a') {
      for (int i = 0; i < 26; ++i)
        for (int j = 0; j < v[i].size(); ++j) ans[cnt++] = 'a' + i;
      printf("%s\n", ans);
    } else {
      for (int i = 0; i < v[0].size(); ++i) ans[cnt++] = 'a';
      if (b[1] == 'b') {
        for (int i = 0; i < v[2].size(); ++i) ans[cnt++] = 'c';
        for (int i = 0; i < v[1].size(); ++i) ans[cnt++] = 'b';
      } else if (b[1] == 'c') {
        for (int i = 0; i < v[1].size(); ++i) ans[cnt++] = 'b';
        for (int i = 0; i < v[2].size(); ++i) ans[cnt++] = 'c';
      }
      for (int i = 3; i < 26; ++i)
        for (int j = 0; j < v[i].size(); ++j) ans[cnt++] = 'a' + i;
      printf("%s\n", ans);
    }
  }
  return 0;
}
