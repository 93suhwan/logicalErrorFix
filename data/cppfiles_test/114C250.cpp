#include <bits/stdc++.h>
using namespace std;
long long int binpow(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans = ans * a;
    }
    a = a * a;
    b >>= 1;
  }
  return ans;
}
long long power(long long a, long long b, long long m) {
  long long ans = 1;
  a = a % m;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
long long mod_Inverse(long long a, long long m) { return power(a, m - 2, m); }
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    vector<pair<int, int>> ans;
    for (int i = 1; i < n; i++) {
      if (a[i] != a[0]) {
        ans.push_back({a[i], a[0]});
      }
    }
    for (int i = 0; i < n / 2; i++)
      cout << ans[i].first << " " << ans[i].second << '\n';
  }
}
