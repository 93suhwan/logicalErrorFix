#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  } else
    return false;
}
template <class T>
bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  } else
    return false;
}
template <class T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &arr) {
  std::cout << "{";
  for (int i = 0; i < arr.size(); i++) std::cout << (!i ? "" : ", ") << arr[i];
  std::cout << "}";
  return out;
}
template <class T>
std::ostream &operator<<(std::ostream &out,
                         const std::vector<std::vector<T>> &arr) {
  std::cout << "{\n";
  for (auto &vec : arr) std::cout << "  " << vec << ",\n";
  std::cout << "}";
  return out;
}
template <class S, class T>
std::ostream &operator<<(std::ostream &out, const std::pair<S, T> &p) {
  std::cout << "{" << p.first << "," << p.second << "}" << '\n';
  return out;
}
template <class T>
std::istream &operator>>(std::istream &in, std::vector<T> &arr) {
  for (auto &i : arr) std::cin >> i;
  return in;
}
template <class S, class T>
std::istream &operator>>(std::istream &in, std::pair<S, T> &p) {
  std::cin >> p.first >> p.second;
  return in;
}
template <class T>
void debug_a(T *a, int N) {
  std::cout << "debug array : {";
  for (int i = 0; i < N; i++) {
    std::cout << *(a + i) << (i < N - 1 ? ", " : "}\n");
  }
}
struct io {
  io() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
  }
} ioboost;
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  auto inside = [&](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  };
  vector<vector<int>> state(n, vector<int>(m, 0));
  function<int(int, int, int, int, int)> func = [&](int x, int y, int dx,
                                                    int dy, int tmp) {
    if (!inside(x, y) || state[x][y]) {
      return tmp;
    }
    return func(x - dx, y + dy, !dx, !dy, tmp + 1);
  };
  function<int(int, int, int, int, int)> func2 = [&](int x, int y, int dx,
                                                     int dy, int tmp) {
    if (!inside(x, y) || state[x][y]) {
      return tmp;
    }
    return func2(x + dx, y - dy, !dx, !dy, tmp + 1);
  };
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans++;
      int d = min(n - i, m - j);
      int fi = i + d - 1;
      int fj = j + d - 1;
      int k = 4 * (d - 1);
      if (fi != n - 1 || fj != m - 1) {
        k++;
      }
      ans += k;
    }
  }
  for (int _ = 0; _ < q; _++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    x = (n - 1 - x);
    if (state[x][y]) {
      state[x][y] = 0;
      ll f, g;
      f = func(x, y, 0, 1, 0) - 1;
      g = func2(x, y, 1, 0, 0) - 1;
      if (f or g) {
        ans += f * g + f + g;
      }
      f = func(x, y, 1, 0, 0) - 1;
      g = func2(x, y, 0, 1, 0) - 1;
      if (f or g) {
        ans += f * g + f + g;
      }
      ans++;
    } else {
      ll f, g;
      f = func(x, y, 0, 1, 0) - 1;
      g = func2(x, y, 1, 0, 0) - 1;
      if (f or g) {
        ans -= f * g + f + g;
      }
      f = func(x, y, 1, 0, 0) - 1;
      g = func2(x, y, 0, 1, 0) - 1;
      if (f or g) {
        ans -= f * g + f + g;
      }
      ans--;
      state[x][y] = 1;
    }
    cout << ans << endl;
  }
}
