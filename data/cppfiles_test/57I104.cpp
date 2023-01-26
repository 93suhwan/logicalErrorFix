#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
const long long N = 1000010, mod = 1e9 + 7;
char s[N];
long long n, a[N], A, B, xianA, xianB;
vector<long long> ans;
long long find(long long x) {
  long long ans = 0;
  for (long long i = (long long)(1); i <= (long long)(n); ++i)
    if (a[i] == x) ans = i;
  return ans;
}
int main() {
  for (long long T = read(); T--;) {
    n = read();
    bool fl = 1;
    ans.clear();
    for (long long i = (long long)(1); i <= (long long)(n); ++i) {
      a[i] = read();
      fl &= (a[i] & 1) == (i & 1);
    }
    if (!fl)
      puts("-1");
    else {
      for (long long i = n; i >= 1; i -= 2) {
        long long p;
        p = find(i);
        if (p > 0) ans.push_back(p), reverse(a + 1, a + p + 1);
        p = find(i - 1) - 1;
        if (p > 0) ans.push_back(p), reverse(a + 1, a + p + 1);
        p = find(i - 1) + 1;
        if (p > 0) ans.push_back(p), reverse(a + 1, a + p + 1);
        p = find(i);
        if (p > 0) ans.push_back(p), reverse(a + 1, a + p + 1);
        ans.push_back(i);
        reverse(a + 1, a + i + 1);
      }
      cout << ans.size() << endl;
      for (long long i = (long long)(0); i < (long long)(ans.size()); ++i)
        write(ans[i]), putchar(' ');
      puts("");
    }
  }
}
