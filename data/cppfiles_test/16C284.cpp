#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
struct el {
  long long a;
  long long b;
  long long c;
};
long long qpow(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2) {
      res = (res * a) % MOD;
      n--;
    } else {
      n = n / 2;
      a = (a * a) % MOD;
    }
  }
  return res;
}
bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
  if (p1.second != p2.second) return p1.second < p2.second;
  return p1.first > p2.first;
}
bool prime(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long inv(long long n) { return qpow(n, MOD - 2); }
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  multiset<pair<int, int>, greater<pair<int, int>>> ms;
  for (int i = 0; i < n; i++) ms.insert({arr[i], i});
  vector<pair<int, int>> ans;
  while (true) {
    if (ms.size() <= 1) break;
    pair<int, int> p1 = *ms.begin();
    ms.erase(ms.begin());
    pair<int, int> p2 = *ms.begin();
    ms.erase(ms.begin());
    if (p1.first <= 0 || p2.first <= 0) break;
    ans.push_back({p1.second, p2.second});
    p1.first--, p2.first--;
    if (p1.first > 0) ms.insert(p1);
    if (p2.first > 0) ms.insert(p2);
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) solve();
  cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << '\n';
  return 0;
}
