#include <bits/stdc++.h>
using namespace std;
const int c = 100005;
long long n;
vector<long long> a;
bool read() {
  if (!(cin >> n)) return false;
  a.resize(n + 1);
  for (long long i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  return true;
}
vector<pair<long long, long long>> pcave;
bool check(long long p) {
  long long currp = p;
  for (long long i = 0; i < n; ++i) {
    if (pcave[i].first <= currp) {
      currp += pcave[i].second;
    } else
      return false;
  }
  return true;
}
long long binary_Search(long long b, long long e) {
  long long ans = 1e18;
  while (b <= e) {
    long long mid = b + (e - b) / 2;
    if (check(mid)) {
      e = mid - 1;
      ans = min(ans, mid);
    } else
      b = mid + 1;
  }
  return ans;
}
void solve() {
  pcave.clear();
  cin >> n;
  pcave.resize(n);
  vector<vector<long long>> v(n);
  for (long long i = 0; i < n; ++i) {
    long long k;
    cin >> k;
    vector<long long> temp(k);
    long long maxxp = -1;
    for (long long j = 0; j < k; ++j) {
      cin >> temp[j];
      maxxp = max(temp[j] - j + 1, maxxp);
    }
    v[i] = temp;
    pcave[i] = {maxxp, k};
  }
  sort(pcave.begin(), pcave.end());
  cout << binary_Search(pcave[0].first, pcave[n - 1].first) << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
