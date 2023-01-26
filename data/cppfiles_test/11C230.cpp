#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char *x) { cout << '\"' << x << '\"'; }
void __print(const string &x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cout << '{';
  __print(x.first);
  cout << ',';
  __print(x.second);
  cout << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cout << '{';
  for (auto &i : x) cout << (f++ ? "," : ""), __print(i);
  cout << "}";
}
void _print() { cout << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cout << ", ";
  _print(v...);
}
const long long mod = 998244353;
const double epsilon = 1e-8;
int n;
string s;
int cnt[200005][5];
int id[200005];
int goblc;
int fuckint = 0;
void process() {
  int tcase = 1;
  cin >> tcase;
  for (int ttcase = 1; ttcase <= tcase; ttcase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> s;
      for (int c = 0; c < 5; c++) cnt[i][c] = 0;
      for (char c : s) cnt[i][c - 'a']++;
      id[i] = i;
    }
    int res = 0;
    for (int c = 0; c < 5; c++) {
      goblc = c;
      sort(id + 1, id + n + 1, [](int &ax, int &bx) {
        int maxax = accumulate(cnt[ax], cnt[ax] + 5, fuckint) - cnt[ax][goblc];
        int maxbx = accumulate(cnt[bx], cnt[bx] + 5, fuckint) - cnt[bx][goblc];
        if ((cnt[ax][goblc] - maxax) == (cnt[bx][goblc] - maxbx))
          return cnt[ax][goblc] > cnt[bx][goblc];
        return (cnt[ax][goblc] - maxax) > (cnt[bx][goblc] - maxbx);
      });
      int ft[5];
      for (int i = 0; i < 5; i++) ft[i] = 0;
      int respre = 0;
      for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) ft[j] += cnt[id[i]][j];
        int maxax = accumulate(ft, ft + 5, fuckint) - ft[c];
        if (ft[c] <= maxax) {
          for (int j = 0; j < 5; j++) ft[j] -= cnt[id[i]][j];
          continue;
        }
        respre++;
      }
      res = max(res, respre);
    }
    cout << res << "\n";
  }
}
int online = 2;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (online == 0) {
    freopen("in.inp", "r", stdin);
    freopen("out.out", "w", stdout);
  } else if (online == 1) {
    freopen("dddd.inp", "r", stdin);
    freopen("dddd.out", "w", stdout);
  }
  process();
  return 0;
}
