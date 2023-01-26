#include <bits/stdc++.h>
const int INF = 1000000000;
using namespace std;
void solve() {
  int n;
  cin >> n;
  if (n & 1) {
    cout << 2 << " " << n - 1;
  } else {
    cout << 2 << " " << n / 2;
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
