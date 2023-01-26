#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct compF {
  bool operator()(const pair<T, T> &a, const pair<T, T> &b) {
    return a.first < b.first;
  }
};
template <typename T>
struct compS {
  bool operator()(const pair<T, T> &a, const pair<T, T> &b) {
    return a.second < b.second;
  }
};
template <typename T>
void printMatrix(const string &txt, vector<vector<T>> &a) {
  cout << txt;
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < a[i].size(); ++j) cout << a[i][j] << ' ';
    cout << endl;
  }
}
template <typename T>
void printVector(const string &txt, vector<T> &a) {
  cout << txt;
  for (int i = 0; i < a.size(); ++i) cout << a[i] << ' ';
  cout << endl;
}
template <typename T>
void readVector(int n, vector<T> &a) {
  if (a.size() < n) a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
}
template <typename T>
T lb(const set<T> &a, T x) {
  auto it = a.lower_bound(x);
  if (it == a.end()) return -1;
  return *it;
}
template <typename T>
T ub(const set<T> &a, T x) {
  auto it = a.upper_bound(x);
  if (it == a.end()) return -1;
  return *it;
}
template <typename T>
T rlb(const set<T> &a, T x) {
  auto it = a.lower_bound(x);
  if (it == a.begin()) {
    if (*it > x) return -1;
    return *it;
  }
  it = prev(it);
  return *it;
}
template <typename T>
T rub(const set<T> &a, T x) {
  auto it = a.lower_bound(x);
  if (it == a.begin()) {
    return -1;
  }
  it = prev(it);
  return *it;
}
template <typename T1, typename T2>
bool exist(map<T1, T2> &m, T1 x) {
  if (m.find(x) == m.end()) return false;
  return true;
}
long long gcd(long long a, long long b) {
  while (a != 0 && b != 0) {
    if (b > a)
      b %= a;
    else
      a %= b;
  }
  return a + b;
}
long long minFactor(long long x) {
  for (long long i = 2; i * i <= x; ++i)
    if (x % i == 0) return i;
  return x;
}
long long allFactors(long long x, vector<long long> &prms,
                     vector<long long> &prm_cnt) {
  prms.clear();
  prm_cnt.clear();
  while (x > 1) {
    long long t = minFactor(x);
    prms.push_back(t);
    int s = prms.size() - 1;
    prm_cnt.push_back(0);
    while (x % t == 0) {
      x /= t;
      ++prm_cnt[s];
    }
  }
  return 0;
}
long long add(long long a, long long b) {
  if (a > 998244353) a %= 998244353;
  if (b > 998244353) b %= 998244353;
  return (a + b) % 998244353;
}
long long sub(long long a, long long b) {
  if (a > 998244353) a %= 998244353;
  if (b > 998244353) b %= 998244353;
  long long x = a - b;
  while (x < 0) x += 998244353;
  return x;
}
long long mul(long long a, long long b) {
  if (a > 998244353) a %= 998244353;
  if (b > 998244353) b %= 998244353;
  return (a * b) % 998244353;
}
long long pow_(long long a, long long b) {
  if (b == 0) return 1ll;
  if (b % 2 == 0) {
    long long k = pow_(a, b / 2);
    return mul(k, k);
  } else {
    long long k = pow_(a, b - 1);
    return mul(a, k);
  }
}
int a[1000][1000] = {0, 0};
int n, m, q;
long long dp[1000][1000][2] = {0, 0, 0};
pair<int, int> st1(int x, int y) {
  int len1 = 0;
  int xx = x, yy = y;
  while (xx >= 0 && yy >= 0 && !a[xx][yy]) {
    len1++;
    if (len1 % 2 == 1)
      --xx;
    else
      --yy;
  }
  xx = x, yy = y;
  int len2 = 0;
  while (xx < n && yy < m && !a[xx][yy]) {
    len2++;
    if (len2 % 2 == 1)
      ++yy;
    else
      ++xx;
  }
  return {len1, len2};
}
pair<int, int> st2(int x, int y) {
  int len1 = 0;
  int xx = x, yy = y;
  while (xx >= 0 && yy >= 0 && !a[xx][yy]) {
    len1++;
    if (len1 % 2 == 1)
      --yy;
    else
      --xx;
  }
  xx = x, yy = y;
  int len2 = 0;
  while (xx < n && yy < m && !a[xx][yy]) {
    len2++;
    if (len2 % 2 == 1)
      ++xx;
    else
      ++yy;
  }
  return {len1, len2};
}
long long C(long long x) { return (x * (x - 1)) / 2; }
long long R(long long x) { return (x * (x + 1)) / 2; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cin >> n >> m >> q;
  unsigned long long curr_res = 0;
  dp[0][0][0] = dp[0][0][1] = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (i == 0 && j == 0) continue;
      if (j > 0) dp[i][j][0] += dp[i][j - 1][1] + 1;
      if (i > 0) dp[i][j][1] += dp[i - 1][j][0] + 1;
    }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      for (int k = 0; k < 2; ++k) {
        curr_res += max(dp[i][j][k], 0ll);
      }
  curr_res += n * m;
  while (q--) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    if (a[x][y] == 1) {
      a[x][y] = 0;
      pair<int, int> p1 = st1(x, y);
      pair<int, int> p2 = st2(x, y);
      int l1 = p1.first - 1, l2 = p1.second - 1;
      curr_res += l1;
      curr_res += l2;
      curr_res += l1 * l2;
      l1 = p2.first - 1, l2 = p2.second - 1;
      curr_res += l1;
      curr_res += l2;
      curr_res += l1 * l2;
      ++curr_res;
    } else {
      pair<int, int> p1 = st1(x, y);
      pair<int, int> p2 = st2(x, y);
      int l1 = p1.first - 1, l2 = p1.second - 1;
      curr_res -= l1;
      curr_res -= l2;
      curr_res -= l1 * l2;
      l1 = p2.first - 1, l2 = p2.second - 1;
      curr_res -= l1;
      curr_res -= l2;
      curr_res -= l1 * l2;
      curr_res--;
      a[x][y] = 1;
    }
    cout << curr_res << endl;
  }
  return 0;
}
