#include <bits/stdc++.h>
using namespace std;
const long long DIM = 3e5 + 7;
const long long DIMM = 5e4 + 7;
const long long DDIM = 7;
const long long INF = 1e18 + 7;
const long long X = 1e5 + 7;
const long long BS = 2e5 + 7;
const long long AS = 26 + 7;
const long long MODULO = 1e9 + 7;
long long nt, n, m, k, q;
long long val, s, n1;
long long c[DIM];
vector<long long> res;
int main() {
  ios_base::sync_with_stdio();
  cin.tie();
  cout.tie();
  ;
  cin >> nt;
  for (int tt = 1; tt <= nt; tt++) {
    cin >> n >> m;
    n1 = n - 2 * m;
    for (int i = 1; i <= n; i++) {
      cin >> val;
      if (i < val)
        s = n - val + i;
      else
        s = i - val;
      c[s]++;
    }
    for (int i = 0; i < n; i++) {
      if (c[i] >= n1) res.push_back(i);
      c[i] = 0;
    }
    sort(res.begin(), res.end());
    cout << res.size() << ' ';
    for (auto to : res) cout << to << ' ';
    cout << endl;
    res.clear();
  }
  return 0;
}
