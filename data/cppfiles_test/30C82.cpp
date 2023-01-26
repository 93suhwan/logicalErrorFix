#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e9 + 7;
const int N = 1e5 + 1;
const int inf = 0x3f3f3f3f;
long long f[N], gold[N];
long long Find(long long x) { return f[x] == x ? x : f[x] = Find(f[x]); }
void Union(long long x, long long y) {
  long long fx = Find(x);
  long long fy = Find(y);
  if (fx == fy)
    return;
  else
    f[fy] = fx;
}
long long ksm(long long a, long long n) {
  long long cnt = 1;
  while (n) {
    if (n & 1) cnt = (cnt * a);
    a = (a * a);
    n >>= 1;
  }
  return cnt;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, flag = 1, ans = MAXN;
    string s;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n / 2; i++) {
      if (s[i] != s[n - i - 1]) {
        flag = 0;
      }
    }
    if (flag) {
      cout << 0 << endl;
      continue;
    }
    for (int i = 0; i < 26; i++) {
      char c = 'a' + i;
      int cnt = 0;
      flag = 1;
      int l = 0, r = n - 1;
      while (l < r) {
        if (s[l] != s[r]) {
          if (s[l] == c)
            l++, cnt++;
          else if (s[r] == c)
            r--, cnt++;
          else {
            flag = 0;
            break;
          }
        } else
          l++, r--;
      }
      if (flag) ans = min(ans, cnt);
    }
    if (ans == MAXN)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
