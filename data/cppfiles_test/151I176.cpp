#include <bits/stdc++.h>
using namespace std;
int to[500000 + 1], of[500000 + 1], _index[500000 + 1];
vector<int> v;
int cnt;
int find(int i) {
  if (_index[i] == i) return i;
  return _index[i] = find(_index[i]);
}
void add(int x) {
  if (to[find(of[x])] != x) {
    cnt++;
    to[cnt] = x;
    of[x] = cnt;
    v.push_back(cnt);
  } else {
    v.push_back(of[x]);
  }
}
void change(int x, int y) {
  if (x == y) return;
  if (of[y] == 0) {
    cnt++;
    of[y] = cnt;
    to[cnt] = y;
  }
  int pa = find(of[x]), pb = find(of[y]);
  if (to[pa] == 0) return;
  _index[pa] = pb;
  to[pa] = 0;
}
void print() {
  for (auto x : v) cout << to[find(x)] << " ";
}
void solve() {
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) _index[i] = i;
  int t, x, y;
  cnt = 0;
  while (q--) {
    cin >> t;
    if (t == 1) {
      cin >> x;
      add(x);
    } else {
      cin >> x >> y;
      change(x, y);
    }
  }
  print();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
