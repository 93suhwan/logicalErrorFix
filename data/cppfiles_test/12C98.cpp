#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int kv = n * m / 2 - k;
  if (n & 1) {
    k -= m / 2;
    if (k < 0) {
      cout << "NO" << endl;
      return;
    }
  } else if (m & 1) {
    kv -= n / 2;
    if (kv < 0) {
      cout << "NO" << endl;
      return;
    }
  }
  if (k & 1 || kv & 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}
int main() {
  clock_t time_req = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t != 0) {
    solve();
    t--;
  }
  time_req = clock() - time_req;
  return 0;
}
