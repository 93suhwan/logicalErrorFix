#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long int tt, n, i, ans;
  tt = 1;
  cin >> tt;
  while (tt--) {
    cin >> n;
    vector<long long int> v(n), mx(n);
    for (i = 0; i < n; i++) cin >> v[i];
    mx[n - 1] = v[n - 1];
    for (i = n - 2; i >= 0; i--) mx[i] = max(mx[i + 1], v[i]);
    set<long long int> s;
    for (i = 0; i < n; i++) s.insert(mx[i]);
    ans = s.size() - 1;
    cout << ans << "\n";
  }
  return 0;
}
