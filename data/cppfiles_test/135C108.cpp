#include <bits/stdc++.h>
using namespace std;
long long x;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long gcd_arr(vector<long long> &a) {
  if (a.size() == 1) return a[0];
  long long g = gcd(a[0], a[1]);
  for (size_t i = 2; i < a.size(); i++) g = gcd(g, a[i]);
  return g;
}
set<pair<int, pair<int, int>>> s;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for (size_t i = 0; i < n; i++) {
      cin >> x;
      a.push_back(x);
    }
    std::sort(a.begin(), a.end());
    vector<int> b;
    for (size_t i = n - 2 * k; i < n; i++) {
      b.push_back(a[i]);
    }
    int ans = 0;
    for (size_t i = 0; i < n - 2 * k; i++) ans += a[i];
    for (size_t i = 0; i < b.size() / 2; i++) ans += b[i] / b[i + k];
    cout << ans << "\n";
  }
  return 0;
}
