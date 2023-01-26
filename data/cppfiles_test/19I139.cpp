#include <bits/stdc++.h>
const int32_t mod = 1e9 + 7;
using namespace std;
unordered_map<long long, long long> mp;
void fun(vector<long long>& v, long long idx, long long sum, bool si) {
  if (idx == (long long)v.size()) {
    mp[sum]++;
    return;
  }
  fun(v, idx + 1, sum, si);
  if (si) {
    fun(v, idx + 1, sum - v[idx], !si);
  } else
    fun(v, idx + 1, sum + v[idx], !si);
}
void solve(long long test) {
  long long n;
  cin >> n;
  mp.clear();
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  fun(v, 0, 0, 0);
  for (auto it : mp) {
    if (it.second > 1) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  fun(v, 0, 0, 1);
  mp.clear();
  for (auto it : mp) {
    if (it.second > 1) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  cout << "NO"
       << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  long long i = 1;
  while (i <= t) {
    solve(i);
    i++;
  }
  return 0;
}
