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
bool cust(const pair<T, T> &a, const pair<T, T> &b) {
  if (a.first == b.first) return (a.second > b.second);
  return (a.first < b.first);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int> > range(n);
    for (int i = 0; i < n; i++) {
      cin >> range[i].first >> range[i].second;
    }
    sort(range.begin(), range.end(), cust<int>);
    vector<pair<int, int> > ans(n + 1);
    for (int i = 1; i < n + 1; i++) {
      ans[i].second = i;
      for (int j = 0; j < n; j++) {
        if (range[j].first <= i && i <= range[j].second) ans[i].first++;
      }
    }
    sort(ans.begin() + 1, ans.end());
    for (int i = 0; i < n; i++) {
      cout << range[i].first << " " << range[i].second << " "
           << ans[i + 1].second << "\n";
    }
    cout << "\n";
  }
  return 0;
}
