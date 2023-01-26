#include <bits/stdc++.h>
using namespace std;
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
template <typename T>
std::ostream& operator<<(std::ostream& stream, const vector<T>& vec) {
  for (size_t i = 0; i < vec.size(); i++) {
    stream << vec[i];
    if (i != vec.size() - 1) stream << ' ';
  };
  return stream;
}
template <typename T>
std::istream& operator>>(std::istream& stream, vector<T>& vec) {
  for (T& x : vec) stream >> x;
  return stream;
}
template <typename T, typename U>
std::ostream& operator<<(std::ostream& stream, const pair<T, U>& pr) {
  stream << pr.first << ' ' << pr.second;
  return stream;
}
template <typename T, typename U>
std::istream& operator>>(std::istream& stream, pair<T, U>& pr) {
  stream >> pr.first >> pr.second;
  return stream;
}
template <typename T>
void operator+=(vector<T>& vec, const T value) {
  for (T& x : vec) x += value;
}
template <typename T>
void operator-=(vector<T>& vec, const T value) {
  for (T& x : vec) x -= value;
}
template <typename T>
void operator++(vector<T>& vec) {
  vec += 1;
}
template <typename T>
void operator++(vector<T>& vec, T) {
  vec += 1;
}
template <typename T>
void operator--(vector<T>& vec) {
  vec -= 1;
}
template <typename T>
void operator--(vector<T>& vec, T) {
  vec -= 1;
}
template <typename T>
void operator*=(vector<T>& vec, const T value) {
  for (T& x : vec) x *= value;
}
template <typename T>
void operator/=(vector<T>& vec, const T value) {
  for (T& x : vec) x /= value;
}
template <typename T, typename U>
void operator+=(pair<T, U>& vec, const T value) {
  vec.first += value;
  vec.second += value;
}
template <typename T, typename U>
void operator-=(pair<T, U>& vec, const T value) {
  vec.first -= value;
  vec.second -= value;
}
template <typename T, typename U>
void operator++(pair<T, U>& vec) {
  vec += 1;
}
template <typename T, typename U>
void operator++(pair<T, U>& vec, T) {
  vec += 1;
}
template <typename T, typename U>
void operator--(pair<T, U>& vec) {
  vec -= 1;
}
template <typename T, typename U>
void operator--(pair<T, U>& vec, T) {
  vec -= 1;
}
template <typename T, typename U>
void operator*=(pair<T, U>& vec, const T value) {
  vec.first *= value;
  vec.second *= value;
}
template <typename T, typename U>
void operator/=(pair<T, U>& vec, const T value) {
  vec.first /= value;
  vec.second /= value;
}
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(char c) {
  string s;
  s += c;
  return s;
}
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "1" : "0"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
void bharo(int N_N) { return; }
template <typename Head, typename... Tail>
void bharo(int N_N, Head& H, Tail&... T) {
  H.resize(N_N);
  bharo(N_N, T...);
}
void safai() { return; }
template <typename Head, typename... Tail>
void safai(Head& H, Tail&... T) {
  H.clear();
  safai(T...);
}
vector<vector<int>> dx = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
void testcase() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int cnt;
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  function<void(int, int)> dfs = [&](int i, int j) {
    if (vis[i][j]) return;
    cnt++;
    vis[i][j] = true;
    for (int k = 0; k < 4; k++) {
      if (1 << k & a[i][j]) continue;
      int x = i + dx[k][0], y = j + dx[k][1];
      if (min(x, y) >= 0 && x < n && y < m) {
        dfs(x, y);
      }
    }
  };
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cnt = 0;
      dfs(i, j);
      if (cnt) ans.push_back(cnt);
    }
  }
  sort(ans.rbegin(), ans.rend());
  for (int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i];
    if (i != (int)ans.size() - 1) cout << ' ';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  while (tt--) {
    testcase();
  }
  return (0 - 0);
}
