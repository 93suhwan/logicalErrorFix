#include <bits/stdc++.h>
using namespace std;
long long count_pairs(vector<double> arr, long long n, double sum) {
  unordered_map<double, long long> m;
  long long count = 0;
  for (long long i = 0; i < n; i++) {
    if (m.find(sum - arr[i]) != m.end()) {
      count += m[sum - arr[i]];
    }
    m[arr[i]]++;
  }
  return count;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  for (long long tt = 1; tt <= t; tt++) {
    long long n;
    cin >> n;
    vector<double> a(n);
    double sum = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    double new_sum = 1.0 * ((n - 2) * sum) / n;
    double diff = sum - new_sum;
    long long count = count_pairs(a, n, diff);
    cout << count << '\n';
  }
  return 0;
}
