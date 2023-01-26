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
inline string arrStr(T arr, long long n) {
  stringstream s;
  s << "[";
  for (long long i = 0; i < n - 1; i++) s << arr[i] << ",";
  s << arr[n - 1] << "]";
  return s.str();
}
template <typename t>
void evars(vector<vector<t>> a) {
  for (auto i : a) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << "\n";
  }
}
inline void __evars_begin(long long line) { cout << "#" << line << ": "; }
template <typename T>
inline void __evars_out_var(vector<T> val) {
  cout << arrStr(val, val.size());
}
template <typename T>
inline void __evars_out_var(T* val) {
  cout << arrStr(val, 10);
}
template <typename T>
inline void __evars_out_var(T val) {
  cout << val;
}
inline void __evars(vector<string>::iterator it) { cout << "\n"; }
template <typename T, typename... Args>
inline void __evars(vector<string>::iterator it, T a, Args... args) {
  cout << it->substr((*it)[0] == ' ', it->length()) << "=";
  __evars_out_var(a);
  cout << "; ";
  __evars(++it, args...);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> vals(n + 1);
  for (long long i = 1; i < n + 1; ++i) cin >> vals[i];
  vals[0] = 0;
  long long a = 0, b = 0;
  bool is_ok = true;
  for (long long i = 1; i < n + 1; ++i) {
    if (vals[i] && vals[i - 1]) {
      a++;
    } else if (vals[i] && !vals[i - 1]) {
      b++;
    } else if (!vals[i] && !vals[i - 1] && i != 1) {
      is_ok = false;
      break;
    }
  }
  (!is_ok) ? cout << -1 << "\n" : cout << (5 * a + b + 1) << "\n";
}
int32_t main() {
  clock_t begin = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
