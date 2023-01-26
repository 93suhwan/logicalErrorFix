#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long R = 998244353, R1 = 19491001, R2 = 236, NUMTESTCASE;
const long long NN = 10 + 1e5, Inverse2 = 500000004;
const double pi = acos(-1.0);
int di[8] = {1, 0, -1, 0, 1, -1, 1, -1}, dj[8] = {0, 1, 0, -1, 1, -1, -1, 1};
int n, Arr[NN], Total;
map<int, pair<int, int>> Memo[NN];
pair<int, int> Dp(int Pos, int l, int Next) {
  if (Pos < l) return {0, Next};
  if (Memo[Pos].count(Next)) return Memo[Pos][Next];
  Dp(Pos - 1, l, INT_MAX);
  pair<int, int> res;
  if (Arr[Pos] <= Next)
    res = {1 + Dp(Pos - 1, l, Arr[Pos]).first, Dp(Pos - 1, l, Arr[Pos]).second};
  else {
    int Number = (Arr[Pos] + Next - 1) / Next;
    int p = Arr[Pos] / Number;
    res = {Number + Dp(Pos - 1, l, p).first, Dp(Pos - 1, l, p).second};
  }
  if (Next == INT_MAX) Total += res.first;
  return Memo[Pos][Next] = res;
}
int main() {
  for (cin >> NUMTESTCASE; NUMTESTCASE; NUMTESTCASE--) {
    scanf("%d", &n);
    for (int i = (1); i <= (n); ++i) scanf("%d", Arr + i);
    int Ans = 0;
    for (long long i = 1; i <= n; i++)
      Ans = (Ans + (n - i + 2) * (n - i + 1) / 2) % R;
    Ans = (R - Ans) % R;
    map<int, pair<int, int>> dp;
    for (int i = (n); i >= (1); --i) {
      map<int, pair<int, int>> dp2;
      dp2[Arr[i]] = {1, 1};
      int c = 1;
      for (auto p : dp) {
        int t = 0, Nxt = Arr[i], Cnt = p.second.second;
        if (Arr[i] <= p.first)
          t = 1;
        else
          t = (Arr[i] + p.first - 1) / p.first,
          Nxt = Arr[i] / ((Arr[i] + p.first - 1) / p.first);
        dp2[Nxt] = {dp2[Nxt].first + t * Cnt + p.second.first,
                    dp2[Nxt].second + Cnt};
        c += Cnt;
      }
      assert(c == n - i + 1);
      dp = dp2;
      for (auto p : dp) Ans = (Ans + p.second.first) % R;
    }
    printf("%d\n", Ans);
  }
  return 0;
}
