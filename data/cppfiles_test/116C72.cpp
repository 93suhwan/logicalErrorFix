#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
template <typename T, typename... Args>
inline string arrStr(T arr, int n) {
  stringstream s;
  s << "[";
  for (int i = 0; i < n - 1; i++) s << arr[i] << ",";
  s << arr[n - 1] << "]";
  return s.str();
}
inline void __evars_begin(int line) { cerr << "#" << line << ": "; }
template <typename T>
inline void __evars_out_var(vector<T> val) {
  cerr << arrStr(val, val.size());
}
template <typename T>
inline void __evars_out_var(T* val) {
  cerr << arrStr(val, 10);
}
template <typename T>
inline void __evars_out_var(T val) {
  cerr << val;
}
inline void __evars(vector<string>::iterator it) { cerr << endl; }
template <typename T, typename... Args>
inline void __evars(vector<string>::iterator it, T a, Args... args) {
  cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
  __evars_out_var(a);
  cerr << "; ";
  __evars(++it, args...);
}
const long long N = 2e5 + 15;
const long long sz = (1 << 20);
const long long mod = 1e9 + 7;
const long long mod2 = 998244353;
void boomer() {
  long long n;
  cin >> n;
  vector<long long> v(n + 1);
  vector<long long> a;
  for (long long i = 1; i <= n; ++i) {
    cin >> v[i];
    a.push_back(v[i]);
  }
  sort(a.begin(), a.end());
  long long mex = 0;
  for (long long x : a) {
    if (x == mex) mex++;
  }
  vector<long long> dp1(mex + 10), dp2(mex + 10);
  for (long long i = 1; i <= n; ++i) {
    if (v[i]) {
      long long x = v[i] - 1;
      dp2[x] = (dp2[x] + dp2[x] + dp1[x]) % mod2;
    }
    long long x = v[i] + 1;
    dp1[x] = (dp1[x] + dp1[x]) % mod2;
    dp2[x] = (dp2[x] + dp2[x]) % mod2;
    dp1[x] = (dp1[x] + dp1[x - 1]) % mod2;
    if (v[i] == 0) dp1[1]++;
    if (v[i] == 1) dp2[0]++;
  }
  long long ans = 0;
  for (long long i = 0; i <= mex; ++i) ans = (ans + dp1[i] + dp2[i]) % mod2;
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long tc = 1;
  cin >> tc;
  for (long long i = 1; i <= tc; ++i) {
    boomer();
    if (i < tc) cout << "\n";
  }
  return 0;
}
