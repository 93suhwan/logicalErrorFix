#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN = 1e5 + 3;
void solve() {
  long long n;
  cin >> n;
  long long ans = 6;
  long long bin = 4;
  for (int i = 1; i < n; i++) {
    bin *= bin;
    bin %= Mod;
    ans *= bin;
    ans %= Mod;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
