#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  long long ans = 1;
  for (int i = 1; i <= 2 * n; i++) {
    ans = ans * (i);
  }
  cout << (ans / 2) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt;
  cin >> tt;
  for (int i = 0; i < tt; i++) {
    solve();
    cout << endl;
  }
}
