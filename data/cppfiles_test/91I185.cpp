#include <bits/stdc++.h>
using namespace std;
const int c = 100005, k = 50, sok = 2e9;
int n, m, q;
bool t[c][k];
map<pair<int, int>, int> el;
multiset<int> s1[c], s2[k][2];
multiset<long long> r;
long long res(int a) {
  long long ans = 0;
  int cnt = 0;
  for (auto x : s1[a]) {
    ans += x;
    cnt++;
    if (cnt == 3) {
      return ans;
    }
  }
}
void valt(int id) {
  int a, b, suly;
  cin >> a >> b;
  if (a > b) {
    swap(a, b);
  }
  if (id) {
    cin >> el[{a, b}];
  }
  suly = el[{a, b}];
  if (!id) {
    el.erase({a, b});
  }
  r.erase(r.find(res(a))), r.erase(r.find(res(b)));
  if (id) {
    s1[a].insert(suly), s1[b].insert(suly);
  } else {
    s1[a].erase(s1[a].find(suly)), s1[b].erase(s1[b].find(suly));
  }
  r.insert(res(a)), r.insert(res(b));
  for (int i = 0; i < k; i++) {
    if (t[a][i] == t[b][i]) {
      int h = t[a][i];
      if (id) {
        s2[i][h].insert(suly);
      } else {
        s2[i][h].erase(s2[i][h].find(suly));
      }
    }
  }
}
void calc() {
  long long mini = *(r.begin());
  for (int i = 0; i < k; i++) {
    long long x = *(s2[i][0].begin()), y = *(s2[i][1].begin());
    mini = min(mini, x + y);
  }
  cout << mini << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 3; j++) {
      s1[i].insert(sok);
    }
    r.insert(res(i));
  }
  for (int j = 0; j < k; j++) {
    for (int i = 1; i <= n; i++) {
      t[i][j] = rand() % 2;
    }
    s2[j][0].insert(sok), s2[j][1].insert(sok);
  }
  for (int i = 1; i <= m; i++) {
    valt(1);
  }
  calc();
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int id;
    cin >> id;
    valt(id);
    calc();
  }
  return 0;
}
