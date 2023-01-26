#include <bits/stdc++.h>
using namespace std;
long long useful(vector<long long>& nums) {
  long long n = nums.size();
  vector<long long> dp1(n + 1, 0);
  vector<long long> dp2(n + 1, 0);
  for (long long i = 1; i <= n; i++) {
    dp1[i] = max(dp1[i - 1], dp2[i - 1] + nums[i - 1]);
    dp2[i] = max(dp2[i - 1], dp1[i - 1] - nums[i - 1]);
  }
  return dp1[n];
}
long long power(long long x, long long y, long long m = 1000000007) {
  x = x % m;
  if (y == 0) return 1LL;
  if (y % 2) return (x * power((x * x) % m, y / 2, m)) % m;
  return power((x * x) % m, y / 2, m);
}
vector<long long> sieve(long long n) {
  long long* arr = new long long[n + 1]();
  vector<long long> vect;
  for (long long i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (long long j = i * i; j <= n; j += i) arr[j] = 1;
    }
  delete[] arr;
  return vect;
}
bool comp(long long a, long long b) { return a > b; }
bool comp_pair(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first > b.first;
}
void solve() {
  long long n, d;
  cin >> n >> d;
  long long arr[n];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  long long flag = 0;
  queue<long long> q;
  vector<long long> dist(n, -1);
  for (long long i = 0; i < n; i++) {
    if (arr[i] == 0) {
      q.push(i);
      dist[i] = 0;
    }
  }
  while (!q.empty()) {
    long long temp = q.front();
    q.pop();
    long long ind = (temp + d) % n;
    if (dist[ind] == -1) {
      dist[ind] = dist[temp] + 1;
      q.push(ind);
    }
  }
  long long ans = 0;
  for (auto u : dist) {
    if (u == -1) {
      cout << -1 << endl;
      return;
    }
    ans = max(ans, u);
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
