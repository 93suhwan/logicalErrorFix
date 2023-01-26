#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int INF = 1000000000 + 1e8;
const long long LINF = 2000000000000000000;
const int N = 3e5 + 1010;
int t[4 * N];
int query(int v, int vl, int vr, int l, int r) {
  if (r < vl || vr < l) return -INF;
  if (vl >= l && vr <= r) return t[v];
  int vm = (vl + vr) / 2;
  return max(query(2 * v + 1, vl, vm, l, r),
             query(2 * v + 2, vm + 1, vr, l, r));
}
void modify(int v, int vl, int vr, int pos, int val) {
  if (vl == vr) {
    t[v] = max(t[v], val);
    return;
  }
  int vm = (vl + vr) / 2;
  if (pos <= vm) {
    modify(2 * v + 1, vl, vm, pos, val);
  } else
    modify(2 * v + 2, vm + 1, vr, pos, val);
  t[v] = max(t[2 * v + 1], t[2 * v + 2]);
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mp[x].push_back(i + 1);
  }
  int ans = 0;
  vector<int> res(n + 1);
  for (auto to : mp) {
    int ai = to.first;
    for (auto i : to.second) {
      if (i - ai >= 0) {
        res[i] = max(1, query(0, 0, N - 1, 0, i - ai) + 1);
        ans = max(ans, res[i]);
      }
    }
    for (auto i : to.second) {
      if (i - ai >= 0) {
        modify(0, 0, N - 1, i - ai, res[i]);
      }
    }
  }
  cout << ans;
}
int main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tst = 1;
  while (tst--) {
    solve();
  }
}
