#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int int_inf = 2 * 1e9;
const long long ll_inf = 8 * 1e18;
#pragma GCC optimize("O3")
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<long long, int>;
using pll = pair<long long, long long>;
istream& operator>>(istream& in, pii& i) {
  in >> i.first >> i.second;
  return in;
}
template <class T>
istream& operator>>(istream& in, vector<T>& a) {
  for (auto& i : a) {
    in >> i;
  }
  return in;
}
template <class T>
ostream& operator<<(ostream& out, vector<T>& a) {
  for (auto i : a) {
    out << i;
  }
  return out;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long myRand(long long B) { return (unsigned long long)rng() % B; }
void solve() {
  string s, t;
  cin >> s >> t;
  string cur_s = "";
  for (int i = 0; i < s.size(); ++i) {
    cur_s += s[i];
    string cur_ss = cur_s;
    cur_ss.pop_back();
    reverse((cur_ss).begin(), (cur_ss).end());
    cur_ss = cur_s + cur_ss;
    size_t pos = cur_ss.find(t);
    if (pos != std::string::npos) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
