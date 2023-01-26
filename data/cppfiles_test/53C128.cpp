#include <bits/stdc++.h>
using namespace std;
namespace {
using T = long long;
namespace module {
inline const T m = 998244353;
void add(T& a, T b) {
  if ((a += b) >= m) a -= m;
}
void dec(T& a, T b) {
  if ((a -= b) < 0) a += m;
}
void mul(T& a, T b) { a = a * b % m; }
T radd(T a, T b) { return (a += b) >= m ? a - m : a; }
T rdec(T a, T b) { return (a -= b) < 0 ? a + m : a; }
T rmul(T a, T b) { return a * b % m; }
};  // namespace module
constexpr char endl = '\n';
const int maxN = 2e5 + 5;
int n;
char c;
string s;
set<int> ban;
void solve() {
  cin >> n >> c >> s;
  bool all = true;
  for (int i = 0; i < n; i++) all &= s[i] == c;
  if (all) return cout << 0 << endl, void();
  for (int i = n; i >= 2; i--) {
    bool ok = true;
    for (int j = i - 1; j < n && ok; j += i) ok &= s[j] == c;
    if (ok) return cout << 1 << endl << i << endl, void();
  }
  cout << 2 << endl << n - 1 << ' ' << n << endl;
}
}  // namespace
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t(1);
  cin >> t;
  for (int i = 1; i <= t; i++) solve();
}
