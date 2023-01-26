#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << ",  ";
  err(++it, args...);
}
long long int power(long long int x, long long int b,
                    long long int modh = 998244353) {
  long long int p = 1;
  while (b > 0) {
    if (b & 1) {
      p = p * x;
      p %= modh;
    }
    b >>= 1;
    x *= x;
    x %= modh;
  }
  return p % modh;
}
std::vector<long long int> fact;
void fact_pre(long long int n = 2000005) {
  fact.resize(n, 1);
  for (long long int i = 2; i < n; i++) fact[i] = (fact[i - 1] * i) % 998244353;
}
long long int ncr(long long int n, long long int r) {
  if (r > n) return 0;
  return (fact[n] * power((fact[n - r] * fact[r]) % 998244353, 998244353 - 2)) %
         998244353;
}
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
long long int rng(long long int lim, long long int s = 0) {
  uniform_int_distribution<long long int> uid(s, lim - 1);
  return uid(rang);
}
struct ppp {
  long long int first, second, tt, fo;
};
long long int bsleft(vector<long long int> &arr, long long int c) {
  long long int l = -1, r = arr.size();
  while (r - l > 1) {
    long long int mid = (r + l) / 2;
    if (arr[mid] <= c) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}
struct lex_compare {
  bool operator()(
      const pair<long long int, pair<long long int, long long int>> &p1,
      const pair<long long int, pair<long long int, long long int>> &p2) {
    if (p1.first != p2.first) {
      return p1.first > p2.first;
    } else {
      return p1 > p2;
    }
  }
};
void solve() {
  long long int k = 2;
  string s;
  cin >> s;
  long long int n = s.size();
  vector<long long int> arr(n);
  for (long long int i = 0; i < n; i++) arr[i] = s[i] - 'a' + 1;
  vector<vector<long long int>> arr2(26 + 1);
  for (long long int i = 0; i < n; i++) {
    arr2[arr[i]].push_back(i);
  }
  vector<long long int> temp;
  long long int currcolor = 0;
  long long int ans = 0;
  for (long long int i = 1; i < 27; i++) {
    long long int here = 0;
    for (auto j : arr2[i]) {
      temp.push_back(j);
      here++;
      currcolor = (currcolor + 1) % k;
      if (temp.size() == k) {
        ans += k;
        temp.clear();
      }
      if (here == k) {
        break;
      }
    }
  }
  cout << ans / 2 << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i < t + 1; i++) {
    solve();
  }
}
