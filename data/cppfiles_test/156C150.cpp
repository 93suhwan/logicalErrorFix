#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long pow1(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  if (b == 1) {
    return a % mod;
  }
  if (b % 2 == 0) {
    return pow1((a * a) % mod, b / 2) % mod;
  }
  return (a * pow1(a, b - 1)) % mod;
}
int main() {
  mt19937 ll(time(0));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (t; t > 0; --t) {
    long long n, k;
    cin >> n >> k;
    vector<long long> s(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
      sum += s[i];
    }
    if (sum <= k) {
      cout << 0 << '\n';
      continue;
    }
    sort(s.begin(), s.end());
    long long min1;
    long long l = sum - k;
    int j = n - 1;
    for (long long i = 1; i < n; ++i) {
      sum = sum - s[j] + s[0];
      l = min(l, max((long long)0, (sum + i - k) / (i + 1)) + i);
      --j;
    }
    cout << l << '\n';
  }
}
