#include <bits/stdc++.h>
using namespace std;
long long int prime = 998244353;
long long int mod = 1000000007;
const long long int inf = 1e18 + 7;
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
void solve() {
  unordered_map<char, int> look_up;
  unordered_map<long long int, vector<int>> lp;
  long long int n, m, k = 0, p = 0, q = 0, sum = 0, ans = 0, tmp = 0, count = 0;
  cin >> n;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  sort(v.begin(), v.end());
  tmp = n / 2;
  int i = 1;
  while (tmp--) cout << v[i] << " " << v[0] << "\n", i++;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1, count = 1;
  cin >> t;
  while (t--) solve(), count++;
  return 0;
}
