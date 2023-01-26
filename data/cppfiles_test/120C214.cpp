#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
int pre[50][N], l, r;
int main() {
  for (int bt = 0; bt < 40; bt++)
    for (int i = 1; i < N; i++)
      pre[bt][i] = pre[bt][i - 1] + ((i & (1 << bt)) != 0);
  int T;
  cin >> T;
  while (T--) {
    int ans = 0;
    cin >> l >> r;
    for (int bt = 0; bt < 40; bt++) ans = max(ans, pre[bt][r] - pre[bt][l - 1]);
    cout << r - l + 1 - ans << '\n';
  }
}
