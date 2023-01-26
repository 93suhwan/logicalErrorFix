#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
const int c = pow(10, 9) + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n), copy(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    int ans = 0;
    copy = v;
    sort(copy.begin(), copy.end());
    while (copy != v) {
      ans++;
      if (ans & 1) {
        for (int i = 0; i < n - 2; i += 2) {
          if (i + 1 < n && v[i] > v[i + 1]) swap(v[i], v[i + 1]);
        }
      } else {
        for (int i = 1; i < n; i += 2) {
          if (i + 1 < n && v[i] > v[i + 1]) swap(v[i], v[i + 1]);
        }
      }
    }
    cout << ans << endl;
  }
}
