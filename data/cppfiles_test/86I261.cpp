#include <bits/stdc++.h>
using namespace std;
const int iinf = 1e9 + 7;
const long long int inf = 1e9 + 7;
const long long int mod = 998244353;
const long long int maxn = 2e5 + 5;
long long int sqr(long long int x) { return x * x; }
long long int modd(long long int a) {
  if (a > 0) return a % inf;
  while (a < 0) {
    a += inf;
  }
  return a;
}
long long int modexpo(long long int a, long long int b, long long int iinf1) {
  a %= iinf1;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % iinf1;
    a = a * a % iinf1;
    b >>= 1;
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  string s, s1;
  cin >> s >> s1;
  long long int ans = 0;
  int prev;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] != s1[i]) {
      ans += 2;
    } else {
      if (s[i + 1] == s1[i + 1] && s[i] != s[i + 1]) {
        ans += 2;
        i++;
        prev = i;
      } else {
        if (s[i] == '0') {
          ans += 1;
        }
      }
    }
  }
  if (prev < n - 1) {
    if (s[n - 1] != s1[n - 1]) {
      ans += 2;
    } else {
      if (s[n - 1] == '0') ans++;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
