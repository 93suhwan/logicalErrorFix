#include <bits/stdc++.h>
using namespace std;
int c = 0, i = 0;
int t;
int ans[1001];
int main(void) {
  cin >> t;
  while (c < 1000) {
    i++;
    if (((i % 3) != 0) && ((i % 10) != 3)) ans[++c] = i;
  }
  while (t--) {
    cin >> c;
    cout << ans[c] << endl;
  }
  return 0;
}
