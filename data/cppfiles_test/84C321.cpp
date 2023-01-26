#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
void solve() {
  int n, s;
  cin >> n >> s;
  if (n == 1) {
    cout << s << "\n";
    return;
  }
  int val = n - n / 2 + 1;
  if (n & 1) val--;
  cout << s / val << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
