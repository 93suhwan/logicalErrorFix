#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000006;
int n;
int a[N];
int b[N];
void solv() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) b[i] = a[i];
  vector<pair<int, bool> > v;
  int u = 1;
  while (u <= n) {
    bool z = true;
    int i = u;
    while (i < n && a[i] > a[i + 1]) {
      b[i] *= -1;
      z = false;
      ++i;
    }
    b[i] *= -1;
    while (i < n && a[i] < a[i + 1]) ++i;
    v.push_back(make_pair(u, z));
    u = i + 1;
  }
  if (((int)(v).size()) <= 2) {
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) cout << b[i] << ' ';
    cout << "\n";
    return;
  }
  int i = 0;
  while (i < ((int)(v).size()) - 1 && a[v[i].first] > a[v[i + 1].first]) ++i;
  bool z = false;
  for (int j = i + 1; j < ((int)(v).size()); ++j) {
    if (!v[j].second) {
      cout << "NO\n";
      return;
    }
    if (a[v[j - 1].first] > a[v[j].first]) {
      cout << "NO\n";
      return;
    }
    b[v[j].first] *= -1;
  }
  cout << "YES\n";
  for (int i = 1; i <= n; ++i) cout << b[i] << ' ';
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solv();
  }
  return 0;
}
