#include <bits/stdc++.h>
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long mod = 998244353;
long long modpow(long long b, long long e) {
  long long ans = 1;
  for (; e; b = b * b % mod, e /= 2)
    if (e & 1) ans = ans * b % mod;
  return ans;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> e(2, 1);
  map<pair<int, int>, int> prev;
  vector<vector<int> > row(n, vector<int>(2, 1)), col(m, vector<int>(2, 1));
  vector<int> rcnt(3), ccnt(3);
  rcnt[2] = n;
  ccnt[2] = m;
  for (int i = (0); i < (k); ++i) {
    int x, y, t;
    cin >> x >> y >> t;
    --x;
    --y;
    if (prev.count(make_pair(x, y))) {
      int par = ((x + y) & 1) ^ prev[make_pair(x, y)];
      ++e[par ^ 1];
      int rowpar = ((y & 1) ^ prev[make_pair(x, y)]);
      ++row[x][rowpar ^ 1];
      if (row[x][rowpar ^ 1] == 1 && row[x][rowpar] < 1) {
        --rcnt[0];
        ++rcnt[1];
      } else if (row[x][rowpar ^ 1] == 1 && row[x][rowpar] == 1) {
        --rcnt[1];
        ++rcnt[2];
      }
      int colpar = ((x & 1) ^ prev[make_pair(x, y)]);
      ++col[y][colpar ^ 1];
      if (col[y][colpar ^ 1] == 1 && col[y][colpar] < 1) {
        --ccnt[0];
        ++ccnt[1];
      } else if (col[y][colpar ^ 1] == 1 && col[y][colpar] == 1) {
        --ccnt[1];
        ++ccnt[2];
      }
      prev.erase(make_pair(x, y));
    }
    if (t == 0) {
      prev[make_pair(x, y)] = 0;
    } else if (t == 1) {
      prev[make_pair(x, y)] = 1;
    }
    if (t != -1) {
      int par = ((x + y) & 1) ^ prev[make_pair(x, y)];
      --e[par ^ 1];
      int rowpar = ((y & 1) ^ prev[make_pair(x, y)]);
      row[x][rowpar ^ 1]--;
      int colpar = ((x & 1) ^ prev[make_pair(x, y)]);
      col[y][colpar ^ 1]--;
      if (row[x][rowpar ^ 1] == 0 && row[x][rowpar] < 1) {
        --rcnt[1];
        ++rcnt[0];
      } else if (row[x][rowpar ^ 1] == 0 && row[x][rowpar] == 1) {
        --rcnt[2];
        ++rcnt[1];
      }
      if (col[y][colpar ^ 1] == 0 && col[y][colpar] < 1) {
        --ccnt[1];
        ++ccnt[0];
      } else if (col[y][colpar ^ 1] == 0 && col[y][colpar] == 1) {
        --ccnt[2];
        ++ccnt[1];
      }
    }
    long long rans = (rcnt[0] > 0 ? 0 : modpow(2, rcnt[2]));
    long long cans = (ccnt[0] > 0 ? 0 : modpow(2, ccnt[2]));
    long long ans = (2 * mod + rans + cans - max(0, e[0]) - max(0, e[1])) % mod;
    cout << ans << '\n';
  }
}
