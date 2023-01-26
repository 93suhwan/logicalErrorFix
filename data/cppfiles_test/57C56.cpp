#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  ll s, n, k;
  cin >> s >> n >> k;
  if (s == k)
    cout << "YES\n";
  else if (s < k)
    cout << "NO\n";
  else {
    s -= n;
    ll need = (n / k) * k;
    cout << (s >= need ? "NO" : "YES") << '\n';
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}
