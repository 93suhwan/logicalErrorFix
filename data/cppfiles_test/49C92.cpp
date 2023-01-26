#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N1 = 5e6 + 5;
const long long N2 = 2e4 + 5;
long long n, a[16], Up[16][16], WL[N1], P[N2], Res, Lim;
vector<pair<long long, long long> > Match;
void Input() {
  cin >> n;
  for (long long i = 0; i < n; ++i) cin >> a[i];
}
long long Pow(long long A, long long B) {
  if (B == 0) return 1;
  long long C = Pow(A, B / 2);
  if (B % 2 == 0) return C * C % MOD;
  return C * C % MOD * A % MOD;
}
long long Get_Pos(pair<long long, long long> A) {
  long long Low = 0, High = Match.size();
  High--;
  while (Low <= High) {
    long long Mid = (Low + High) / 2;
    if (Match[Mid].first < A.first)
      Low = Mid + 1;
    else {
      if (Match[Mid].first > A.first)
        High = Mid - 1;
      else {
        if (Match[Mid].second < A.second)
          Low = Mid + 1;
        else {
          if (Match[Mid].second > A.second)
            High = Mid - 1;
          else
            return Mid + 1;
        }
      }
    }
  }
}
bool In_Mask(long long x, long long Mask) { return (Mask & (1ll << x)) > 0; }
void Cal_WinToLose() {
  for (long long i = 0; i < n; ++i) {
    for (long long j = i + 1; j < n; ++j) {
      Up[i][j] = Pow(a[i] + a[j], MOD - 2);
      Up[j][i] = Up[i][j];
    }
  }
  for (long long Mask1 = 1; Mask1 <= Lim; ++Mask1) {
    for (long long Mask2 = 0; Mask2 <= (Lim ^ Mask1); ++Mask2) {
      if ((Mask1 & Mask2) != 0) continue;
      Match.push_back({Mask1, Mask2});
      long long Cnt = Match.size();
      long long NumBit = __builtin_popcount(Mask1);
      long long PosBit = __builtin_ctz(Mask1);
      WL[Cnt] = 1;
      if (NumBit == 1) {
        for (long long i = 0; i < n; ++i) {
          if (In_Mask(i, Mask2))
            WL[Cnt] = WL[Cnt] * a[PosBit] % MOD * Up[PosBit][i] % MOD;
        }
      } else {
        long long subMask1 = (1ll << PosBit), subMask2 = (Mask1 ^ subMask1);
        WL[Cnt] = WL[Get_Pos({subMask1, Mask2})] *
                  WL[Get_Pos({subMask2, Mask2})] % MOD;
      }
    }
  }
}
void Cal_Probability() {
  for (long long Mask = 1; Mask <= Lim; ++Mask) {
    P[Mask] = 1;
    long long NumWin = __builtin_popcount(Mask);
    long long Lose = (Lim ^ Mask);
    for (long long subMask = 1; subMask < Mask; ++subMask) {
      if ((Mask | subMask) != Mask) continue;
      long long exMask = (Mask ^ subMask);
      P[Mask] =
          (P[Mask] - P[subMask] * WL[Get_Pos({subMask, exMask})] % MOD + MOD) %
          MOD;
    }
    Res = (Res + NumWin * (P[Mask] * WL[Get_Pos({Mask, Lose})] % MOD)) % MOD;
  }
}
void Solve() {
  Lim = (1ll << n) - 1;
  Res = 0;
  Cal_WinToLose();
  Cal_Probability();
  cout << Res;
}
int main() {
  if (fopen("trash.inp", "r"))
    freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  Input();
  Solve();
}
