#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using db = double;
using pii = pair<int, int>;
const int N = 1e5 + 10;
vector<int> a[N], minl[N], minr[N], maxl[N], maxr[N];
int id[N];
bool st[N];
bool cmp(int i, int j) { return a[i][0] > a[j][0]; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      a[i].resize(m);
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = 0; i < n; i++) id[i] = i, st[i] = 0;
    sort(id, id + n, cmp);
    sort(a, a + n, [](vector<int> i, vector<int> j) { return i[0] > j[0]; });
    for (int i = 0; i < n; i++) minl[i] = maxl[i] = minr[i] = maxr[i] = a[i];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i) minl[i][j] = min(minl[i][j], minl[i - 1][j]);
        if (j) minl[i][j] = min(minl[i][j], minl[i][j - 1]);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = m - 1; j; j--) {
        if (i) maxr[i][j] = max(maxr[i][j], maxr[i - 1][j]);
        if (j < m - 1) maxr[i][j] = max(maxr[i][j], maxr[i][j + 1]);
      }
    }
    for (int i = n - 1; i; i--) {
      for (int j = 0; j < m; j++) {
        if (i < n - 1) maxl[i][j] = max(maxl[i][j], maxl[i + 1][j]);
        if (j) maxl[i][j] = max(maxl[i][j], maxl[i][j - 1]);
      }
    }
    for (int i = n - 1; i; i--) {
      for (int j = m - 1; j; j--) {
        if (i < n - 1) minl[i][j] = min(minl[i][j], minl[i + 1][j]);
        if (j < m - 1) minl[i][j] = min(minl[i][j], minl[i][j + 1]);
      }
    }
    bool flag = false;
    int ii, jj;
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < m - 1; j++) {
        if (minl[i][j] > maxl[i + 1][j] &&
            maxr[i][j + 1] < minr[i + 1][j + 1]) {
          flag = true;
          ii = i, jj = j;
          break;
        }
      }
      if (flag) break;
    }
    if (flag) {
      cout << "YES\n";
      for (int i = 0; i <= ii; i++) st[id[i]] = 1;
      for (int i = 0; i < n; i++)
        if (st[i])
          cout << 'R';
        else
          cout << 'B';
      cout << " " << jj + 1 << "\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
