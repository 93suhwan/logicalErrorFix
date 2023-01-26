#include <bits/stdc++.h>
using namespace std;
template <class Num>
Num mabs(Num x) {
  if (x < 0) return -x;
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> X(n + 1), Y(n + 1);
  for (int i = (1); i < (n + 1); i++) {
    cin >> X[i] >> Y[i];
  }
  int ans = 0;
  int K = 1;
  for (; K * K <= m; K++) K++;
  vector<int> start(n + 1, 0);
  vector<int> pref(m + 1, 0);
  vector<vector<int>> mali(K + 2, vector<int>(K + 2, 0));
  auto modify = [&](int tko, int val) -> void {
    int ciklus = X[tko] + Y[tko];
    assert(ciklus <= K + 2);
    int poc = (start[tko] + X[tko]) % ciklus;
    int len = 1;
    for (int i = poc; len <= Y[tko]; i++) {
      if (i == ciklus) i = 0;
      mali[ciklus][i] += val;
      len++;
      if ((i + 1) % ciklus == poc) break;
    }
  };
  auto get = [&](int T) -> int {
    int ret = 0;
    for (int i = 1; i <= K; i++) {
      ret += mali[i][T % i];
    }
    return ret;
  };
  for (int i = (1); i < (m + 1); i++) {
    int tip, tko;
    cin >> tip >> tko;
    if (tip == 1) {
      start[tko] = i;
      if (X[tko] + Y[tko] < K) {
        modify(tko, 1);
      } else {
        for (int j = i + X[tko]; j <= m; j += X[tko] + Y[tko]) {
          pref[j]++;
          if (j + Y[tko] <= m) pref[j + Y[tko]]--;
        }
      }
    } else {
      if (X[tko] + Y[tko] < K) {
        modify(tko, -1);
      } else {
        for (int j = start[tko] + X[tko]; j <= m; j += X[tko] + Y[tko]) {
          pref[j]--;
          if (j + Y[tko] <= m) pref[j + Y[tko]]++;
          if (i > j && i <= j + Y[tko]) ans -= 1;
        }
      }
    }
    ans += pref[i];
    cout << ans + get(i) << "\n";
  }
  return 0;
}
