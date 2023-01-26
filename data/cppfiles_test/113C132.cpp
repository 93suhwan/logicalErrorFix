#include <bits/stdc++.h>
using namespace std;
namespace Color {
enum Code {
  FG_RED = 31,
  FG_GREEN = 32,
  FG_YELLOW = 33,
  FG_BLUE = 34,
  FG_DEFAULT = 39
};
class ColorDebugger {
  Code code;

 public:
  ColorDebugger(Code pCode) : code(pCode) {}
  template <class T>
  ColorDebugger& operator<<(const T& other) {
    cout << "\033[" << code << "m" << other << "\033[" << FG_DEFAULT << "m";
    return *this;
  }
  ColorDebugger& operator<<(ostream& (*pManip)(ostream&)) {
    (*pManip)(cout);
    return *this;
  }
};
}  // namespace Color
using namespace Color;
ColorDebugger ycout(FG_YELLOW);
ColorDebugger gcout(FG_GREEN);
const long long inf = 2e18;
const long long mod = 998244353;
const long long MAX = 2e5 + 20;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  vector<long long> a(n);
  long long sumi = 0;
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) sumi += a[i];
  sort(a.begin(), a.end());
  long long m;
  cin >> m;
  while (m--) {
    long long x, y;
    cin >> x >> y;
    long long ans = inf;
    auto it = lower_bound(a.begin(), a.end(), x);
    if (it != a.end()) {
      ans = min(ans, max(0LL, y - sumi + (*it)));
    }
    it--;
    ans = min(ans, max(0LL, y - sumi + (*it)) + abs((*it) - x));
    cout << ans << "\n";
  }
}
