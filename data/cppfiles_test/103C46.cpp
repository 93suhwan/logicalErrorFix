#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
using pi = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vvi = vector<vector<int>>;
using vpi = vector<pi>;
string to_string(bool b) { return b ? "true" : "false"; }
template <typename T, typename U>
string to_string(pair<T, U> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename T, typename U, typename V>
string to_string(tuple<T, U, V> t) {
  return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " +
         to_string(get<2>(t)) + ")";
}
string to_string(string s) { return s; }
template <typename T>
string to_string(const vector<T>& v) {
  bool f = true;
  string s = "[";
  for (const auto& x : v) {
    if (!f) s += ", ";
    f = false;
    s += to_string(x);
  }
  s += "]";
  return s;
}
template <typename T>
string to_string(const T& g) {
  bool f = true;
  string s = "{";
  for (const auto& x : g) {
    if (!f) s += ", ";
    f = false;
    s += to_string(x);
  }
  s += "}";
  return s;
}
void init_io(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
template <typename T>
void debug(const T& t) {
  cout << to_string(t) << '\n';
}
pi next_point(int j, int k, int c) {
  switch (c) {
    case 'U':
      j--;
      break;
    case 'D':
      j++;
      break;
    case 'R':
      k++;
      break;
    default:
      k--;
      break;
  }
  return {j, k};
}
vector<vector<char>> grid(2000, vector<char>(2000));
vvi mem(2000, vi(2000, INT_MIN));
int main() {
  init_io();
  int t;
  cin >> t;
  while (t--) {
    string dummy;
    getline(cin, dummy);
    int n, m, j, k;
    cin >> n >> m;
    for (j = 0; j < n; j++) fill(mem[j].begin(), mem[j].end(), INT_MIN);
    for (j = 0; j < n; j++) {
      cin >> dummy;
      for (k = 0; k < m; k++) grid[j][k] = dummy[k];
    }
    for (j = 0; j < n; j++)
      for (k = 0; k < m; k++) {
        if (mem[j][k] == INT_MIN) {
          int x = j, y = k, c = 0;
          while (x >= 0 and y >= 0 and x < n and y < m and
                 mem[x][y] == INT_MIN) {
            mem[x][y] = -c;
            auto p = next_point(x, y, grid[x][y]);
            x = p.first, y = p.second, c++;
          }
          if (x >= 0 and y >= 0 and x < n and y < m) {
            if (mem[x][y] > 0) {
              int p = j, q = k;
              while (p != x or y != q) {
                mem[p][q] = c-- + mem[x][y];
                auto h = next_point(p, q, grid[p][q]);
                p = h.first, q = h.second;
              }
            } else {
              auto pt = next_point(x, y, grid[x][y]);
              int p = pt.first, q = pt.second;
              mem[x][y] += c;
              while (p != x or y != q) {
                mem[p][q] = mem[x][y];
                auto h = next_point(p, q, grid[p][q]);
                p = h.first, q = h.second;
              }
              p = j, q = k;
              while (p != x or q != y) {
                mem[p][q] = c--;
                auto h = next_point(p, q, grid[p][q]);
                p = h.first, q = h.second;
              }
            }
          } else {
            x = j, y = k;
            while (x >= 0 and y >= 0 and x < n and y < m) {
              mem[x][y] = c--;
              auto p = next_point(x, y, grid[x][y]);
              x = p.first, y = p.second;
            }
          }
        }
      }
    int mx = mem[0][0], e = 0, f = 0;
    for (j = 0; j < n; j++)
      for (k = 0; k < m; k++) {
        if (mem[j][k] > mx) mx = mem[j][k], e = j, f = k;
      }
    cout << e + 1 << " " << f + 1 << " " << mx << '\n';
  }
  return 0;
}
