#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1010;
long long col[MAXN][MAXN];
long long N, K;
void f(vector<long long> vect, long long lvl) {
  long long tam = vect.size();
  if (tam <= 1) return;
  vector<long long> vvv;
  for (long long i = 0; i < K; i++) {
    if (i < (tam % K)) {
      vvv.push_back(tam / K + 1);
    } else {
      vvv.push_back(tam / K);
    }
  }
  reverse(vect.begin(), vect.end());
  vector<vector<long long>> ccc;
  for (auto x : vvv) {
    vector<long long> temp;
    while (x--) {
      temp.push_back(vect.back());
      vect.pop_back();
    }
    ccc.push_back(temp);
  }
  for (auto vvv : ccc) {
    f(vvv, lvl + 1);
  }
  for (long long i = 0; i < ccc.size(); i++) {
    for (long long j = i + 1; j < ccc.size(); j++) {
      for (auto x : ccc[i]) {
        for (auto y : ccc[j]) {
          col[x][y] = lvl;
        }
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;
  vector<long long> vect;
  for (long long i = 1; i <= N; i++) {
    vect.push_back(i);
  }
  f(vect, 1);
  long long may = 0;
  for (long long i = 1; i <= N; i++) {
    for (long long j = i + 1; j <= N; j++) {
      may = max(may, col[i][j]);
    }
  }
  cout << may << '\n';
  for (long long i = 1; i <= N; i++) {
    for (long long j = i + 1; j <= N; j++) {
      cout << col[i][j] << " ";
    }
  }
  cout << '\n';
  return 0;
}
