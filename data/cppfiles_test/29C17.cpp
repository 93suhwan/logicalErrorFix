#include <bits/stdc++.h>
using namespace std;
inline void pisz(int n) { printf("%d\n", n); }
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, -1, 0, 1};
const int drr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dcc[8] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  for (int i = 0; i < ((int)((t).size())); i++) s << t[i] << " ";
  return s;
}
class UnionFind {
 private:
  vector<int> rank, p;

 public:
  UnionFind(int n) {
    for (int i = 0; i < n; i++) p.push_back(i);
    rank.assign(n, 0);
  }
  int findSet(int s) { return (p[s] == s) ? s : (p[s] = findSet(p[s])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;
    int x = findSet(i), y = findSet(j);
    if (rank[x] > rank[y])
      p[y] = x;
    else {
      p[x] = y;
      if (rank[x] == rank[y]) rank[y]++;
    }
  }
};
bool fcomp(double A, double B) {
  double EPSILON = numeric_limits<double>::epsilon();
  double diff = A - B;
  return fabs(diff) < EPSILON;
}
double x_y(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main() {
  int(testow);
  scanf("%d", &(testow));
  while (testow--) {
    long long ct[2];
    memset(ct, 0, sizeof(ct));
    int(n);
    scanf("%d", &(n));
    int dt[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", &dt[i]);
      if (dt[i] == 0 || dt[i] == 1) ct[dt[i]]++;
    }
    long long mul = 1;
    for (int i = 1; i <= ct[0]; i++) mul *= 2;
    cout << ct[1] * mul << endl;
  }
  return 0;
}
