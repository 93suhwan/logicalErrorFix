#include <bits/stdc++.h>
using namespace std;
void solve(long long a[], long long n, long long k, long long sum) {
  vector<long long> v;
  long long p = INT_MAX, cnt = 0;
  for (long long i = 1; i < n; i++) v.push_back(a[i] - a[0]);
  while (sum > k && v.size()) {
    p = min(cnt + (sum - k + cnt) / (cnt + 1), p);
    sum -= v.back(), cnt++;
    v.pop_back();
  }
  if (sum > k) cnt += (sum - k + cnt) / (cnt + 1);
  cout << min(cnt, p) << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n], sum = 0;
    for (auto &it : a) {
      cin >> it;
      sum += it;
    }
    sort(a, a + n);
    if (n == 1) {
      if (a[0] <= k)
        cout << "0\n";
      else
        cout << a[0] - k << "\n";
    } else
      solve(a, n, k, sum);
  }
}
