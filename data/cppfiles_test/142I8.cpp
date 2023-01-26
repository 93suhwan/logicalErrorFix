#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
  if (x == 0) return y;
  return (gcd(y % x, x));
}
string Tolower(string s) {
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}
string Toupper(string s) {
  transform(s.begin(), s.end(), s.begin(), ::toupper);
  return s;
}
void solve() {
  long long t;
  cin >> t;
  while (t--) {
    long long m, n, ans = -1, l, r, mid;
    cin >> m >> n;
    vector<vector<long long>> a(m);
    set<long long> s;
    vector<long long> b;
    for (long long i = 0; i < m; i++) {
      for (long long j = 0; j < n; j++) {
        long long x;
        cin >> x;
        a[i].push_back(x);
        s.insert(x);
      }
    }
    for (auto x : s) b.push_back(x);
    l = 0, r = b.size() - 1;
    while (l <= r) {
      mid = l + (r - l) / 2;
      bool f = true;
      map<long long, long long> make_pair;
      for (long long i = 0; i < m; i++) {
        for (long long j = 0; j < n; j++) {
          if (a[i][j] >= b[mid]) make_pair[i]++;
        }
      }
      vector<long long> temp;
      for (auto x : make_pair) temp.push_back(x.second);
      sort((temp).begin(), (temp).end(), greater<int>());
      long long sum = 0;
      for (long long i = 0; i < n - 1; i++) {
        sum += temp[i];
      }
      if (sum >= n)
        f = true;
      else
        f = false;
      if (f) {
        ans = b[mid];
        l = mid + 1;
      } else
        r = mid - 1;
    }
    if (n - 1 >= m) {
      ans = 1e9;
      for (long long i = 0; i < n; i++) {
        long long mx = -1;
        for (long long j = 0; j < m; j++) {
          mx = max(mx, a[j][i]);
        }
        ans = min(ans, mx);
      }
    }
    cout << ans << "\n";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
