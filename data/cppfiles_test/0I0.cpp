#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
const long long inf = 0x3f3f3f3f3f3f3f3fLL;
long long N = 3e5 + 10;
const long long MOD = 1e9 + 7;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  string s;
  vector<pair<long long, long long>> a;
  for (long long i = 0; i < n; i++) {
    cin >> s;
    long long c = 0;
    for (long long j = 0; j < m; j++) {
      if (j & 1)
        c -= (s[j] - 'A');
      else
        c += (s[j] - 'A');
    }
    a.emplace_back(c, i);
  }
  sort(a.begin(), a.end());
  for (auto i : a) cout << i.second + 1 << ' ';
  cout << '\n';
  return 0;
}
