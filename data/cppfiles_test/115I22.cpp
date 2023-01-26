#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);
long long random2() { return (1ll << 31ll) * eng() + eng(); }
long long n, m, k, q, T;
const long long big = 1000000007;
const long long big2 = 1000000009;
const long long mod = 998244353;
const long long MAXN = 200004;
long long rowpar[2][2] = {0};
long long colpar[2][2] = {0};
long long sumpar[2][2] = {0};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long a, b, c, d, e;
  cin >> n >> m >> k;
  vector<vector<int> > A(n, vector<int>(m, -1));
  for (int c1 = 0; c1 < (k); ++c1) {
    cin >> a >> b >> c;
    a--;
    b--;
    if (A[a][b] != -1) {
      rowpar[A[a][b]][a % 2]--;
      colpar[A[a][b]][b % 2]--;
      sumpar[A[a][b]][(a + b) % 2]--;
    }
    A[a][b] = c;
    if (A[a][b] != -1) {
      rowpar[A[a][b]][a % 2]++;
      colpar[A[a][b]][b % 2]++;
      sumpar[A[a][b]][(a + b) % 2]++;
    }
    long long ans = 0;
    for (int c3 = 0; c3 < (2); ++c3) {
      ans += ((colpar[0][c3] == 0) && (colpar[1][(c3 ^ 1)] == 0));
    }
    for (int c3 = 0; c3 < (2); ++c3) {
      ans += ((rowpar[0][c3] == 0) && (rowpar[1][(c3 ^ 1)] == 0));
    }
    for (int c3 = 0; c3 < (2); ++c3) {
      ans += ((sumpar[0][c3] == 0) && (sumpar[1][(c3 ^ 1)] == 0));
    }
    cout << ans << "\n";
  }
  return 0;
}
