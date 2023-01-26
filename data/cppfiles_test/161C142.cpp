#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, mod2 = 998244353;
void debug_func(istream_iterator<string> _it) { cerr << "\n"; }
template <typename T, typename... Args>
void debug_func(istream_iterator<string> _it, T x, Args... args) {
  cerr << "[ " << *_it << " : " << x << " ]";
  cerr << " , ";
  debug_func(++_it, args...);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long true_rand(long long n) {
  uniform_int_distribution<long long> uid(0, n - 1);
  return uid(rng);
}
long long power(long long a, long long b) {
  a = a % mod;
  if (a == 0) return 0;
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return ans;
}
template <typename T>
bool sortbysec(const pair<T, T> &a, const pair<T, T> &b) {
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
    vector<int> freq(n + 1);
    for (int i = 1; i < n + 1; i++) {
      for (int j = 0; j < n; j++) {
        if (l[j] <= i && i <= r[j]) freq[i]++;
      }
    }
    for (int i = 0; i < n; i++) {
      int mn = n + 5, val;
      for (int j = l[i]; j < r[i] + 1; j++) {
        if (freq[j] <= mn) {
          mn = freq[j];
          val = j;
        }
      }
      cout << l[i] << " " << r[i] << " " << val << "\n";
    }
  }
  return 0;
}
