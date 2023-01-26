#include <bits/stdc++.h>
using namespace std;
int n, V[171];
void cauta(int p) {
  vector<pair<int, int> > Queries;
  int res, st = 1, dr = n;
  for (int m = dr; m >= st; --m) {
    cout << "? ";
    for (int i = 1; i <= n; ++i) {
      if (i != p)
        cout << "1 ";
      else
        cout << n - m + 2 << " ";
    }
    cout << "\n";
    cout.flush();
    cin >> res;
    if (res == 0) {
      V[p] = m;
      break;
    } else {
      if (V[res]) {
        V[p] = V[res] - 1 + m - n;
        break;
      } else if (res != p)
        Queries.push_back({res, n - m + 1});
    }
  }
  for (auto it : Queries) V[it.first] = it.second + V[p];
}
void solve() {
  cin >> n;
  for (int i = n; i >= 1; --i)
    if (!V[i]) cauta(i);
  cout << "! ";
  for (int i = 1; i <= n; ++i) {
    cout << V[i] << " ";
    V[i] = 0;
  }
  cout << "\n";
  cout.flush();
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int te = 1;
  while (te--) solve();
  return 0;
}
