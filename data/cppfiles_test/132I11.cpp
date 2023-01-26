#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 4;
const int M = 1e9 + 7;
void solve() {
  int ar[7];
  for (int i = 0; i < 7; i++) {
    cin >> ar[i];
    if (i < 3) {
      cout << ar[i] << " ";
    }
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
