#include <bits/stdc++.h>
using namespace std;
void solve();
int q;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << n - 2 * n / 3 << " " << n / 3 << endl;
  }
}
