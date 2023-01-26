#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  map<long long, long long> mp1, mp2;
  vector<pair<long long, long long>> a(n + 1), b(n + 1);
  a[0].first = 0;
  a[0].second = 0;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
    mp1[i] = a[i].first;
  }
  for (long long i = 1; i <= n; ++i) {
    cin >> b[i].first;
    b[i].second = i;
    mp2[i] = b[i].first;
  }
  string s = "0";
  for (long long i = 1; i <= n; ++i) s += "0";
  priority_queue<pair<long long, long long>> pq1, pq2, pqleft1, pqleft2;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  s[b[n].second] = '1';
  s[a[n].second] = '1';
  pq1.push({-mp1[b[n].second], b[n].second});
  pq2.push({-mp2[a[n].second], a[n].second});
  for (long long i = 1; i <= n; ++i) {
    pqleft1.push({a[i].first, a[i].second});
    pqleft2.push({b[i].first, b[i].second});
  }
  while (!pqleft1.empty() && !pqleft2.empty()) {
    long long val1 = -pq1.top().first;
    long long f = 0;
    if (pqleft1.top().first >= val1) {
      if (pqleft1.top().first != val1) {
        s[pqleft1.top().second] = '1';
        pq2.push({-mp2[pqleft1.top().second], pqleft1.top().second});
        f = 1;
      }
      pqleft1.pop();
    }
    long long val2 = -pq2.top().first;
    if (pqleft2.top().first >= val2) {
      if (pqleft2.top().first != val2) {
        s[pqleft2.top().second] = '1';
        pq1.push({-mp1[pqleft2.top().second], pqleft2.top().second});
        f = 1;
      }
      pqleft2.pop();
    }
    if (f == 0) {
      break;
    }
  }
  while (!pqleft1.empty()) {
    long long val1 = -pq1.top().first;
    if (pqleft1.top().first >= val1) {
      s[pqleft1.top().second] = '1';
      pqleft1.pop();
    } else {
      break;
    }
  }
  while (!pqleft2.empty()) {
    long long val2 = -pq2.top().first;
    if (pqleft2.top().first >= val2) {
      s[pqleft2.top().second] = '1';
      pqleft2.pop();
    } else {
      break;
    }
  }
  for (long long i = 1; i <= n; ++i) std::cout << s[i];
  std::cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
}
