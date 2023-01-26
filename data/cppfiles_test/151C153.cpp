#include <bits/stdc++.h>
using namespace std;
const int NMAX = 5e5;
struct query {
  int type;
  int x;
  int y;
} q[NMAX];
vector<int> v;
int fin[NMAX + 1];
void solve() {
  int n, i, a, b, c;
  cin >> n;
  for (i = 0; i <= NMAX; i++) fin[i] = i;
  for (i = 0; i < n; i++) {
    cin >> q[i].type;
    if (q[i].type == 1) {
      cin >> q[i].x;
    } else
      cin >> q[i].x >> q[i].y;
  }
  for (i = n - 1; i >= 0; i--) {
    if (q[i].type == 1) {
      v.push_back(fin[q[i].x]);
    } else
      fin[q[i].x] = fin[q[i].y];
  }
  reverse(v.begin(), v.end());
  for (auto it : v) cout << it << ' ';
}
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
