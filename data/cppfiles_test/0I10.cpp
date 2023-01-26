#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const long long MAXN = 1600010;
void fast_stream() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
ll power(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b % 2) {
      res = (res * a) % 1000000007;
      --b;
    } else {
      a = (a * a) % 1000000007;
      b = b >> 1;
    }
  }
  return res % 1000000007;
}
ll max(ll a, ll b) { return a > b ? a : b; }
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
bool myCmp(pair<int, string>& a, pair<int, string>& b) {
  return a.second < b.second;
}
bool isPrime(int x) {
  if (x <= 1) {
    return false;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<string, int>> vec;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    vec.push_back({s, i});
  }
  for (int i = 0; i < n; i++) {
    string s = vec[i].first;
    for (int j = 0; j < m; j++) {
      if (j % 2) {
        int c = s[j] - 'A';
        c = 25 - c;
        s[j] = 'A' + c;
      }
    }
    vec[i].first = s;
  }
  sort(vec.begin(), vec.end());
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    ans.push_back(vec[i].second);
  }
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << '\n';
  return;
}
int main() {
  fast_stream();
  ll t;
  cin >> t;
  t = 1;
  while (t--) {
    solve();
  }
}
