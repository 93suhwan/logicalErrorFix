#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 100;
inline int read() {
  int X = 0;
  bool flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    X = (X << 1) + (X << 3) + ch - '0';
    ch = getchar();
  }
  if (flag) return X;
  return ~(X - 1);
}
char s[N];
int main() {
  int _;
  cin >> _;
  while (_--) {
    cin >> s;
    int n = strlen(s);
    int ans = 0, f = 0;
    for (int i = 0; i <= n; i++) {
      if (s[i] == '0') f = 1;
    }
    if (f == 0) {
      cout << 0 << endl;
      continue;
    }
    int start = 0, sum = 0;
    for (int i = start; i < n; i++) {
      if (s[i] == '0') {
        int res = 0, yi = 0, er = 0;
        for (int j = i; j < n; j++) {
          if (s[j] == '1') yi++;
          if (s[j] == '0') res++;
          if (s[j] == '2') er++;
          start = j + 1;
          if (yi && er) break;
        }
        if (yi == 0 && er == 0)
          sum++;
        else if (yi == 0 || yi == 1)
          sum++;
        else if (er == 1 || er == 0) {
          if (res >= 2)
            sum += 2;
          else
            sum++;
        }
        i = start;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
