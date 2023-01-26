#include <bits/stdc++.h>
using namespace std;
int TC, N;
string S;
array<int, 4> solve() {
  int pos = find(S.begin() + N / 2, S.end(), '0') - S.begin() + 1;
  if (pos <= N) return {pos - N / 2, pos, pos - N / 2, pos - 1};
  if (S[N - 1 - N / 2] == '0') return {N - N / 2, N, N - N / 2 + 1, N};
  return {N - N / 2, N - 1, N - N / 2 + 1, N};
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> TC;
  while (TC--) {
    cin >> N >> S;
    auto ans = solve();
    for (int i = (0); i < (4); i++) cout << ans[i] << " \n"[i == 3];
  }
}
