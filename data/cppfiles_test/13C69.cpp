#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5, mod = 1e9 + 7;
long long read() {
  bool Minus = false;
  long long result = 0;
  char ch = getchar();
  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }
  if (ch == '-')
    Minus = true;
  else
    result = ch - '0';
  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = result * 10 + (ch - '0');
  }
  return Minus ? -result : result;
}
int solve(int test) {
  string s;
  cin >> s;
  int n = s.size(), cntA = 0, cntB = 0, cntC = 0;
  for (int i = 0; i < n; ++i)
    cntA += (s[i] == 'A'), cntB += (s[i] == 'B'), cntC += (s[i] == 'C');
  cout << (cntA + cntC == cntB ? "YES\n" : "NO\n");
  return 0;
}
int main(int argc, char **argv) {
  freopen("error", "w", stderr);
  int tests = read();
  for (int i = 0; i < tests; ++i) solve(i + 1);
  return 0;
}
