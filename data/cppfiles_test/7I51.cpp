#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma comment(linker, "/STACK:256000000")
using namespace std;
mt19937 rd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
const int INF = 1000 * 1000 * 1000 + 322;
const long long LLINF =
    2LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL + 57;
constexpr int MOD = 1000 * 1000 * 1000 + 7;
constexpr int FFT_MOD = 998244353;
const int P1E6 = 1336337;
const int P1E3 = 1009;
const long long P1E14 = 100000000000031;
const long long P1E17 = 100000000000000003;
const long double PI = acosl(-1.);
const long double EPS = 1e-9;
template <typename T, typename U>
inline ostream& operator<<(ostream& _out, const pair<T, U>& _p) {
  _out << _p.x << " " << _p.y;
  return _out;
}
template <typename T, typename U>
inline istream& operator>>(istream& _in, pair<T, U>& _p) {
  _in >> _p.x >> _p.y;
  return _in;
}
template <typename T>
inline ostream& operator<<(ostream& _out, const vector<T>& _v) {
  if (_v.empty()) return _out;
  _out << _v.front();
  for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline istream& operator>>(istream& _in, vector<T>& _v) {
  for (auto& _i : _v) _in >> _i;
  return _in;
}
template <typename T>
inline ostream& operator<<(ostream& _out, const set<T>& _s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline ostream& operator<<(ostream& _out, const multiset<T>& _s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline ostream& operator<<(ostream& _out, const unordered_set<T>& _s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline ostream& operator<<(ostream& _out, const unordered_multiset<T>& _s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T, typename U>
inline ostream& operator<<(ostream& _out, const map<T, U>& _m) {
  if (_m.empty()) return _out;
  _out << "{\"" << _m.begin()->x << "\", \"" << _m.begin()->y << "\"}";
  for (auto _it = ++_m.begin(); _it != _m.end(); ++_it)
    _out << ", { \"" << _it->x << "\", \"" << _it->y << "\"}";
  return _out;
}
template <typename T, typename U>
inline ostream& operator<<(ostream& _out, const unordered_map<T, U>& _m) {
  if (_m.empty()) return _out;
  _out << '(' << _m.begin()->x << ": " << _m.begin()->y << ')';
  for (auto _it = ++_m.begin(); _it != _m.end(); ++_it)
    _out << ", (" << _it->x << ": " << _it->y << ')';
  return _out;
}
const char* infile = "";
const char* outfile = "";
inline long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline int pwm(long long xx, long long pow, int MD) {
  if (pow < 0) {
    pow = pow % (long long(MD) - 1) + MD - 1;
  }
  long long mlt = 1;
  while (pow) {
    if (pow & 1) {
      mlt *= xx;
      mlt %= MD;
    }
    xx *= xx;
    pow >>= 1;
    xx %= MD;
  }
  return (int)mlt;
}
inline long long gcdex(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long xx, yy;
  long long gc = gcdex(b, a % b, yy, xx);
  x = xx;
  y = yy - (a / b) * xx;
  return gc;
}
inline int inv(long long r, int _mod) {
  return pwm(r % _mod, long long(_mod) - 2, _mod);
}
const int N = 505;
int mv[N][2];
int at_last;
int dp[2][N][N];
inline void solve() {
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < m; ++i) {
    mv[i][b[i] - '0'] = i + 1;
    for (int st = 0; st <= i; ++st) {
      string t = b.substr(st, i - st);
      t.push_back('1' ^ '0' ^ b[i]);
      if (t == b.substr(0, (int)(t).size())) {
        mv[i][('1' ^ '0' ^ b[i]) - '0'] = (int)(t).size();
        break;
      }
    }
  }
  for (int st = 1; st < m; ++st) {
    string t = b.substr(st);
    if (t == b.substr(0, (int)(t).size())) {
      mv[(int)(b).size() - 1][b.back() - '0'] = (int)(t).size();
      break;
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j <= n; ++j) {
      dp[0][i][j] = INF;
    }
  }
  dp[0][0][0] = 0;
  for (int st = 0; st < n; ++st) {
    for (int cur_prf = 0; cur_prf < m; ++cur_prf) {
      for (int cnt = 0; cnt <= n; ++cnt) {
        dp[(st & 1) ^ 1][cur_prf][cnt] = INF;
      }
    }
    for (int cur_prf = 0; cur_prf < m; ++cur_prf) {
      for (int cnt = 0; cnt <= n; ++cnt) {
        dp[(st & 1) ^ 1][mv[cur_prf][b[cur_prf] - '0']]
          [cnt + (cur_prf == m - 1)] =
              min(dp[(st & 1) ^ 1][mv[cur_prf][b[cur_prf] - '0']]
                    [cnt + (cur_prf == m - 1)],
                  dp[(st & 1)][cur_prf][cnt] + (a[st] != b[cur_prf]));
        dp[(st & 1) ^ 1][mv[cur_prf][(b[cur_prf] ^ '1' ^ '0') - '0']][cnt] =
            min(dp[(st & 1) ^ 1][mv[cur_prf][(b[cur_prf] ^ '1' ^ '0') - '0']]
                  [cnt],
                dp[(st & 1)][cur_prf][cnt] + (a[st] == b[cur_prf]));
      }
    }
  }
  for (int poss = 0; poss <= n - m + 1; ++poss) {
    int ans = INF;
    for (int prf = 0; prf < m; ++prf) {
      ans = min(ans, dp[n & 1][prf][poss]);
    }
    cout << (ans == INF ? -1 : ans) << " ";
  }
  cout << '\n';
}
signed main() {
  if (*infile != '\0') {
    assert(freopen(infile, "r", stdin));
  }
  if (*outfile != '\0') {
    assert(freopen(outfile, "w", stdout));
  }
  cout.tie(nullptr);
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << setprecision(20);
  cout << fixed;
  solve();
  return 0;
}
