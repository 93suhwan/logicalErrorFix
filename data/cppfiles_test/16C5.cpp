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
    vector<int> a(n);
    multiset<pair<int, int> > ms;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i]) ms.insert({a[i], i + 1});
    }
    vector<pair<int, int> > talks;
    while (ms.size() > 1) {
      pair<int, int> first = *ms.begin();
      ms.erase(ms.begin());
      auto it = ms.end();
      it--;
      pair<int, int> last = *it;
      ms.erase(it);
      talks.push_back({first.second, last.second});
      if (first.first > 1) ms.insert({first.first - 1, first.second});
      if (last.first > 1) ms.insert({last.first - 1, last.second});
    }
    cout << (int)talks.size() << "\n";
    for (auto e : talks) cout << e.first << " " << e.second << "\n";
  }
  return 0;
}
