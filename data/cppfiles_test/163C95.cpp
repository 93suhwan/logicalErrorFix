#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1000000007;
inline long long Qpow(long long x, long long p) {
  long long Res = 1;
  while (p) {
    if (p & 1) Res = Res * x % Mod;
    x = x * x % Mod;
    p >>= 1;
  }
  return Res;
}
signed main(void) {
  ios::sync_with_stdio(false);
  long long Case = 1;
  cin >> Case;
  while (Case--) {
    long long N, M, A, B, C, D;
    cin >> N >> M >> A >> B >> C >> D;
    vector<vector<vector<long long> > > Vis(N + 3);
    for (long long i = 0; i <= N + 2; i++)
      Vis[i] = vector<vector<long long> >(M + 3);
    for (long long i = 0; i <= N + 2; i++)
      for (long long j = 0; j <= M + 2; j++) Vis[i][j] = vector<long long>(4);
    vector<long long> Anss;
    long long CN = 1, CM = 1, Ans = 0, dD = 0;
    while (1) {
      if (A == N) CN = -1;
      if (A == 1) CN = 1;
      if (B == M) CM = -1;
      if (B == 1) CM = 1;
      if (CN > 0 && CM > 0)
        dD = 0;
      else if (CN > 0)
        dD = 1;
      else if (CM > 0)
        dD = 2;
      else
        dD = 3;
      if (Vis[A][B][dD]) break;
      Vis[A][B][dD] = 1;
      if (A == C || B == D) Anss.push_back(Ans);
      Ans++;
      A += CN;
      B += CM;
    }
    long long Sol = Anss.size();
    long long Once = 0, Prob = 1;
    long long P;
    cin >> P;
    P = P * Qpow(100, Mod - 2) % Mod;
    for (long long i = 0; i < Anss.size(); i++) {
      Once = (Once + Prob * P % Mod * Anss[i]) % Mod;
      Prob = Prob * (Mod + 1 - P) % Mod;
    }
    P = Qpow((Mod + 1 - P), Sol);
    D = Mod + 1 - P;
    assert(P == Prob);
    long long Rr = Once * Qpow(Mod + 1 - P, Mod - 2) % Mod;
    long long T2 = Ans * Qpow(Mod + 1 - P, Mod - 2) % Mod * P % Mod;
    cout << (Rr + T2) % Mod << '\n';
  }
  return 0;
}
