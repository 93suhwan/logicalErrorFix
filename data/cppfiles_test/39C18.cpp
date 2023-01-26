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
  vector<int> arr_next(n + 1), arr_prev(n + 1);
  vector<int> res(n + 1);
  for (int i = 1; i < n + 1; i++) {
    x[i] = 2;
    arr_next[i] = query(x);
    if (!arr_next[i]) res[i] = n;
    x[i] = 1;
  }
  x.assign(n + 1, 2);
  int pos;
  for (int i = 1; i < n + 1; i++) {
    x[i] = 1;
    arr_prev[i] = query(x);
    if (!arr_prev[i]) {
      res[i] = 1;
      pos = i;
    }
    x[i] = 2;
  }
  int k = 1;
  while (k != n) {
    if (arr_next[pos] != pos) {
      res[arr_next[pos]] = ++k;
      pos = arr_next[pos];
      continue;
    }
    for (int i = 1; i < n + 1; i++) {
      if (i == pos) continue;
      if (arr_prev[i] == pos) {
        res[i] = ++k;
        pos = i;
        continue;
      }
    }
  }
  answer(res);
  return 0;
}
