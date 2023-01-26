#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, long long> p, pair<long long, long long> q) {
  if (p.first != q.first)
    return p.first > q.first;
  else
    return p.second < q.second;
}
long long myfun(char ch, long long n, vector<string> v) {
  vector<pair<long long, long long>> va;
  long long total = 0;
  long long totmx = 0;
  for (long long i = 0; i < n; i++) {
    long long N = v[i].size();
    long long cnt = 0;
    for (long long j = 0; j < v[i].size(); j++) {
      if (ch != v[i][j]) cnt++;
    }
    total += cnt;
    totmx += (N - cnt);
    va.push_back({cnt, N - cnt});
  }
  if (totmx > total) {
    return n;
  }
  sort(va.begin(), va.end(), cmp);
  long long i;
  for (i = 0; i < n; i++) {
    long long x = va[i].first;
    long long y = va[i].second;
    total -= x;
    totmx -= y;
    if (totmx > total) {
      return (n - (i + 1));
    }
  }
  long long val = 0;
  return val;
}
void solve() {
  long long n;
  cin >> n;
  vector<string> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long a = myfun('a', n, v);
  long long b = myfun('b', n, v);
  long long c = myfun('c', n, v);
  long long d = myfun('d', n, v);
  long long e = myfun('e', n, v);
  long long ans = max(a, max(b, c));
  ans = max(ans, max(d, e));
  cout << ans << endl;
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
