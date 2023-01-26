#include <bits/stdc++.h>
using namespace std;
std::mt19937 rng(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
const long long INF = 1ll << 60;
const long long mod = 1000000007;
const long double PI = acosl(-1);
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}
void solve() {
  long long n, m, i, j;
  cin >> n >> m;
  vector<set<long long>> adj(n + 1);
  for (i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    adj[x].insert(y);
    adj[y].insert(x);
  }
  long long a, b, c, d, e;
  for (a = 1; a <= min(n, 48ll); a++) {
    for (b = a + 1; b <= min(n, 48ll); b++) {
      for (c = b + 1; c <= min(n, 48ll); c++) {
        for (d = c + 1; d <= min(n, 48ll); d++) {
          for (e = d + 1; e <= min(n, 48ll); e++) {
            vector<long long> ind = {a, b, c, d, e};
            bool ok = 1, ini;
            ini = adj[a].count(b);
            for (i = 0; i < 5; i++) {
              for (j = i + 1; j < 5; j++) {
                if (adj[ind[i]].count(ind[j]) != ini) ok = 0;
              }
            }
            if (ok) {
              for (auto a : ind) {
                cout << a << ' ';
              }
              cout << "\n";
              return;
            }
          }
        }
      }
    }
  }
  cout << -1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
}
