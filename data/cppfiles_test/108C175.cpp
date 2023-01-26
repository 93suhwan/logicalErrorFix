#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n + 1), b(n + 1);
  long long maxia = 0, maxIdxa;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] > maxia) {
      maxia = a[i];
      maxIdxa = i;
    }
  }
  long long maxib = 0, maxIdxb;
  for (long long i = 1; i <= n; ++i) {
    cin >> b[i];
    if (b[i] > maxib) {
      maxib = b[i];
      maxIdxb = i;
    }
  }
  string s = "0";
  for (long long i = 1; i <= n; ++i) s += "0";
  priority_queue<pair<long long, long long>> pq1, pq2, pqleft1, pqleft2;
  s[maxIdxa] = '1';
  s[maxIdxb] = '1';
  pq1.push({-a[maxIdxb], maxIdxb});
  pq2.push({-b[maxIdxa], maxIdxa});
  for (long long i = 1; i <= n; ++i) {
    pqleft1.push({a[i], i});
    pqleft2.push({b[i], i});
  }
  while (!pqleft1.empty() && !pqleft2.empty()) {
    long long val1 = -pq1.top().first;
    long long f = 0;
    if (pqleft1.top().first >= val1) {
      if (pqleft1.top().first != val1) {
        s[pqleft1.top().second] = '1';
        pq2.push({-b[pqleft1.top().second], pqleft1.top().second});
        f = 1;
      }
      pqleft1.pop();
    }
    long long val2 = -pq2.top().first;
    if (pqleft2.top().first >= val2) {
      if (pqleft2.top().first != val2) {
        s[pqleft2.top().second] = '1';
        pq1.push({-a[pqleft2.top().second], pqleft2.top().second});
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
