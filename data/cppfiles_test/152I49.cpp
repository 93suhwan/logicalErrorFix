#include <bits/stdc++.h>
using std::cin, std::cout, std::endl;
void solve() {
  int N;
  cin >> N;
  std::vector<int> P(N);
  for (auto &El : P) cin >> El;
  int Prev = std::numeric_limits<int>::min();
  P[0] = -P[0];
  for (int I = 1; I < N; I++) {
    int Pos = P[I];
    int Neg = -P[I];
    if (Neg > P[I - 1]) {
      P[I] = Neg;
      continue;
    }
    if (Pos > P[I - 1]) continue;
    if (Neg > Prev) {
      Prev = P[I - 1];
      P[I] = Neg;
      continue;
    }
    if (Pos > Prev) {
      Prev = P[I - 1];
      continue;
    }
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (auto El : P) cout << El << ' ';
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
