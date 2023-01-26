#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -f;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}
inline void chkmin(int &a, int b) {
  if (a > b) a = b;
}
inline void chkmax(int &a, int b) {
  if (a < b) a = b;
}
const int N = 1e5 + 5;
char s[N];
int a[N];
int main() {
  int T = read();
  while (T--) {
    int n = read(), tmp = 0;
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) a[i] = s[i] - 'a';
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
      if (a[i] != s[i] - 'a') ++tmp;
    cout << tmp << endl;
  }
}
