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
  vector<long long> seat;
  for (long long i = 0; i <= ub; i++) {
    long long remain = n - i * lb;
    if (remain % ub == 0) {
      for (long long j = 0; j < i; j++) seat.push_back(lb);
      for (long long j = 0; j < (remain / ub); j++) seat.push_back(ub);
      break;
    }
  }
  priority_queue<pair<long long, long long>> pq;
  for (long long i = 0; i < n; i++) pq.push({0, i});
  while (k--) {
    priority_queue<pair<long long, long long>> temp;
    for (auto &x : seat) {
      cout << x << ' ';
      for (long long i = 0; i < x; i++) {
        long long p = pq.top().first, u = pq.top().second;
        pq.pop();
        p += (x == ub);
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
