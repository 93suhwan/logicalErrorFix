#include <bits/stdc++.h>
using namespace std;
istream& operator>>(istream& in, __int128& a) {
  int64_t b;
  in >> b;
  a = b;
  return in;
}
ostream& operator<<(ostream& out, const __int128 a) {
  unsigned __int128 b = a < 0 ? -a : a;
  char buf[128];
  char* c = end(buf);
  do {
    --c;
    *c = "0123456789"[b % 10];
    b /= 10;
  } while (b);
  if (a < 0) {
    --c;
    *c = '-';
  }
  int64_t len = end(buf) - c;
  out.rdbuf()->sputn(c, len);
  return out;
}
template <class T>
void mini(T& a, T b) {
  a = min(a, b);
}
template <class T>
void maxi(T& a, T b) {
  a = max(a, b);
}
template <class T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <class T1, class T2>
ostream& operator<<(ostream& os, pair<T1, T2> const& a) {
  return os << "[" << a.first << ", " << a.second << "]";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os,
                                  Container const& a) {
  os << "{ ";
  for (auto& i : a) os << i << " ";
  return os << "}";
}
template <class T>
void out(T a) {
  cout << a << endl;
}
template <class T, class... Args>
void out(T a, Args... args) {
  cout << a << " ";
  out(args...);
}
template <class T>
void out(std::initializer_list<T> a) {
  for (auto i : a) {
    cout << i << " ";
  }
  cout << endl;
}
template <class T>
void out(vector<vector<T>> a) {
  for (vector<T> i : a) out(i);
}
template <class T>
void out_(T a[], int l, int r) {
  for (int i = l; i <= r; i++) cout << a[i] << " ";
  cout << endl;
}
void out() { cout << "OK" << endl; }
template <class T>
void sort(vector<T>& a) {
  sort(a.begin(), a.end());
}
template <class T>
void rever(vector<T>& a) {
  reverse(a.begin(), a.end());
}
template <class T>
void uniq(vector<T>& a) {
  sort(a);
  a.erase(unique(a.begin(), a.end()), a.end());
}
template <class T>
vector<T> set_int(vector<T> a, vector<T> b) {
  sort(a);
  sort(b);
  vector<T> res;
  set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
  return res;
}
clock_t start_time;
void start_timer() { start_time = clock(); }
double get_time() { return (double)(clock() - start_time) / CLOCKS_PER_SEC; }
template <class T>
using min_pque = priority_queue<T, vector<T>, greater<T>>;
const int N = 105;
int dp[N][N][N];
int p;
int C[N][N];
int fac[N];
int add(int a, int b) {
  a += b;
  if (a >= p) a -= p;
  return a;
}
int mult(int a, int b) { return a * 1ll * b % p; }
int sol(int n, int m, int k) {
  int& cur = dp[n][m][k];
  if (cur >= 0) {
    return cur;
  }
  cur = 0;
  if (n == 0) {
    if (k == 0) {
      cur = 1;
    }
    return cur;
  }
  if (m == 1) {
    if (k == 1) {
      cur = fac[n];
    }
    return cur;
  }
  if (m > n) {
    if (k == 0) {
      cur = fac[n];
    }
    return cur;
  }
  for (int i = 1; i <= n; i++) {
    int kek = 0;
    int l = max(0, k - n + i);
    int r = min(k, i - 1);
    for (int j = l; j <= r; j++) {
      int lol = mult(sol(i - 1, m - 1, j), sol(n - i, m - 1, k - j));
      kek = add(kek, lol);
    }
    kek = mult(kek, C[n - 1][i - 1]);
    cur = add(cur, kek);
  }
  return cur;
}
void Solve() {
  for (int n = 0; n <= N - 1; n++) {
    for (int m = 0; m <= N - 1; m++) {
      for (int k = 0; k <= N - 1; k++) {
        dp[n][m][k] = -1;
      }
    }
  }
  int n, m, k;
  cin >> n >> m >> k >> p;
  C[0][0] = 1;
  for (int n = 0; n <= N - 1; n++) {
    C[n][0] = C[n][n] = 1;
    for (int i = 1; i <= n - 1; i++) {
      C[n][i] = add(C[n - 1][i - 1], C[n - 1][i]);
    }
  }
  fac[0] = 1;
  for (int i = 1; i <= N - 1; i++) {
    fac[i] = mult(fac[i - 1], i);
  }
  int ans = sol(n, m, k);
  out(ans);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  start_timer();
  Solve();
  return 0;
}
