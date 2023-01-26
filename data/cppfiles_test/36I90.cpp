#include <bits/stdc++.h>
using namespace std;
int dp[100001] = {
    0,
};
int dpr[100001] = {
    0,
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int x;
    cin >> x;
    if (x == 3) {
      cout << "abc\n";
    } else {
      int d = x / 2;
      for (int i = 0; i < d - 1; i++) {
        cout << 'a';
      }
      cout << 'b';
      for (int i = 0; i < d; i++) {
        cout << 'a';
      }
      if (d & 1) cout << 'c';
      cout << '\n';
    }
  }
  return 0;
}
