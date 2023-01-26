#include <bits/stdc++.h>
using namespace std;
void minz(long long &A, long long B) {
  if (A > B) A = B;
  return;
}
void maxz(long long &A, long long B) {
  if (A < B) A = B;
  return;
}
const int maxn{(int)(1e3 + 2911)};
const int MOD{(int)(123457)};
int inc[3] = {1, 2, 3};
int ina[3];
void Solve_case() {
  int a, b, c;
  cin >> a >> b >> c;
  ina[0] = a % 2;
  ina[1] = b % 2;
  ina[2] = c % 2;
  int A, B, ans = -1;
  for (int x = (int)(0); x <= (int)(7); ++x) {
    A = 0;
    B = 0;
    for (int i = (int)(0); i <= (int)(2); ++i) {
      if (((x >> i) & (int)(1)))
        A += inc[i] * ina[i];
      else
        B += inc[i] * ina[i];
    }
    if (ans == -1)
      ans = abs(A - B);
    else
      ans = min(ans, abs(A - B));
  }
  cout << ans << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int sub;
  int T_T = 1;
  cin >> T_T;
  while (T_T--) {
    Solve_case();
  }
  return 0;
}
