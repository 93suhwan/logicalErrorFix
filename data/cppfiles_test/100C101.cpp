#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int T, N;
int A[200001];
long long Fact[200001], Inv_Fact[200001];
long long my_pow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = (ret * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ret;
}
void solve() {
  int Max = 0, max_cnt = 0, almost_max_cnt = 0;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    Max = max(Max, A[i]);
  }
  for (int i = 1; i <= N; i++) {
    if (A[i] == Max) max_cnt++;
  }
  if (max_cnt > 1) {
    cout << Fact[N] << "\n";
    return;
  }
  for (int i = 1; i <= N; i++) {
    if (A[i] == Max - 1) almost_max_cnt++;
  }
  if (!almost_max_cnt) {
    cout << "0\n";
    return;
  }
  long long ans = (Fact[N] - Fact[almost_max_cnt] * Fact[N] % MOD *
                                 Inv_Fact[almost_max_cnt + 1] % MOD) %
                  MOD;
  if (ans < 0) ans += MOD;
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  Fact[0] = 1;
  for (int i = 1; i <= 200000; i++) Fact[i] = (Fact[i - 1] * i) % MOD;
  Inv_Fact[200000] = my_pow(Fact[200000], MOD - 2);
  for (int i = 199999; i >= 0; i--)
    Inv_Fact[i] = Inv_Fact[i + 1] * (i + 1) % MOD;
  cin >> T;
  while (T--) solve();
  return 0;
}
