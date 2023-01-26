#include <bits/stdc++.h>
using namespace std;
using vInt = vector<int>;
using LL = long long;
using vLL = vector<LL>;
using pLL = pair<LL, LL>;
using vPLL = vector<pLL>;
using pii = pair<int, int>;
using vPii = vector<pii>;
using matInt = vector<vInt>;
using matLL = vector<vLL>;
using vBool = vector<bool>;
using matBool = vector<vBool>;
void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<string> map(N);
  for (int i = 0; i < N; i++) cin >> map[i];
  matInt check(N, vInt(M));
  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j < M; j++) {
      if (map[i][j] == '.') continue;
      int count = 0;
      for (int k = 0; k <= i; k++) {
        if (j - k < 0) break;
        if (j + k >= M) break;
        if (map[i - k][j - k] == '.') break;
        if (map[i - k][j + k] == '.') break;
        count++;
      }
      if (check[i][j] == 0 && count - 1 < K) {
        cout << "NO" << '\n';
        return;
      }
      if (count - 1 < K) continue;
      for (int k = 0; k < count; k++) {
        check[i - k][j - k] = 1;
        check[i - k][j + k] = 1;
      }
    }
  }
  cout << "YES" << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
