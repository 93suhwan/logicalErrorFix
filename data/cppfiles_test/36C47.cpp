#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "a"
         << "\n";
    return;
  }
  cout << string(n / 2, 'a') + (n & 1 ? "bc" : "b") + string(n / 2 - 1, 'a')
       << "\n";
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
