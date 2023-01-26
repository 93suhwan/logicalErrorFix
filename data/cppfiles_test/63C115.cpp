#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > aa;
const int N = 1010;
int p1[N], p2[N];
int find1(int x) {
  if (p1[x] != x) p1[x] = find1(p1[x]);
  return p1[x];
}
int find2(int x) {
  if (p2[x] != x) p2[x] = find2(p2[x]);
  return p2[x];
}
int main() {
  int T;
  T = 1;
  while (T--) {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= n; i++) {
      p1[i] = i;
      p2[i] = i;
    }
    int a, b;
    while (m1--) {
      cin >> a >> b;
      p1[find1(a)] = find1(b);
    }
    while (m2--) {
      cin >> a >> b;
      p2[find2(a)] = find2(b);
    }
    int s = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (p1[find1(i)] != find1(j) && p2[find2(i)] != find2(j)) {
          s++;
          p1[find1(i)] = find1(j);
          p2[find2(i)] = find2(j);
          aa.push_back({i, j});
        }
      }
    }
    cout << s << endl;
    for (auto it : aa) cout << it.first << ' ' << it.second << endl;
  }
  return 0;
}
