#include <bits/stdc++.h>
using namespace std;
unordered_map<int, bool> mp;
bool isPrime(int n) {
  if (mp[n] == 1) return 1;
  int i;
  for (i = 2; i <= sqrt(n); i++) {
    if ((n % i) == 0) {
      return false;
    }
  }
  mp[n] = 1;
  return true;
}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n + 5);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  sort(v.begin() + 1, v.begin() + 1 + n);
  int ans = 0, i = 1;
  for (; i <= n; i++) {
    if (v[i] == i) continue;
    if ((v[i] & 1 && v[i] / 2 >= i) || (v[i] % 2 == 0 && v[i] / 2 > i)) {
      ans += 1;
      continue;
    } else {
      break;
    }
  }
  if (i == n + 1)
    cout << ans << endl;
  else {
    cout << -1 << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
