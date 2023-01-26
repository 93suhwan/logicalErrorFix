#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  if (n & 1) {
    for (int i = 0; i < n; i++) {
      cout << "a";
    }
  } else {
    for (int i = 0; i < n - 1; i++) {
      cout << "a";
    }
    cout << "b";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
