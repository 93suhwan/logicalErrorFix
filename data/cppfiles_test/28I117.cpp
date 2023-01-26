#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void debug3(int *t, int st, int n) {
  cerr << '{' << t[st];
  for (int i = st + 1; i <= n; i++) cerr << ",", __print(t[i]);
  cerr << "}" << '\n';
}
const int MOD = 1e9 + 7;
int v[300005], a[300005], b[300005];
map<int, int> mp;
vector<int> sol;
set<int> s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, n, m, i, ct;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    mp.clear();
    sol.clear();
    for (i = 1; i <= n; i++) cin >> v[i];
    for (i = 1; i <= n; i++) a[i] = v[i] - i;
    for (i = 1; i <= n; i++) mp[a[i]]++;
    for (auto vec : mp) {
      if (n - vec.second > 2 * m) continue;
      if (n - vec.second <= m + 1)
        sol.push_back((n - vec.first) % n);
      else {
        for (i = 1; i <= n; i++) {
          if (i <= n - vec.second + 1)
            b[i] = a[i] - vec.first;
          else
            b[i] = (a[i] - vec.first + n) % n;
        }
        s.clear();
        ct = 0;
        for (i = 1; i <= n; i++) {
          if (b[i] == 0) continue;
          if (s.find(-b[i]) != s.end()) {
            s.erase(-b[i]);
            ct++;
          } else
            s.insert(b[i]);
        }
        if (n - vec.second - 2 * ct <= (m + 1 - ct))
          sol.push_back((n - vec.first) % n);
      }
    }
    sort(sol.begin(), sol.end());
    cout << sol.size() << " ";
    for (auto vec : sol) cout << vec << " ";
    cout << '\n';
  }
}
