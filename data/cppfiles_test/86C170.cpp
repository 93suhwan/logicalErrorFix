#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
long long mul(long long a, long long b) { return (a * b) % (1000000007); }
long long add(long long a, long long b) { return (a + b) % (1000000007); }
long long sub(long long a, long long b) {
  return ((a - b) % (1000000007) + (1000000007)) % (1000000007);
}
void upd(long long &a, long long b) {
  a = (a % (1000000007) + b % (1000000007)) % (1000000007);
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
string s, s2;
int n;
int mex(int l, int r) {
  bool fl0 = 0, fl1 = 0;
  for (int i = l; i <= r; i++) {
    if (s[i] == '0')
      fl0 = 1;
    else
      fl1 = 1;
    if (s2[i] == '0')
      fl0 = 1;
    else
      fl1 = 1;
  }
  if (!fl0)
    return 0;
  else if (!fl1)
    return 1;
  else
    return 2;
}
int f[512345];
int main() {
  int T = read();
  while (T--) {
    n = read();
    cin >> s >> s2;
    int n = s.length();
    f[0] = mex(0, 0);
    for (int i = 1; i <= n - 1; i++) {
      f[i] = f[i - 1] + mex(i, i);
      if (i > 1) f[i] = max(f[i], f[i - 2] + mex(i - 1, i));
      if (i == 1) f[i] = max(f[i], mex(i - 1, i));
    }
    cout << f[n - 1] << endl;
  }
  return 0;
}
