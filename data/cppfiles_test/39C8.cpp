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
int query(vector<int> &a) {
  int n = a.size();
  cout << "? ";
  for (int i = 1; i < n; i++) cout << a[i] << " ";
  cout << endl;
  int k;
  cin >> k;
  return k;
}
void answer(vector<int> &a) {
  int n = a.size();
  cout << "! ";
  for (int i = 1; i < n; i++) cout << a[i] << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> x(n + 1, 1);
  vector<int> res(n + 1);
  int mn = n + 1;
  for (int i = n; i >= 1; i--) {
    if (!res[i]) {
      int k = 2;
      vector<int> delta(n + 1);
      while (k <= n) {
        x[i] = k;
        int pos = query(x);
        if (pos == 0 || pos == i) {
          res[i] = mn - k + 1;
          mn = min(mn, res[i]);
          break;
        }
        if (res[pos]) {
          res[i] = res[pos] - k + 1;
          break;
        }
        delta[pos] = k - 1;
        k++;
      }
      if (k == n + 1) res[i] = 1;
      for (int j = 1; j < n + 1; j++) {
        if (delta[j]) res[j] = delta[j] + res[i];
      }
      x[i] = 1;
    }
  }
  answer(res);
  return 0;
}
