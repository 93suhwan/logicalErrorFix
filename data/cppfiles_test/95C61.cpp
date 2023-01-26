#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T, size_t N>
inline ostream &operator<<(ostream &os, const array<T, N> &a) {
  os << "[";
  int cnt = 0;
  for (auto &val : a) {
    if (cnt++) os << ", ";
    os << val;
  }
  os << "]";
  return os;
}
template <typename T>
inline ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "]";
}
template <typename T>
inline ostream &operator<<(ostream &os, const set<T> &v) {
  os << "{";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "}";
}
template <typename T>
inline ostream &operator<<(ostream &os, const unordered_set<T> &v) {
  os << "{";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "}";
}
template <typename T>
inline ostream &operator<<(ostream &os, const multiset<T> &v) {
  os << "{";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "}";
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const map<T1, T2> &v) {
  os << "[";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "]";
}
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vs = vector<string>;
using vb = vector<bool>;
using vd = vector<double>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vc = vector<char>;
using si = set<int>;
using mpii = map<int, int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const char nl = '\n';
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}
struct RMQ {
  const static int N = 1000005;
  const static int M = 20;
  int mi[N][M], ma[N][M];
  void init(int n, vector<int> &val) {
    for (int i = 0; i < n; i++) mi[i][0] = ma[i][0] = val[i];
    for (int j = 1; j <= log((double)n) / log(2.0); j++) {
      for (int i = 0; i + (1 << j) - 1 < n; i++) {
        ma[i][j] = max(ma[i][j - 1], ma[i + (1 << (j - 1))][j - 1]);
        mi[i][j] = min(mi[i][j - 1], mi[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  int getMax(int a, int b) {
    assert(a <= b);
    int k = (int)(log((double)b - a + 1) / log(2.0));
    return max(ma[a][k], ma[b - (1 << k) + 1][k]);
  }
  int getMin(int a, int b) {
    assert(a <= b);
    int k = (int)(log((double)b - a + 1) / log(2.0));
    return min(mi[a][k], mi[b - (1 << k) + 1][k]);
  }
} rmq;
struct Node {
  int rowId;
  pii leftValues;
  pii rightValues;
};
void solve() {
  int n, m;
  cin >> n >> m;
  vi val(n * m);
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (m); j++) cin >> val[i * m + j];
  rmq.init(n * m, val);
  auto getMin = [&](int row, int x, int y) -> int {
    x = row * m + x;
    y = row * m + y;
    return rmq.getMin(x, y);
  };
  auto getMax = [&](int row, int x, int y) -> int {
    x = row * m + x;
    y = row * m + y;
    return rmq.getMax(x, y);
  };
  vector<Node> data(n, Node());
  vector<int> p(n);
  vector<int> leftMin(n), rightMax(n);
  for (int column = 0; column < m - 1; ++column) {
    for (int i = 0; i < (n); i++) {
      data[i].rowId = i;
      data[i].leftValues = {getMin(i, 0, column), getMax(i, 0, column)};
      data[i].rightValues = {getMin(i, column + 1, m - 1),
                             getMax(i, column + 1, m - 1)};
    }
    iota((p).begin(), (p).end(), 0);
    sort((p).begin(), (p).end(), [&](int x, int y) {
      if (data[x].leftValues.second != data[y].leftValues.second)
        return data[x].leftValues.second < data[y].leftValues.second;
      return data[x].leftValues.first < data[y].leftValues.first;
    });
    leftMin[n - 1] = data[p[n - 1]].leftValues.first;
    for (int i = n - 2; i >= 0; i--)
      leftMin[i] = min(leftMin[i + 1], data[p[i]].leftValues.first);
    rightMax[n - 1] = data[p[n - 1]].rightValues.second;
    for (int i = n - 2; i >= 0; i--)
      rightMax[i] = max(rightMax[i + 1], data[p[i]].rightValues.second);
    int bluePos = -1;
    for (int blue = 0, rightMin = INT_MAX; blue < n - 1; blue++) {
      umin(rightMin, data[p[blue]].rightValues.first);
      if (leftMin[blue + 1] > data[p[blue]].leftValues.second &&
          rightMin > rightMax[blue + 1]) {
        bluePos = blue;
        break;
      }
    }
    if (bluePos != -1) {
      cout << "YES" << nl;
      string color(n, 'R');
      for (int i = 0; i < (bluePos + 1); i++) color[p[i]] = 'B';
      cout << color << " " << column + 1 << nl;
      return;
    }
  }
  cout << "NO" << nl;
}
void solve(int _cas) { solve(); }
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL), cout.precision(12);
  int cas;
  cin >> cas;
  for (int i = 0; i < (cas); i++) solve(i + 1);
}
