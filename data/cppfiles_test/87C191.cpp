#include <bits/stdc++.h>
using namespace std;
long long num[105];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> num[i];
  long long dex = 0;
  for (long long i = 1; i <= n; i++) {
    if (num[i] <= i + dex) {
      continue;
    }
    dex += num[i] - (i + dex);
  }
  cout << dex << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
