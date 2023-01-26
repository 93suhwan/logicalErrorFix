#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int nmax = 1000500;
int ans[nmax];
int a[nmax];
int b[nmax];
int n, k;
vector<pair<int, int> > toch;
int d[600600];
void best(int mask) {
  for (int i = 0; i < (1 << k); i++) d[i] = 0;
  for (int i = 1; i <= n; i++) d[a[i] ^ mask] = i, b[i] = a[i] ^ mask;
  vector<int> v;
  for (int i = 0; i < (1 << k); i++)
    if (d[i]) v.push_back(i);
  map<int, pair<int, int> > mp;
  for (int i = 0; i + 1 < n; i++) {
    int x = b[v[i]];
    int y = b[v[i + 1]];
    int z = x ^ y;
    int c = 0;
    while (z > 0) z /= 2, c++;
    mp[c] = {v[i], v[i + 1]};
  }
  toch.push_back(prev(mp.end())->second);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  int m = (1 << k);
  for (int i = 0; i < m; i++) ans[i] = 1e9;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int l = 0; l < k; l++)
    for (int r = l; r < k; r++) {
      int xmask = 0;
      for (int i = l; i <= r; i++) xmask ^= (1 << i);
      best(xmask);
    }
  int ind = 0;
  while (clock() * 1.0 / CLOCKS_PER_SEC < 2.5) {
    int i, j;
    if (ind < toch.size()) {
      i = toch[ind].first;
      j = toch[ind].second;
      ind++;
    } else {
      i = rand() % n + 1;
      j = rand() % n + 1;
    }
    if (i != j) {
      for (int x = 0; x < m; x++)
        ans[x] = min(ans[x], abs((x ^ a[i]) - (x ^ a[j])));
    }
  }
  for (int i = 0; i < m; i++) cout << ans[i] << " ";
  cout << "\n";
}
