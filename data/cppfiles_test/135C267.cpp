#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    long long sum = 0;
    for (long long i = 0; n - k + i < n; i++) {
      sum += v[n - 2 * k + i] / v[n - k + i];
    }
    for (long long i = 0; i < n - 2 * k; i++) {
      sum += v[i];
    }
    cout << sum;
    cout << "\n";
  }
  return 0;
}
