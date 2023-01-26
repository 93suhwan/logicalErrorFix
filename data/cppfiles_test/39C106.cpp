#include <bits/stdc++.h>
using namespace std;
int n, V[171];
void cauta(int p) {
  vector<pair<int, int> > Queries;
  int res, st = 2, dr = n;
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
    } else {
      if (V[res]) {
        V[p] = V[res] - 1 + m - n;
      } else if (res != p)
        Queries.push_back({res, n - m + 1});
    }
  }
  if (!V[p]) V[p] = 1;
  for (auto it : Queries) V[it.first] = it.second + V[p];
}
int gaseste(int dif) {
  cout << "? ";
  for (int i = 1; i < n; ++i) {
    if (dif > 0)
      cout << "1 ";
    else
      cout << -dif + 1 << " ";
  }
  if (dif > 0)
    cout << dif + 1 << "\n";
  else
    cout << "1\n";
  cout.flush();
  int rep = 0;
  cin >> rep;
  return rep;
}
void solve() {
  cin >> n;
  int v, st = 0, dr = 0;
  for (int i = -n + 1; i < n; ++i) {
    if (!i) continue;
    v = gaseste(i);
    V[v] = i;
    if (!v) {
      if (i > 0 && !dr) dr = i;
    }
    if (v && i < 0 && !st) st = -i;
  }
  V[n] = st + 1;
  for (int i = 1; i < n; ++i) V[i] += V[n];
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
