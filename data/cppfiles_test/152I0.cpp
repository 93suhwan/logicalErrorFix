#include <algorithm>
#include <bitset>
#include <cassert>
#include <deque>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <map>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl;

void solve() {
  int N;
  cin >> N;
  std::vector<int> P(N);
  for (auto &El : P)
    cin >> El;

  using State = std::array<std::array<int, 2>, 2>; // [Count][IsNegated]
  const State INIT = State{std::array<int, 2>{0, 0}, {0, 0}};
  std::vector<State> DP(N, INIT);
  std::vector<State> From(N, INIT);
  DP[0] = State{std::array<int, 2>{1, 1}, {0, 0}};
  for (int Pos = 1; Pos < N; Pos++) {
    for (int Count = 0; Count < 2; Count++)
      for (int Neg = 0; Neg < 2; Neg++)
          for (int PrevNeg = 0; PrevNeg < 2; PrevNeg++) {
            int Cur = Neg ? -P[Pos] : P[Pos];
            int Prev = PrevNeg ? -P[Pos - 1] : P[Pos - 1];
            int PrevCount = Count - (Cur < Prev);
            if (PrevCount < 0)
              continue;
            if (DP[Pos - 1][PrevCount][PrevNeg]) {
              DP[Pos][Count][Neg] = 1;
              From[Pos][Count][Neg] = PrevCount * 2 + PrevNeg;
            }
          }
  }
  std::pair<int, int> Cur = {-1, -1};
  for (int Count = 0; Count < 2; Count++) {
    for (int Neg = 0; Neg < 2; Neg++) {
      if (DP[N - 1][Count][Neg])
        Cur = {Count, Neg};
    }
  }
  if (Cur.first == -1) {
    cout << "NO\n";
    return;
  }
  for (int I = N - 1; I >= 0; I--) {
    if (Cur.second)
      P[I] = -P[I];
    int Mask = From[I][Cur.first][Cur.second];
    Cur = {Mask >> 1, Mask & 1};
  }
  cout << "YES\n";
  for (auto El : P)
    cout << El << ' ';
  cout << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  for (int TestCase = 1; TestCase <= T; TestCase++) {
    solve();
  }
  return 0;
}
