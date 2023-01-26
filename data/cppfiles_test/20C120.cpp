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
const int N = 405;
const int inf = 1e9;
int a[N][N];
int dp[N][N];
int b[N][N];
int c[N][N];
int cnt[2];
void Solve() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        char c;
        cin >> c;
        a[i][j] = c - '0';
      }
    }
    int ans = inf;
    for (int B = 4; B <= m; B++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          b[i][j] = inf;
          c[i][j] = inf;
          dp[i][j] = inf;
        }
      }
      for (int i = 1; i <= n; i++) {
        cnt[0] = cnt[1] = 0;
        for (int j = m; j >= 1; j--) {
          cnt[a[i][j]]++;
          if (j + B <= m) {
            cnt[a[i][j + B]]--;
          }
          if (j + B - 1 > m) continue;
          b[i][j] = cnt[0] - int(a[i][j] == 0) - int(a[i][j + B - 1] == 0);
          c[i][j] = cnt[1] - int(a[i][j] == 1) - int(a[i][j + B - 1] == 1);
          c[i][j] += int(a[i][j] == 0) + int(a[i][j + B - 1] == 0);
        }
      }
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (j + B - 1 > m) break;
          if (i >= 5) {
            mini(ans, b[i][j] + dp[i - 1][j]);
          }
          if (i >= 2) {
            mini(dp[i][j], dp[i - 1][j] + c[i][j]);
          }
          if (i >= 4) {
            mini(dp[i][j], c[i][j] + c[i - 1][j] + c[i - 2][j] + b[i - 3][j]);
          }
        }
      }
    }
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  start_timer();
  Solve();
  return 0;
}
