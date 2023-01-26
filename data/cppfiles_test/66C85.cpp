#include <bits/stdc++.h>
using namespace std;
void run() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void solve() {
  int n;
  cin >> n;
  int val = 0;
  while (n > 0) {
    val++;
    if (val % 10 != 3 && val % 3 != 0) {
      n--;
    }
  }
  cout << val;
}
int main() {
  run();
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
