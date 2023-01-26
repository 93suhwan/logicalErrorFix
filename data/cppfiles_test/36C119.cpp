#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, sum = 0;
    cin >> n;
    vector<long long> v(n), ans, odd;
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
      if (v[i] % 2 == 0) {
        ans.push_back(i);
      } else
        odd.push_back(i);
      sum += v[i];
    }
    long long count = 0;
    for (long long i = 2; i * i <= sum; i++) {
      if (sum % i == 0) count++;
    }
    if (count > 0) {
      cout << n << endl;
      for (long long i = 0; i < n; i++) cout << i + 1 << " ";
    } else {
      cout << n - 1 << endl;
      odd.pop_back();
      for (long long i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << " ";
      }
      for (long long i = 0; i < odd.size(); i++) {
        cout << odd[i] + 1 << " ";
      }
    }
    cout << endl;
  }
}
