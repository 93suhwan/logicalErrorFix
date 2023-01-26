#include <bits/stdc++.h>
using namespace std;
int add(int x, int y) {
  x += y;
  if (x >= 998244353) x -= 998244353;
  return x;
}
void main0() {
  int n;
  cin >> n;
  vector<int> dp1(n + 2, 0), dp2(n + 2, 0);
  dp1[0] = 1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    dp1[x + 1] = add(dp1[x + 1], dp1[x + 1]);
    dp1[x + 1] = add(dp1[x + 1], dp1[x]);
    if (x > 0) {
      dp2[x - 1] = add(dp2[x - 1], dp2[x - 1]);
      dp2[x - 1] = add(dp2[x - 1], dp1[x - 1]);
    }
    dp2[x + 1] = add(dp2[x + 1], dp2[x + 1]);
  }
  int ans = 0;
  for (int i = 0; i < n + 2; i++) ans = add(ans, dp1[i]);
  for (int i = 0; i < n + 2; i++) ans = add(ans, dp2[i]);
  cout << add(ans, 998244353 - 1) << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) main0();
  return 0;
}
