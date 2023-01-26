#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
vi p1(1010), p2(1010);
int find(int a, int x) {
  if (x == 1)
    return p1[a] == a ? a : p1[a] = find(p1[a], 1);
  else
    return p2[a] == a ? a : p2[a] = find(p2[a], 2);
}
void unite(int a, int b, int x) {
  if (x == 1) {
    a = p1[a];
    b = p1[b];
    if (a != b) p1[b] = a;
  } else {
    a = p2[a];
    b = p2[b];
    if (a != b) p2[b] = a;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  for (int i = 1; i <= n; i++) p1[i] = i, p2[i] = i;
  for (int i = 1; i <= m1; i++) {
    int u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    unite(u, v, 1);
  }
  for (int i = 1; i <= m2; i++) {
    int u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    unite(u, v, 2);
  }
  vector<array<int, 2>> v;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int a = find(i, 1), b = find(j, 1);
      int aa = find(i, 2), bb = find(j, 2);
      if (a != b && aa != bb) {
        v.push_back({i, j});
        unite(i, j, 1);
        unite(i, j, 2);
      }
    }
  }
  cout << (int)v.size() << endl;
  for (int i = 0; i < (int)v.size(); i++)
    cout << v[i][0] << " " << v[i][1] << endl;
}
