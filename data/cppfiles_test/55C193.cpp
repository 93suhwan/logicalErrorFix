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
const int maxn{(int)(3e5 + 11)};
const long long MOD{(long long)(1e9 + 7)};
int k;
void Solve_case() {
  cin >> k;
  if (k == 1) {
    cout << '6' << '\n';
    return;
  }
  long long now = 16;
  for (int i = (int)(2); i <= (int)(k - 1); ++i) {
    now = (4 * now) % MOD;
    now = now * now % MOD;
  }
  cout << (6 * now) % MOD << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T_T = 1;
  while (T_T--) {
    Solve_case();
  }
  return 0;
}
