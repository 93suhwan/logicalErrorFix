#include <bits/stdc++.h>
using namespace std;
struct ufds {
  int n;
  vector<int> p, s;
  ufds(int n = 0) : n(n), p(n), s(n, 1) {
    for (int i = 0; i < n; i++) p[i] = i;
  }
  int findSet(int i) { return p[i] == i ? i : (p[i] = findSet(p[i])); }
  bool inSameSet(int i, int j) { return findSet(i) == findSet(j); }
  int getSizeOfSet(int i) { return s[findSet(i)]; }
  void unionSet(int i, int j) {
    i = findSet(i);
    j = findSet(j);
    if (i != j) {
      if (s[i] < s[j]) swap(i, j);
      s[i] += s[j];
      p[j] = i;
    }
  }
};
struct maximum_matching {
  int n, mm = 0, t = 0;
  vector<int> m, l, p, o, v;
  vector<vector<int>> &e;
  queue<int> q;
  maximum_matching(vector<vector<int>> &e)
      : n(e.size()), m(n, -1), l(n), p(n), o(n), v(n), e(e) {
    for (int i = 0; i < n; i++)
      if (m[i] == -1) mm += bfs(i);
  }
  int lca(int i, int j) {
    for (t++;; swap(i, j))
      if (i != -1) {
        if (v[i] == t) return i;
        v[i] = t;
        i = m[i] == -1 ? -1 : o[p[m[i]]];
      }
  }
  void blossom(int i, int j, int a) {
    while (o[i] != a) {
      p[i] = j;
      j = m[i];
      if (l[j] == 1) l[j] = 0, q.push(j);
      o[i] = o[j] = a;
      i = p[j];
    }
  }
  bool bfs(int s) {
    for (int i = 0; i < n; i++) l[i] = -1, o[i] = i;
    while (!q.empty()) q.pop();
    l[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int i = q.front();
      q.pop();
      for (int j : e[i])
        if (l[j] == -1) {
          l[j] = 1;
          p[j] = i;
          if (m[j] == -1) {
            while (j != -1) m[j] = p[j], swap(j, m[m[j]]);
            return true;
          }
          l[m[j]] = 0;
          q.push(m[j]);
        } else if (l[j] == 0 && o[i] != o[j]) {
          int a = lca(o[i], o[j]);
          blossom(i, j, a);
          blossom(j, i, a);
        }
    }
    return false;
  }
};
int n, a[300100], r[300100], value, m, rng[300100][3], c = 1, comp[700];
bool u[300100], rngu[300100];
vector<int> er[2], te[700];
void fill() {
  int nv = 1;
  for (int i = 0; i < n - 1; i++)
    if (r[i] == 0 && r[i + 1] == 0) {
      while (u[nv]) nv++;
      r[i] = r[i + 1] = nv, value++, u[nv] = true;
    }
  for (int i = 0; i < n; i++)
    if (r[i] == 0) r[i] = 1;
}
void fillOE(int k, int av) {
  int i = rng[k][0], j = rng[k][1];
  if (av == a[i - 1])
    r[i] = av;
  else
    r[j] = av;
  value++, u[av] = true;
}
void fillE(int k) {
  int i = rng[k][0], j = rng[k][1];
  r[i] = r[i - 1], r[j] = r[j + 1];
  u[a[i - 1]] = u[a[j + 1]] = true;
  value++;
}
void dfsTree(int i, int p = -1) {
  for (int k : te[i]) {
    int j = i ^ rng[k][2];
    if (j != p) {
      fillOE(k, j);
      dfsTree(j, i);
    }
  }
}
void dfsComp(int i) {
  comp[i] = c;
  for (int k : te[i]) {
    int j = i ^ rng[k][2];
    if (comp[j] == 0) dfsComp(j);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i], r[i] = a[i];
  int s = 0;
  while (s < n && a[s] == 0) s++;
  if (s < n && s % 2 == 1) a[s - 1] = r[s - 1] = a[s], s--;
  int e = n - 1;
  while (e >= 0 && a[e] == 0) e--;
  if (e >= 0 && (n - e - 1) % 2 == 1) a[e + 1] = r[e + 1] = a[e], e++;
  if (s < e) {
    for (int i = s + 1; i < e; i++)
      if (a[i] == 0) {
        int j = i;
        while (a[j + 1] == 0) j++;
        rng[m][0] = i, rng[m][1] = j;
        rng[m][2] = a[i - 1] ^ a[j + 1];
        er[(j - i + 1) & 1].push_back(m);
        m++;
        i = j;
      }
    ufds uf(700);
    for (int k : er[1]) {
      int i = rng[k][0], j = rng[k][1];
      if (!uf.inSameSet(a[i - 1], a[j + 1])) {
        uf.unionSet(a[i - 1], a[j + 1]);
        te[a[i - 1]].push_back(k);
        te[a[j + 1]].push_back(k);
        rngu[k] = true;
      }
    }
    for (int k : er[1]) {
      int i = rng[k][0], j = rng[k][1];
      if (!rngu[k] && uf.inSameSet(a[i - 1], a[j + 1]) && !u[a[i - 1]]) {
        fillOE(k, a[i - 1]);
        dfsTree(a[i - 1]);
      }
    }
    for (int i = s; i < e; i++)
      if (a[i] > 0 && a[i] == a[i + 1] && !u[a[i]])
        value++, u[a[i]] = true, dfsTree(a[i]);
    for (int i = 1; i <= min(n, 600); i++)
      if (!u[i] && comp[i] == 0) dfsComp(i), c++;
    vector<vector<int>> e(c);
    for (int k : er[0]) {
      int i = rng[k][0], j = rng[k][1];
      if (!u[a[i - 1]] && !u[a[j + 1]] && comp[a[i - 1]] != comp[a[j + 1]]) {
        e[comp[a[i - 1]]].push_back(comp[a[j + 1]]),
            e[comp[a[j + 1]]].push_back(comp[a[i - 1]]);
      }
    }
    maximum_matching mm(e);
    for (int k : er[0]) {
      int i = rng[k][0], j = rng[k][1];
      if (mm.m[comp[a[i - 1]]] != -1 &&
          mm.m[comp[a[i - 1]]] == comp[a[j + 1]]) {
        fillE(k);
        dfsTree(a[i - 1]);
        dfsTree(a[j + 1]);
        mm.m[comp[a[i - 1]]] = -1, mm.m[comp[a[j + 1]]] = -1;
      }
    }
    for (int i = 1; i <= min(n, 600); i++)
      if (!u[i]) dfsTree(i);
  }
  fill();
  for (int i = 0; i < n; i++) cout << r[i] << (i < n - 1 ? " " : "\n");
}
