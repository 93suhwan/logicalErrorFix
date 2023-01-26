#include <bits/stdc++.h>
using namespace std;
template <typename T, typename V>
inline void mn(T &x, V y) {
  if (y < x) x = y;
}
template <typename T, typename V>
inline void mx(T &x, V y) {
  if (x < y) x = y;
}
int find(vector<int> &parents, vector<int> &rank, int v) {
  if (parents[v] == -1) return v;
  return parents[v] = find(parents, rank, parents[v]);
}
void Union(vector<int> &parents, vector<int> &rank, int a, int b) {
  if (rank[a] > rank[b]) {
    parents[b] = a;
  } else if (rank[a] < rank[b]) {
    parents[a] = b;
  } else {
    parents[a] = b;
    rank[b]++;
  }
}
bool isCyclic(vector<int> &parents, vector<int> &rank,
              vector<vector<int>> &Edges) {
  for (auto &x : Edges) {
    int a = find(parents, rank, x[0]);
    int b = find(parents, rank, x[1]);
    if (a == b) {
      return true;
    }
    if (rank[a] > rank[b]) {
      parents[b] = a;
    } else if (rank[a] < rank[b]) {
      parents[a] = b;
    } else {
      parents[a] = b;
      rank[b]++;
    }
  }
  return false;
}
void solve() {
  int f, s, n, m1, m2;
  cin >> n >> m1 >> m2;
  vector<vector<int>> adj1(n), adj2(n), ed1, ed2;
  for (int i = 0; i < m1; i++) {
    cin >> f >> s;
    f--;
    s--;
    ed1.push_back({f, s});
    adj1[f].push_back(s);
    adj1[s].push_back(f);
  }
  for (int i = 0; i < m2; i++) {
    cin >> f >> s;
    f--;
    s--;
    ed2.push_back({f, s});
    adj2[f].push_back(s);
    adj2[s].push_back(f);
  }
  vector<int> par1(n, -1), par2(n, -1), rank1(n), rank2(n);
  bool a = isCyclic(par1, rank1, ed1);
  bool b = isCyclic(par2, rank2, ed2);
  vector<vector<int>> ans;
  vector<int> q1, q2;
  int x1, x2, y1, y2, Y1, Y2;
  for (int i = 1; i < n; ++i) {
    x1 = find(par1, rank1, 0);
    x2 = find(par2, rank2, 0);
    y1 = find(par1, rank1, i);
    y2 = find(par2, rank2, i);
    if (x1 == y1 || x2 == y2) {
      continue;
    }
    ans.push_back({0 + 1, i + 1});
    Union(par1, rank1, x1, y1);
    Union(par2, rank2, x2, y2);
  }
  for (int i = 0; i < n; ++i) {
    x1 = find(par1, rank1, 0);
    x2 = find(par2, rank2, 0);
    y1 = find(par1, rank1, i);
    y2 = find(par2, rank2, i);
    if (x1 != y1) q1.push_back(i);
    if (x2 != y2) q2.push_back(i);
  }
  while (!q1.empty() && !q2.empty()) {
    int a = q1.back();
    int b = q2.back();
    x1 = find(par1, rank1, 0);
    x2 = find(par2, rank2, 0);
    y1 = find(par1, rank1, a);
    y2 = find(par2, rank2, a);
    Y1 = find(par1, rank1, b);
    Y2 = find(par2, rank2, b);
    if (y1 == x1 && y2 == x2) {
      q1.pop_back();
      continue;
    }
    if (Y1 == x1 && Y2 == x2) {
      q2.pop_back();
      continue;
    }
    Union(par1, rank1, y1, Y1);
    Union(par2, rank2, y2, Y2);
    ans.push_back({a + 1, b + 1});
  }
  cout << ans.size() << endl;
  for (auto &x : ans) {
    cout << x[0] << " " << x[1] << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
