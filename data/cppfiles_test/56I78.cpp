#include <bits/stdc++.h>
using namespace std;
long long orz = 1000000007LL;
char color[10];
map<long long, int> s;
int k;
long long qpower(long long a, long long b, long long p) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return ans;
}
void path(long long x) {
  while (1) {
    if (s.find(x) == s.end()) s[x] = 100;
    if (x == 1) break;
    x /= 2LL;
  }
}
long long dfs(long long x, int level) {
  if (x >= (1LL << k)) return 0;
  if (s.find(x) == s.end()) return qpower(4LL, (1LL << (k - level)) - 1LL, orz);
  long long i, flag,
      cnt = 0,
      ret = (dfs(x * 2LL, level + 1) * dfs(x * 2 + 1LL, level + 1)) % orz;
  if (x * 2 >= (1LL << k)) ret = 1;
  for (i = 0; i < 6; i++) {
    flag = 1;
    if (s[x] != 100 && s[x] != i) flag = 0;
    if (x > 1 && s[x / 2] != 100) {
      if (s[x / 2] == i || s[x / 2] + i == 5) flag = 0;
    }
    if (x * 2LL < (1LL << k)) {
      if (s.find(x * 2LL) != s.end() && (s[x * 2] == i || s[x * 2] + i == 5))
        flag = 0;
      if (s.find(x * 2LL + 1) != s.end() &&
          (s[x * 2 + 1] == i || s[x * 2 + 1] + i == 5))
        flag = 0;
    }
    cnt += flag;
  }
  return (ret * cnt) % orz;
}
int main() {
  int n, i, c;
  long long ans, j;
  cin >> k >> n;
  for (i = 0; i < n; i++) {
    scanf("%lld%s", &j, color);
    if (color[0] == 'w')
      c = 0;
    else if (color[0] == 'y')
      c = 5;
    else if (color[0] == 'g')
      c = 1;
    else if (color[0] == 'b')
      c = 4;
    else if (color[0] == 'r')
      c = 2;
    else
      c = 3;
    s[j] = c;
    path(j);
  }
  ans = dfs(1, 0);
  cout << ans;
  return 0;
}
