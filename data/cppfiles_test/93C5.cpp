#include <bits/stdc++.h>
using namespace std;
long long t, n, k;
void solve() {
  long long ris = 0;
  long long tot = 1, act = 1;
  while (act < k && tot < n) {
    ris++;
    tot += act;
    act = min(k, act + act);
  }
  if (tot >= n)
    cout << ris << "\n";
  else
    cout << ris + (n - tot + k - 1) / k << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    solve();
  }
}
