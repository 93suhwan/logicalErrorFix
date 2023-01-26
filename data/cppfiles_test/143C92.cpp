#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
void problem_solver(long long test) {
  map<long long, long long> mp;
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    mp[arr[i]]++;
  }
  long long cnt = 0;
  long long ans = 0;
  multiset<long long> mt;
  for (long long i = 0; i <= n; i++) {
    if (cnt < i) {
      cout << -1 << " ";
      continue;
    }
    if (i > 0 && mp[i - 1] == 0) {
      auto prev = mt.end();
      prev--;
      ans += (i - *prev - 1);
      mt.erase(prev);
    }
    cout << ans + mp[i] << " ";
    cnt += mp[i];
    for (long long j = 0; j < mp[i] - 1; j++) {
      mt.insert(i);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  long long cnt = 1;
  while (t--) {
    problem_solver(cnt);
    cnt += 1;
    cout << '\n';
  }
}
