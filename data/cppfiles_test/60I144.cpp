#include <bits/stdc++.h>
using namespace std;
long long twoSum(long long A[], int n, double sum) {
  long long ans = 0;
  unordered_map<double, int> mp;
  for (int i = 0; i < n; ++i) {
    int target = sum - A[i];
    ans += mp[target];
    mp[A[i]]++;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long a[n], sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    double target = ((1.0 * sum * (n - 2)) / n);
    cout << twoSum(a, n, sum - target) << "\n";
  }
  return 0;
}
