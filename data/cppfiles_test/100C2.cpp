#include <bits/stdc++.h>
using namespace std;
const long long INF = 2 * 1e18;
signed main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long N;
    cin >> N;
    long long i, j;
    priority_queue<long long, vector<long long>, greater<long long> > PQ;
    for (i = 0; i < N; i++) {
      cin >> j;
      PQ.push(j);
    }
    long long ma = PQ.top();
    long long mi = 0;
    while (PQ.size() >= 2) {
      long long t = PQ.top();
      mi += t - mi;
      PQ.pop();
      ma = max(ma, PQ.top() - mi);
    }
    cout << ma << '\n';
  }
}
