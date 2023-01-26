#include <bits/stdc++.h>
using namespace std;
void Err() {}
template <class T, class... A>
void Err(T a, A... x) {
  cerr << a << ',';
  Err(x...);
}
template <class X, class Y, class... A>
void Err(pair<X, Y> a, A... x) {
  cerr << '(' << a.first << ',' << a.second << "),";
  Err(x...);
}
template <template <class...> class T, class t, class... A>
void Err(T<t> a, A... x) {
  cerr << a.size() << ":{";
  for (auto v : a) Err(v);
  cerr << "},";
  Err(x...);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rnd(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng);
}
template <class T>
void Min(T &a, const T b) {
  if (a > b) a = b;
}
template <class T>
void Max(T &a, const T b) {
  if (a < b) a = b;
}
const long long linf = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int N = 2e7 + 10, M = 500;
const long long mod = 1e9 + 7;
const long double eps = 1e-8;
int sgn(long double a) { return a < -eps ? -1 : (a < eps ? 0 : 1); }
void solve() {
  int n;
  cin >> n;
  vector<int> ar(n / 3), ans(n + 1, -1);
  int id[2];
  for (int i = 1; i < n; i += 3) {
    cout << "? " << i << ' ' << i + 1 << ' ' << i + 2 << endl;
    cin >> ar[i / 3];
    id[ar[i / 3]] = i / 3;
  }
  int be[2]{};
  auto f = [&]() {
    int vis[3]{};
    bool ok = 0;
    for (int i = 0; i < 3; i++) {
      cout << "? " << id[0] * 3 + 1 << ' ' << id[0] * 3 + 2 << ' '
           << id[1] * 3 + i + 1 << endl;
      cin >> vis[i];
      if (vis[i] == 1) ok = 1;
    }
    if (ok) {
      ans[id[0] * 3 + 3] = 0;
      for (int i = 0; i < 3; i++) {
        ans[id[1] * 3 + i + 1] = vis[i];
      }
      be[0] = id[0] * 3 + 3;
      for (int i = 0; i < 3; i++)
        if (vis[i]) {
          be[1] = id[1] * 3 + i + 1;
          cout << "? " << id[0] * 3 + 1 << ' ' << id[0] * 3 + 3 << ' '
               << id[1] * 3 + i + 1 << endl;
          cin >> ans[id[0] * 3 + 1];
          ans[id[0] * 3 + 2] = !ans[id[0] * 3 + 1];
          return;
        }
    }
    ans[id[0] * 3 + 1] = ans[id[0] * 3 + 2] = 0;
    be[0] = id[0] * 3 + 1;
    for (int i = 0; i < 3; i++) {
      cout << "? " << be[0] << ' ' << id[1] * 3 + i + 1 << ' '
           << id[1] * 3 + (i + 1) % 3 + 1 << endl;
      cin >> vis[i];
      if (vis[i] == 1) {
        be[1] = id[1] * 3 + i + 1;
        ans[id[1] * 3 + i + 1] = ans[id[1] * 3 + (i + 1) % 3 + 1] = 1;
        cout << "? " << be[0] << ' ' << be[1] << ' '
             << id[1] * 3 + (i + 2) % 3 + 1 << endl;
        cin >> ans[id[1] * 3 + (i + 2) % 3 + 1];
        cout << "? " << be[0] << ' ' << be[1] << ' ' << id[0] * 3 + 3 << endl;
        cin >> ans[id[0] * 3 + 3];
        return;
      }
    }
  };
  f();
  for (int i = 0; i < n / 3; i++) {
    int a = i * 3 + 1, b = i * 3 + 2, c = i * 3 + 3;
    if (~ans[a]) continue;
    cout << "? " << be[!ar[i]] << ' ' << b << ' ' << a << endl;
    int d;
    cin >> d;
    if (d == ar[i]) {
      ans[a] = ans[b] = ar[i];
      cout << "? " << be[0] << ' ' << be[1] << ' ' << c << endl;
      cin >> ans[c];
    } else {
      ans[c] = ar[i];
      cout << "? " << be[0] << ' ' << be[1] << ' ' << a << endl;
      cin >> ans[a];
      ans[b] = !ans[a];
    }
  }
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (ans[i] == 0) {
      v.push_back(i);
    }
  }
  cout << "! " << v.size();
  for (auto i : v) cout << ' ' << i;
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int _;
  cin >> _;
  while (_--) {
    solve();
  }
}
