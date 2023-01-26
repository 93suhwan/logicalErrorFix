#include <bits/stdc++.h>
using namespace std;
int n;
long long arr[200011];
long long sum[200011];
bool check(int k) {
  int i;
  for (i = 1; i <= n; i++) sum[i] = 0;
  for (i = n; i >= 3; i--) {
    if (sum[i] + arr[i] < k) return 0;
    long long d = (sum[i] + arr[i] - k) / 3;
    long long d3 = d * 3;
    d3 = min(d3, arr[i]);
    sum[i - 2] += d3 / 3 * 2;
    sum[i - 1] += d3 / 3;
  }
  return sum[2] + arr[2] >= k && sum[1] + arr[1] >= k;
}
int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    int i;
    for (i = 1; i <= n; i++) cin >> arr[i];
    int l = 0, r = 1e9 + 5, mid;
    while (l + 1 < r) {
      mid = l + r >> 1;
      if (check(mid))
        l = mid;
      else
        r = mid;
    }
    cout << l << '\n';
  }
  return 0;
}
