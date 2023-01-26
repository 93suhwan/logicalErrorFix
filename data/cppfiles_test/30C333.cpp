#include <bits/stdc++.h>
using namespace std;
struct _ {
  ios_base::Init i;
  _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); }
} _;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
const int MOD = 1e9 + 7;
class MainClass {
 public:
  void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = INT_MAX;
    for (char ch = 'a'; ch <= 'z'; ch++) {
      int curr = 0;
      for (int i = 0, j = n - 1; i < j;) {
        if (s[i] == s[j])
          i++, j--;
        else {
          if (s[i] == ch)
            curr++, i++;
          else if (s[j] == ch)
            curr++, j--;
          else {
            curr = INT_MAX;
            break;
          }
        }
      }
      ans = min(ans, curr);
    }
    cout << (ans == INT_MAX ? -1 : ans);
    return;
  }
};
int main() {
  int test = 1;
  cin >> test;
  for (int tst = 1; tst <= test; ++tst) {
    MainClass Ausmosian;
    Ausmosian.solve();
    cout << "\n";
  }
  return 0;
}
