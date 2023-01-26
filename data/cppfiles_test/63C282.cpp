#include <bits/stdc++.h>
using namespace std;
namespace IO {
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (s.size()) {
    setIn(s + ".inp");
    setOut(s + ".out");
  } else {
  }
}
}  // namespace IO
using namespace IO;
namespace Function {
template <typename T1, typename T2>
bool amax(T1 &a, T2 b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
bool amin(T1 &a, T2 b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T>
void compress(T &a) {
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());
}
template <typename T1, typename T2, typename T3>
int position(T1 Begin, T2 End, T3 val, bool type = 0) {
  if (type == 0) {
    return lower_bound(Begin, End, val) - Begin;
  }
  return upper_bound(Begin, End, val) - Begin;
}
template <typename T>
long long sqr(T x) {
  return 1LL * x * x;
}
template <typename T1, typename T2>
long long GCD(T1 a, T2 b) {
  return b == 0 ? a : GCD(b, a % b);
}
template <typename T1, typename T2>
long long LCM(T1 a, T2 b) {
  return 1LL * a / GCD(a, b) * b;
}
}  // namespace Function
using namespace Function;
namespace Output {
char End_Of_Stream = '\n';
void print(int x) { cout << x << End_Of_Stream; }
void print(unsigned int x) { cout << x << End_Of_Stream; }
void print(long unsigned int x) { cout << x << End_Of_Stream; }
void print(long long x) { cout << x << End_Of_Stream; }
void print(unsigned long long x) { cout << x << End_Of_Stream; }
void print(float x) { cout << x << End_Of_Stream; }
void print(double x) { cout << x << End_Of_Stream; }
void print(long double x) { cout << x << End_Of_Stream; }
void print(char x) { cout << x << End_Of_Stream; }
void print(const char *x) { cout << x << End_Of_Stream; }
void print(string x) { cout << x << End_Of_Stream; }
void print(bool x) { cout << x << End_Of_Stream; }
template <typename T1, typename T2>
void print(pair<T1, T2> a) {
  cout << a.first << " " << a.second << End_Of_Stream;
}
template <size_t sz>
void print(bitset<sz> a) {
  for (int i = 0; i < sz; i++) {
    cout << a[i];
  }
  cout << End_Of_Stream;
}
template <typename T>
void write(T x) {
  print(x);
}
template <class T, class... Ts>
void write(T t, Ts... ts) {
  write(t);
  write(ts...);
}
template <class T, class... Ts>
void print(T t, Ts... ts) {
  End_Of_Stream = ' ';
  write(t, ts...);
  cout << '\n';
  End_Of_Stream = '\n';
}
template <typename T>
void print(T a) {
  for (auto it : a) {
    print(it);
  }
}
template <class T, class... Ts>
void prine(T t, Ts... ts) {
  print(t, ts...);
  exit(0);
}
}  // namespace Output
using namespace Output;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int INF = 1e9 + 10;
const long long INFL = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
int root[N][2];
int get_root(int x, int type) {
  if (x != root[x][type]) {
    root[x][type] = get_root(root[x][type], type);
  }
  return root[x][type];
}
int main() {
  setIO();
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  for (int i = 1; i <= n; i++) {
    root[i][0] = root[i][1] = i;
  }
  while (m1--) {
    int u, v;
    cin >> u >> v;
    root[get_root(u, 0)][0] = get_root(v, 0);
  }
  while (m2--) {
    int u, v;
    cin >> u >> v;
    root[get_root(u, 1)][1] = get_root(v, 1);
  }
  vector<pair<int, int> > res;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int u1 = get_root(i, 0);
      int v1 = get_root(j, 0);
      int u2 = get_root(i, 1);
      int v2 = get_root(j, 1);
      if (u1 != v1 && u2 != v2) {
        res.push_back({i, j});
        root[u1][0] = v1;
        root[u2][1] = v2;
      }
    }
  }
  print(res.size());
  print(res);
  return 0;
}
