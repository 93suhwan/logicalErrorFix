#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long arr[m];
    long long count = 0;
    multiset<long long> s;
    for (long long i = 0; i < m; i++) {
      cin >> arr[i];
    }
    for (long long i = 0; i < m; i++) {
      auto it = s.lower_bound(arr[i]);
      long long pos = distance(s.begin(), it);
      count += pos;
      s.insert(arr[i]);
    }
    cout << count << "\n";
  }
}
