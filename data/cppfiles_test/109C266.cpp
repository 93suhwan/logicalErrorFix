#include <bits/stdc++.h>
bool local = false;
using namespace std;
template <class T>
void print(T v) {
  cout << ((int)(v).size()) << "\n";
  for (auto x : v) cout << x << ' ';
  cout << "\n";
};
template <class T>
void print1(T v) {
  cout << ((int)(v).size()) << "\n";
  for (auto x : v) cout << x + 1 << ' ';
  cout << "\n";
};
template <class T1, class T2>
ostream &operator<<(ostream &o, pair<T1, T2> x) {
  return o << x.first << ' ' << x.second;
}
template <class T1, class T2>
istream &operator>>(istream &o, pair<T1, T2> &x) {
  return o >> x.first >> x.second;
}
template <class T>
ostream &operator<<(ostream &o, vector<T> &x) {
  for (auto &el : x) o << el << ' ';
  return o;
}
template <class T>
istream &operator>>(istream &o, vector<T> &x) {
  for (auto &el : x) o >> el;
  return o;
}
template <class T1, class T2>
pair<T1, T2> operator+(pair<T1, T2> a, pair<T1, T2> b) {
  a.first += b.first;
  a.second += b.second;
  return a;
}
template <class T1, class T2>
pair<T1, T2> operator-(pair<T1, T2> a, pair<T1, T2> b) {
  a.first -= b.first;
  a.second -= b.second;
  return a;
}
template <class T1, class T2>
void operator+=(pair<T1, T2> &a, pair<T1, T2> b) {
  a.first += b.first;
  a.second += b.second;
}
template <class T1, class T2>
void operator-=(pair<T1, T2> &a, pair<T1, T2> b) {
  a.first -= b.first;
  a.second -= b.second;
}
int nint() {
  int x;
  cin >> x;
  return x;
}
double getTime() { return clock() / (double)CLOCKS_PER_SEC; };
mt19937 rnd(0);
int rand(int n) { return rnd() % n; }
int rand(int l, int r) { return rnd() % (r - l + 1) + l; }
const int mod = 1000000000 + 7;
void initIO() {
  if (local) {
    freopen("input.txt", "r", stdin);
    srand((int)time(0));
    rnd.seed((int)time(0));
  } else {
    {
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
    };
  }
}
void solve();
void precalc();
int TID;
signed main() {
  initIO();
  int tc = 1;
  cin >> tc;
  precalc();
  for (int tt = 0; tt < (tc); tt++) {
    TID = tt;
    solve();
  }
  if (local)
    cout << "\n"
         << "time = " << getTime() << "\n";
}
void precalc() {}
int n;
int m;
void solve() {
  string s;
  cin >> n >> s;
  int ans = s.back() - 48;
  for (int i = 0; i < (n - 1); i++) {
    if (s[i] != 48) ans += s[i] - 47;
  }
  cout << ans << "\n";
}
