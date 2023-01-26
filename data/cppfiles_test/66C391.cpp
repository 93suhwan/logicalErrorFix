#include <bits/stdc++.h>
using namespace std;
int main() {
  int ans[1001];
  int p = 1;
  for (int i = 1; i <= 1666; i++) {
    if (i % 3 != 0) {
      int x = i % 10;
      if (x != 3) {
        ans[p] = i;
        p++;
      }
    }
  }
  long long t;
  cin >> t;
  while (t != 0) {
    int k;
    cin >> k;
    cout << ans[k] << endl;
    t--;
  }
  return 0;
}
