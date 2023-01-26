#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 10;
const int LOG = 20;
const long long inf = 1e16;
long long pdr[MAX_N];
bool seen;
vector<pair<int, int> > v;
long long d[MAX_N], pain[MAX_N];
long long ans, endd[MAX_N], av[MAX_N];
long long t, n, p;
bool check(long long a, long long b) {
  for (int i = 0; i < n - 1; i++) {
    b -= min(a, pdr[i + 1] - pdr[i]);
  }
  b -= a;
  if (b <= 0)
    return true;
  else
    return false;
}
long long binry(long long l, long long r) {
  long long mid;
  while (l < r) {
    mid = (l + r) / 2;
    if (check(mid, p))
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  set<long long> st;
  cin >> t;
  while (t--) {
    cin >> n >> p;
    for (int i = 0; i < n; i++) cin >> pdr[i];
    ans = binry(1, p);
    cout << ans << '\n';
  }
}
