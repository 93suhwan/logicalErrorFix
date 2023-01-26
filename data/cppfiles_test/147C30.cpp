#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 5, inf = 1e18, mod = 1e9 + 7, mod1 = 1e9 + 3,
                mod2 = 998244353;
const long double eps = 1e-12;
set<long long> adj[N];
long long fastscan() {
  int cc = getc(stdin);
  for (; cc < '0' || cc > '9';) cc = getc(stdin);
  long long ret = 0;
  for (; cc >= '0' && cc <= '9';) {
    ret = ret * 10 + cc - '0';
    cc = getc(stdin);
  }
  return ret;
}
long long powr(long long x, long long n, long long p) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = (res * x) % p;
    x = (x * x) % p;
    n = n / 2;
  }
  return res % p;
}
map<pair<long long, long long>, long long> eg;
long long vis[N];
set<long long> ans;
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long cnt = 0;
    for (auto x : s) {
      if (x == 'N') cnt++;
    }
    if (cnt == 1)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
