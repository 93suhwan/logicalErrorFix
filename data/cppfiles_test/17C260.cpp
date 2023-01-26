#include <bits/stdc++.h>
using namespace std;
const int lmt = 50005;
const long long MOD = 1000000007;
const long long mod = 998244353;
const int AbcN = 'z' - 'a';
const int di[4] = {0, 1, 0, -1};
const int dj[4] = {1, 0, -1, 0};
struct wer {
  int a, b;
};
bool operator<(const wer &a, const wer &b) { return a.a < b.a; }
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
vector<vector<int>> p;
int ori[5][lmt];
void solve() {
  p.clear();
  int n;
  cin >> n;
  for (int i = 0; i < int(n); i++) {
    int a[5];
    for (int j = 0; j < int(5); j++) {
      cin >> a[j];
      ori[j][i] = a[j];
    }
    p.push_back({a[0], a[1], a[2], a[3], a[4], i});
  }
  while (true) {
    int i = 0;
    bool z = false;
    while (i < n) {
      while (i < n && p[i][0] == -1) {
        i++;
      }
      if (i == n) {
        break;
      }
      int j = i + 1;
      while (j < n && p[j][0] == -1) {
        j++;
      }
      if (j == n) {
        break;
      }
      z = true;
      int D = 0;
      for (int k = 0; k < int(5); k++) {
        if (p[i][k] < p[j][k]) {
          D++;
        }
      }
      if (D <= 2) {
        p[i][0] = -1;
      } else {
        p[j][0] = -1;
      }
      i = j + 1;
    }
    if (!z) {
      break;
    }
  }
  int i = 0;
  while (p[i][0] == -1) {
    i++;
  }
  int r = p[i][5];
  for (int j = 0; j < int(n); j++) {
    if (r != j) {
      int D = 0;
      for (int k = 0; k < int(5); k++) {
        if (ori[k][r] > ori[k][j]) {
          D++;
        }
      }
      if (D > 2) {
        cout << "-1\n";
        return;
      }
    }
  }
  cout << r + 1 << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q = 1;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
