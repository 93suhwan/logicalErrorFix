#include <bits/stdc++.h>
using namespace std;
long long squared(long long x) { return (x * x) % 1000000007; }
long long factorial(long long n) {
  long long res = 1;
  for (long long i = 1; i <= n; i++) {
    res = ((res * i) % 1000000007 + 1000000007) % 1000000007;
  }
  return res;
}
long long power(long long x, long long p) {
  if (p == 0) {
    return 1;
  }
  if (p % 2 == 1) {
    return (power(x, p - 1) * x) % 1000000007;
  }
  return squared(power(x, p / 2));
}
void main_solve() {
  long long n;
  long long h;
  cin >> n >> h;
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    v.push_back(x);
  }
  if (h <= n) {
    cout << 1 << ("\n");
    return;
  } else if (n == 1) {
    cout << h << ("\n");
    return;
  }
  vector<long long> nums;
  for (long long i = 1; i < n; i++) {
    nums.push_back(v[i] - v[i - 1]);
  }
  sort(nums.begin(), nums.end());
  long long k = 0;
  long long y = h / n;
  if (h % n != 0) {
    y++;
  }
  for (long long i = 0; i < n - 1; i++) {
    if (nums[i] < y) {
      h -= nums[i];
      long long q = (n - i - 1);
      y = h / q;
      if (h % q != 0) {
        y++;
      }
    } else {
      h -= y;
    }
    k = max(k, y);
  }
  cout << k << ("\n");
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    main_solve();
  }
}
