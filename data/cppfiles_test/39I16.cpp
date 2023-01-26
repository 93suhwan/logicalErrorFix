#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + (c - '0');
    c = getchar();
  }
  return x * f;
}
int n;
int a[105], in[105];
int ans[105];
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    int x = 0;
    cout << "?";
    for (int j = 1; j <= n; j++) {
      if (j != i)
        cout << " 1";
      else
        cout << " 2";
    }
    puts("");
    fflush(stdout);
    scanf("%d", &x);
    if (x != i) {
      a[i] = x;
      in[x]++;
    }
    cout << "?";
    for (int j = 1; j <= n; j++) {
      if (j != i)
        cout << " 2";
      else
        cout << " 1";
    }
    puts("");
    fflush(stdout);
    scanf("%d", &x);
    if (x != i) {
      a[x] = i;
      in[i]++;
    }
  }
  int flag;
  for (int i = 1; i <= n; i++) {
    if (!in[i]) {
      flag = i;
      break;
    }
  }
  int num = 0;
  while (flag) {
    ans[flag] = ++num;
    flag = a[flag];
  }
  cout << "!";
  for (int i = 1; i <= n; i++) cout << " " << ans[i];
  return 0;
}
