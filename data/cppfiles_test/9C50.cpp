#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream& operator<<(ostream& out, const pair<A, B>& p) {
  return out << "(" << p.first << ", " << p.second << ")";
}
template <class A>
ostream& operator<<(ostream& out, const vector<A>& v) {
  for (int i = int(0); i < int(int((v).size())); i++) {
    if (i) out << " ";
    out << v[i];
  }
  return out;
}
const int N = 1005;
const int mlen = 1000009;
const long long maxl = 1001000000;
const int md = 1000000007;
vector<int> a;
void fd() {}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int> > v(n);
  vector<vector<bool> > isDrop(n + 1);
  for (int i = int(0); i < int(n); i++) {
    v[i].resize(m);
    isDrop[i].resize(m);
    for (int j = int(0); j < int(m); j++) cin >> v[i][j];
  }
  isDrop[n].resize(m);
  for (int j = int(0); j < int(m); j++) isDrop[n][j] = true;
  int x, startDrop;
  for (int q = int(0); q < int(k); q++) {
    cin >> x;
    x--;
    startDrop = -1;
    for (int i = int(0); i < int(n + 1); i++) {
      if (isDrop[i][x]) {
        if (startDrop != -1)
          for (int j = int(startDrop); j < int(n); j++) isDrop[j][x] = true;
        cout << ++x << ' ';
        break;
      }
      if (v[i][x] != 2) {
        startDrop = -1;
        int val = v[i][x];
        v[i][x] = 2;
        i--;
        if (val == 1)
          x++;
        else
          x--;
      } else if (startDrop == -1)
        startDrop = i;
    }
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
    fflush(stdout);
  }
  return 0;
}
