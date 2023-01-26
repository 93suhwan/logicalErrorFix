#include <bits/stdc++.h>
using namespace std;
const int maxn = 400505;
const int inf = 0x3f3f3f3f;
int n, m, k;
void YES() {
  cout << "YES"
       << "\n";
}
void NO() {
  cout << "NO"
       << "\n";
}
void solve() {
  cin >> n;
  if (n % 2) {
    cout << n - 1 << ' ' << (n - 1) / 2 << "\n";
  } else {
    cout << 2 << ' ' << n << "\n";
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tn = 1;
  cin >> tn;
  while (tn--) {
    solve();
  }
}
