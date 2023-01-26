#include <bits/stdc++.h>
using namespace std;
int main() {
  int ans[1000];
  for (int i = 0, j = 1; i < 1000; ++j) {
    if ((j % 3 != 0) && (j % 10 != 3)) {
      ans[i++] = j;
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int k;
    cin >> k;
    cout << ans[k - 1] << '\n';
  }
  return 0;
}
