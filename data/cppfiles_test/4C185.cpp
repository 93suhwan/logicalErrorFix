#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  unordered_map<int, int> mp;
  int ans = -1, a;
  for (int i = 2; i <= n; i++) {
    if (mp.find(n % i) == mp.end())
      mp[n % i] = i;
    else {
      ans = n % i;
      a = i;
      break;
    }
  }
  cout << mp[ans] << " " << a << "\n";
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
