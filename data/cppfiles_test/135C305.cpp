#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long int INF = 1e18;
const int N = 2e5 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n - 2 * k; i++) ans += v[i];
    map<int, int> mp;
    for (int i = n - 2 * k; i < n; i++) mp[v[i]]++;
    for (auto [a, b] : mp) ans += max(0, b - k);
    cout << ans << "\n";
  }
  return 0;
}
