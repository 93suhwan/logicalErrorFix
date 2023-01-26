#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &a) {
  cin >> a;
}
template <class H, class... T>
void read(H &a, T &...b) {
  read(a);
  read(b...);
}
template <class T>
void read(vector<T> &A) {
  for (auto &x : A) read(x);
}
template <class T>
void print(T &a) {
  cout << a << " ";
}
template <class H, class... T>
void print(H &a, T &...b) {
  print(a);
  print(b...);
}
template <class T>
void print(vector<T> &A) {
  for (auto x : A) print(x);
}
long long gcd(long long a, long long b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b % a, a);
}
void solve() {
  string t;
  cin >> t;
  string s;
  cin >> s;
  long long n = s.size();
  long long ans = 0;
  map<char, long long> mp;
  for (long long i = 0; i < 26; i++) {
    mp[t[i]] = i;
  }
  for (long long i = 1; i < n; i++) {
    ans += abs(mp[s[i]] - mp[s[i - 1]]);
  }
  cout << ans << endl;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
