#include <bits/stdc++.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rd);
}
const int N = 49;
int n, m, d[N][N];
int b[N];
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int(i) = (1); (i) <= (m); ++(i)) {
    int a, b;
    cin >> a >> b;
    if (max(a, b) > 48) continue;
    d[a][b] = d[b][a] = 1;
  }
  n = min(n, 48);
  for (int(i) = (1); (i) <= (n); ++(i)) b[i] = i;
  shuffle(b + 1, b + 1 + n, rd);
  for (int(i) = (1); (i) <= (n); ++(i))
    for (int(j) = (i + 1); (j) <= (n); ++(j))
      for (int(z) = (j + 1); (z) <= (n); ++(z))
        for (int(k) = (z + 1); (k) <= (n); ++(k))
          for (int(x) = (k + 1); (x) <= (n); ++(x)) {
            int CNT = 0;
            vector<int> a;
            a.push_back(b[i]), a.push_back(b[j]), a.push_back(b[z]),
                a.push_back(b[k]), a.push_back(b[x]);
            for (int(i) = (0); (i) <= ((int)(a).size() - 1); ++(i))
              for (int(j) = (0); (j) <= (i - 1); ++(j))
                if (d[a[i]][a[j]]) ++CNT;
            if (CNT == 0 || CNT == 10) {
              cout << b[i] << ' ' << b[j] << ' ' << b[z] << ' ' << b[k] << ' '
                   << b[x] << '\n';
              return 0;
            }
          }
  cout << -1;
  return 0;
}
