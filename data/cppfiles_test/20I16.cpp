#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<long long, long long>;
const double EPS = 1e-9;
const long long INF = 1e18;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
template <typename T>
void debug_out(string s, T t) {
  cout << "[" << s << ": " << t << "]\n";
}
template <typename T, typename... U>
void debug_out(string s, T t, U... u) {
  long long w = 0, c = 0;
  while (w < (long long)s.size()) {
    if (s[w] == '(') c++;
    if (s[w] == ')') c--;
    if (!c and s[w] == ',') break;
    w++;
  }
  cout << "[" << s.substr(0, w) << ": " << t << "] ";
  debug_out(s.substr(w + 2, (long long)s.size() - w - 1), u...);
}
const long long N = 1e6 + 5;
long long c[10005], intersect[105][105];
vector<long long> idx[105];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  for (long long i = 1; i <= n * k; i++) cin >> c[i], idx[c[i]].push_back(i);
  for (long long i = 1; i <= n; i++) {
    long long mn = INF;
    for (long long j = 0; j + 1 < ((long long)(idx[i]).size()); j++) {
      mn = min(mn, idx[i][j + 1] - idx[i][j]);
    }
    for (long long j = 0; j + 1 < ((long long)(idx[i]).size()); j++) {
      if (idx[i][j + 1] - idx[i][j] == mn) {
        cout << idx[i][j] << " " << idx[i][j + 1] << "\n";
        break;
      }
    }
  }
  return 0;
}
