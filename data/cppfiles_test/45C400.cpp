#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
using pr = pair<T, U>;
template <typename T>
using vt = vector<T>;
template <class T>
bool cmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool cmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
inline namespace CP {
inline namespace Output {
template <class T>
void outv(vector<T> v, int add = 0, bool standard = 1) {
  for (T& i : v) (standard ? cout : cerr) << (i + add) << " ";
  cout << '\n';
}
template <class T>
void put(T output) {
  cout << output << '\n';
}
}  // namespace Output
class IO {
 public:
  void setIn(string second) { (void)!freopen(second.c_str(), "r", stdin); }
  void setOut(string second) { (void)!freopen(second.c_str(), "w", stdout); }
  void Input(int __use_input = 0) {
    if (!!__use_input && 0) {
      setIn("in" + to_string(__use_input) + ".txt");
    }
  }
  IO FastIO() {
    cin.tie(nullptr)->sync_with_stdio(0);
    return *this;
  }
  IO* SetIO(string __s = "", string __t = "") {
    cin.exceptions(cin.failbit);
    if ((int)(__t).size() && !0)
      setIn(__s), setOut(__t);
    else if ((int)(__s).size() && !0)
      setIn(__s + ".in"), setOut(__s + ".out");
    return this;
  }
};
}  // namespace CP
const int MX = (2e5 + 43);
int N;
int a[MX];
void test_case() {
  cin >> N;
  for (int i = (0); i < (N); ++i) cin >> a[i];
  int height = 1;
  for (int i = (0); i < (N); ++i) {
    if (i > 0 && !a[i] && !a[i - 1]) return void(put(-1));
    if (a[i]) {
      if (i > 0 && a[i - 1])
        height += 5;
      else
        height += 1;
    }
  }
  return void(put(height));
}
int main() {
  CP::IO().SetIO()->FastIO().Input(0);
  int Test_Cases = 1;
  cin >> Test_Cases;
  for (int tt = 1; tt <= Test_Cases; ++tt) {
    ;
    ;
    test_case();
  }
  return 0;
}
