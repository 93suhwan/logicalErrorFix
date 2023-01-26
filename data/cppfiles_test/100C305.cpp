#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (auto &x : a) cin >> x;
    ;
    sort(a, a + n);
    long long val = a[0];
    priority_queue<long long> pq;
    pq.push(val);
    for (long long i = 1; i < n; ++i) {
      pq.push(a[i] - val);
      val = a[i];
    }
    cout << pq.top() << "\n";
  }
  return 0;
}
