#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;
void solve() {
  long long N, K;
  cin >> N >> K;
  long long i = 0;
  while ((1LL << i) <= K && (1LL << i) < N) {
    i++;
  }
  long long moves = i;
  long long done = 1LL << i;
  if (done >= N) {
    cout << moves << '\n';
  } else {
    long long rem = (N - done) / K + ((N - done) % K == 0 ? 0 : 1);
    cout << moves + rem << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
