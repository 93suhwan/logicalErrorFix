#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x, n;
  cin >> n;
  priority_queue<pair<long long, long long>> pq;
  vector<long long> a(n + 1);
  for (long long i = 0; i < n; ++i) {
    cin >> x;
    a[x]++;
  }
  long long j;
  vector<long long> mex(n + 1);
  for (long long i = 0; i <= n; ++i) {
    if (a[i] != 0) {
      mex[i] = a[i];
      if (a[i] > 1) pq.push({i, a[i]});
    } else {
      j = i;
      break;
    }
  }
  long long store = n + 1;
  long long sum = 0;
  for (long long k = j + 1; k <= n; ++k) {
    if (a[k - 1] == 0) {
      if (pq.empty()) {
        store = k;
        break;
      }
      long long get = pq.top().first;
      mex[k] = sum + k - 1 - get;
      long long val = pq.top().second;
      val--;
      pq.pop();
      if (val > 1) {
        pq.push({get, val});
      }
      sum = mex[k];
    }
    if (a[k] != 0) {
      mex[k] = a[k] + sum;
      if (a[k] > 1) {
        pq.push({k, a[k]});
      }
    } else {
      mex[k] = sum;
    }
  }
  for (long long k = store; k <= n; ++k) {
    mex[k] = -1;
  }
  for (long long i = 0; i <= n; ++i) cout << mex[i] << ' ';
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
}
