#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize "trapv"
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << ",  ";
  err(++it, args...);
}
long long int power(long long int x, long long int b,
                    long long int modh = 1000000007) {
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
  fact.resize(n, 1LL);
  for (long long int i = 2; i < n; i++)
    fact[i] = (fact[i - 1] * i) % 1000000007;
}
long long int ncr(long long int n, long long int r) {
  if (r > n) return 0;
  return (fact[n] *
          power((fact[n - r] * fact[r]) % 1000000007, 1000000007 - 2)) %
         1000000007;
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
  bool operator()(const pair<long long int, long long int> &p1,
                  const pair<long long int, long long int> &p2) {
    if (p1.second != p2.second) {
      return p1.second < p2.second;
    } else {
      return p1.first < p2.first;
    }
  }
};
inline void add(long long int &x, long long int y) {
  x += y;
  if (x >= 1000000007) x -= 1000000007;
  return;
}
inline long long int sub(long long int x, long long int y) {
  x -= y;
  if (x < 0) x += 1000000007;
  return x;
}
string bitform(long long int x) {
  string s = "";
  while (x > 0) {
    s += (char('0' + x % 2));
    x /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}
void solve(long long int t = 0) {
  long long int n;
  cin >> n;
  string ans = "";
  for (long long int i = 0; i < n - 2; i++) {
    string s;
    cin >> s;
    if (ans.size()) {
      if (s[0] == ans.back()) {
        ans += s[1];
      } else {
        ans += s[0];
        ans += s[1];
      }
    } else
      ans += s;
  }
  if (ans.size() != n) ans += 'a';
  cout << ans << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int t;
  t = 1;
  cin >> t;
  for (long long int i = 1; i < t + 1; i++) {
    solve(i);
  }
}
