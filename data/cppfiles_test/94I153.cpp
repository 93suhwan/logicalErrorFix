#include <bits/stdc++.h>
using namespace std;
void __print(long long x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char *x) { cout << '\"' << x << '\"'; }
void __print(const string &x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cout << '{';
  __print(x.first);
  cout << ',';
  __print(x.second);
  cout << '}';
}
template <typename T>
void __print(const T &x) {
  long long f = 0;
  cout << '{';
  for (auto &i : x) cout << (f++ ? "," : ""), __print(i);
  cout << "}";
}
void _print() { cout << "\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cout << ", ";
  _print(v...);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      v[i] = pow(10LL, x);
    }
    sort(v.begin(), v.end());
    vector<long long> diff;
    for (long long i = 1; i < n; i++) {
      diff.push_back(v[i] / v[i - 1] - 1);
    }
    long long sum = 0, idx = -1, sum1 = 0;
    for (long long i = 0; i < (long long)diff.size(); i++) {
      sum += diff[i];
      if (sum >= k) {
        sum1 = sum - diff[i];
        idx = i;
        break;
      }
    }
    if (idx == -1) {
      long long rem = k - sum + 1;
      long long ans = rem * (*prev(v.end()));
      if (ans / v[idx] > k) {
        cout << ans << "\n";
      } else {
        cout << ans + k - rem + 1 << "\n";
      }
    } else {
      long long rem = (k + 1 - sum1) * v[idx];
      if (rem / v[idx] > k) {
        cout << rem << "\n";
      } else {
        cout << rem + k - rem - 1 << "\n";
      }
    }
  }
}
