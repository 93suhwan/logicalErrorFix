#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long lb = n / m;
  long long ub = (n + m - 1) / m;
  long long extra = (n % m);
  vector<long long> seat;
  for (long long i = 0; i < (n + lb - 1) / lb - (extra != 0); i++)
    seat.push_back(lb);
  for (long long i = 0; i < seat.size() && extra > 0; i++, extra--) seat[i]++;
  sort(seat.begin(), seat.end());
  priority_queue<pair<long long, long long>> pq;
  for (long long i = 0; i < n; i++) pq.push({0, i});
  while (k--) {
    priority_queue<pair<long long, long long>> temp;
    for (auto &x : seat) {
      cout << x << ' ';
      for (long long i = 0; i < x; i++) {
        long long p = pq.top().first, u = pq.top().second;
        pq.pop();
        p += (x != lb);
        cout << (u + 1) << " \n"[i == x - 1];
        temp.push({p, u});
      }
    }
    pq = temp;
  }
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
