#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
const long long N = 1000007, M = 1e7, SZ = 1e5 + 5, md = 1e9 + 7,
                mds = 998244353, inf = 1e9 + 5, linf = 2e18 + 5, lgN = 21,
                MX = 3e5, aA = 'a' - 'A';
stack<int> stk;
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
long long b[N], d[N], w, h, x, qry, y, z, l, r, cnt, res, tmp, num, n, m, k, T;
pair<long long, long long> a[N];
string s;
vector<int> g[N];
bool c[N];
unordered_map<long long, long long> mp, mp2;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> k;
    for (long long i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
    mp.clear();
    for (long long i = 0; i < n; i++) d[i] = 0, mp[a[i].first]++;
    x = 0;
    for (auto i : mp) x += min(i.second, k);
    x = x / k;
    x = x * k;
    sort(a, a + n);
    for (long long i = 0; i < n; i++) {
      if (!x) break;
      if (mp[a[i].first]) {
        mp[a[i].first]--;
        d[a[i].second] = x % k + 1;
        x--;
      }
    }
    for (long long i = 0; i < n; i++) cout << d[i] << ' ';
    cout << '\n';
  }
}
