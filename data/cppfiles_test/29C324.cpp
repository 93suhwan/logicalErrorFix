#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int one = 0;
    int zer = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      one += x == 1;
      zer += x == 0;
    }
    cout << one * 1LL * (1LL << zer) << '\n';
  }
  return 0;
}
