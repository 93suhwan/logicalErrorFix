#include <bits/stdc++.h>
using namespace std;
template <typename T>
void error(T it) {}
template <typename Ty, typename T, typename... Args>
void error(Ty it, T a, Args... arg) {
  cout << *it << " = " << a << '\t';
  error((++it), arg...);
}
void _split(string s, vector<string> &_os) {
  string se;
  long long x = 0;
  for (auto i : s) {
    if (i == ',' && x == 0)
      _os.push_back(se), se = "";
    else
      se += i;
    if (i == '(') x++;
    if (i == ')') x--;
  }
  _os.push_back(se);
}
long long mod = 1e+9 + 7;
long long inf = (2e+18);
long double pi = 3.1415926536;
const long long N = 2e+5 + 3;
const long long _N = 2e+6 + 3;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test = 1;
  cin >> test;
  while (test--) {
    long long n, s;
    cin >> n >> s;
    long long m;
    if (n % 2 == 0) {
      m = n / 2 + 1;
    } else {
      m = (n + 1) / 2;
    }
    long long t1 = s % m;
    long long t2 = (s - t1) / m;
    cout << t2 << endl;
  }
  cerr << "\nTime : "
       << 1000 * (long double)clock() / (long double)CLOCKS_PER_SEC << "ms\t";
}
