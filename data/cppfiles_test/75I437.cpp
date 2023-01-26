#include <bits/stdc++.h>
using namespace std;
int n;
struct node {
  int id;
  int mx;
  int k;
} q[100005];
vector<int> v[100005];
bool cmp(node a, node b) { return a.mx < b.mx; }
bool check(int x) {
  for (int i = 1; i <= n; i++) {
    if (x > q[i].mx) {
      x = x + v[q[i].id].size();
    } else
      return false;
  }
  return true;
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> q[i].k;
    q[i].id = i;
    for (int j = 0; j < q[i].k; j++) {
      int x;
      cin >> x;
      if (j == 0)
        q[i].mx = x;
      else {
        q[i].mx = max(x - j, q[i].mx);
      }
      v[i].push_back(x);
    }
  }
  sort(q + 1, q + 1 + n, cmp);
  int L = q[1].mx - 1, R = q[n].mx + 1;
  while (L + 1 < R) {
    int mid = (L + R) / 2;
    if (check(mid)) {
      R = mid;
    } else {
      L = mid;
    }
  }
  cout << R << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
