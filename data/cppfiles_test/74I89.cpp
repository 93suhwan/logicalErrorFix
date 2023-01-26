#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1003;
int n;
int a[N];
pair<int, int> u[N * N];
void solv() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i + 1]) {
      cout << "YES\n";
      cout << "0 ";
      for (int j = 1; j <= n; ++j) {
        if (i == j) continue;
        cout << a[j] << ' ';
      }
      cout << "\n";
      return;
    }
  }
  if (n == 2) {
    cout << "NO\n";
    return;
  }
  if (n == 3) {
    if ((a[1] + a[2] + a[3]) % 2 == 0) {
      int x = (a[1] + a[2] - a[3]) / 2;
      int z = a[2] - x;
      int y = a[3] - z;
      cout << "YES\n";
      cout << x << ' ' << y << ' ' << z << "\n";
      return;
    }
    cout << "NO\n";
    return;
  }
  vector<int> v[2];
  for (int i = 1; i <= n; ++i) v[a[i] % 2].push_back(a[i]);
  if (!v[0].empty()) {
    int a1, a2, a3;
    if (((int)(v[0]).size()) >= 3) {
      a1 = v[0].back();
      v[0].pop_back();
      a2 = v[0].back();
      v[0].pop_back();
      a3 = v[0].back();
      v[0].pop_back();
    } else {
      a1 = v[0].back();
      v[0].pop_back();
      a2 = v[1].back();
      v[1].pop_back();
      a3 = v[1].back();
      v[1].pop_back();
    }
    int x = (a1 + a2 - a3) / 2;
    int z = a2 - x;
    int y = a3 - z;
    cout << "YES\n";
    cout << x << ' ' << y << ' ' << z << ' ';
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < ((int)(v[i]).size()); ++j) {
        cout << v[i][j] - x << ' ';
      }
    }
    cout << "\n";
    return;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      int g = a[i] + a[j];
      if (u[g].first == 0) {
        u[g] = make_pair(i, j);
      } else {
        int t = a[i] - a[u[g].first];
        cout << "YES\n";
        cout << t << ' ' << min(a[i], a[u[g].first]) << ' '
             << min(a[j], a[u[g].second]) << " 0 ";
        for (int k = 1; k <= n; ++k) {
          if (k == i || k == j || k == u[g].first || k == u[g].second) continue;
          cout << a[k] << ' ';
        }
        cout << "\n";
        return;
      }
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int tt = 1;
  while (tt--) {
    solv();
  }
  return 0;
}
