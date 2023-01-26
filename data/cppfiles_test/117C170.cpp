#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
template <class T>
inline void ckmin(T &a, T b) {
  a = min(a, b);
}
template <class T>
inline void ckmax(T &a, T b) {
  a = max(a, b);
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
using uint = unsigned int;
using int64 = long long int;
using uint64 = unsigned long long int;
using ipair = pair<int, int>;
using VI = vector<int>;
using VD = vector<double>;
void _print(int64 t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(uint64 t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
struct gg {
  int x;
  int y;
  char direction;
  gg(int x, int y, char direction) : x(x), y(y), direction(direction) {}
};
bool valid(int x, int y, int n, int m) {
  return (x >= 0 && x < n && y < m && y >= 0);
}
int xx[] = {1, -1, 0, 0};
int yy[] = {0, 0, 1, -1};
char dd[] = {'d', 'u', 'l', 'r'};
char rdd[] = {'u', 'd', 'r', 'l'};
int main() {
  std::ios::sync_with_stdio(false);
  int test;
  cin >> test;
  while (test--) {
    int n, m;
    cin >> n >> m;
    string a[n];
    queue<gg> q;
    for (int i = 0; i < (n); ++i) {
      cin >> a[i];
    }
    int cc = 0;
    int hh = 0;
    for (int i = 0; i < (n); ++i)
      for (int j = 0; j < (m); ++j) {
        if (a[i][j] == 'L') {
          cc++;
          for (int k = 0; k < 4; ++k) {
            int x = i + xx[k];
            int y = j + yy[k];
            if (valid(x, y, n, m) && a[x][y] == '.') {
              q.push(gg(x, y, dd[k]));
            }
          }
        }
        if (a[i][j] == '#') hh++;
      }
    while (!q.empty()) {
      gg g = q.front();
      q.pop();
      int count = 0;
      int x1, y1, ind;
      for (int i = 0; i < 4; ++i) {
        if (g.direction == rdd[i]) continue;
        int x = g.x + xx[i];
        int y = g.y + yy[i];
        if (valid(x, y, n, m) && a[x][y] == '.') {
          count++;
          x1 = x;
          y1 = y;
          ind = i;
        }
      }
      if (count == 1) {
        q.push(gg(x1, y1, dd[ind]));
      }
      if (count <= 1) {
        a[g.x][g.y] = '+';
      }
    }
    for (int i = 0; i < (n); ++i) {
      printf("%s\n", a[i].c_str());
    }
  }
  return 0;
}
