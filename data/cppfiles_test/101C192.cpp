#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdb = pair<double, double>;
struct custom_hash {
  static ull splitmix64(ull x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(ull x) const {
    static const ull FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
const int N = (int)2e5 + 5;
const int M = (int)1e5 + 5;
const ll mod = 1e9 + 7, mod2 = 1e9 + 9;
const ull base = 131;
const double pi = acos(-1.0);
int _, CNT = -1;
vector<ll> app[2];
ll n;
ll a[N];
string s;
void work(std::istream& in, std::ostream& out) {
  app[0].clear();
  app[1].clear();
  in >> n;
  for (ll i = 1; i <= n; i++) in >> a[i];
  in >> s;
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == 'B')
      app[0].push_back(a[i]);
    else
      app[1].push_back(a[i]);
  }
  sort(app[0].begin(), app[0].end());
  sort(app[1].begin(), app[1].end());
  for (int i = 0; i < (int)app[0].size(); i++) {
    if (app[0][i] < i + 1) {
      out << "NO\n";
      return;
    }
  }
  ll cnt = n;
  for (int i = (int)app[1].size() - 1; i >= 0; i--) {
    if (app[1][i] > cnt) {
      out << "NO\n";
      return;
    }
    cnt--;
  }
  out << "YES\n";
}
class TaskD {
 public:
  void solve(std::istream& in, std::ostream& out) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    _ = 1;
    in >> _;
    while (_--) {
      work(in, out);
    }
  }
};
int main() {
  TaskD solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
