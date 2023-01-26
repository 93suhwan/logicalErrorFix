#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long findGCD(long long arr[], long long n) {
  long long result = arr[0];
  for (long long i = 1; i < n; i++) {
    result = gcd(arr[i], result);
    if (result == 1) {
      return 1;
    }
  }
  return result;
}
long long findXOR(long long n) {
  long long mod = n % 4;
  if (mod == 0)
    return n;
  else if (mod == 1)
    return 1;
  else if (mod == 2)
    return n + 1;
  else if (mod == 3)
    return 0;
  return -1;
}
bool compare(pair<long long, long long> p1, pair<long long, long long> p2) {
  return p1.second < p2.second;
}
void solve() {
  long long n, a;
  cin >> n;
  vector<pair<long long, long long>> ans;
  priority_queue<pair<long long, long long>> pq;
  for (long long i = 0; i < n; i++) {
    cin >> a;
    if (a > 0) {
      pq.push(make_pair(a, i + 1));
    }
  }
  while (pq.size() >= 2) {
    auto t1 = pq.top();
    pq.pop();
    auto t2 = pq.top();
    pq.pop();
    t1.first--, t2.first--;
    ans.push_back({t1.second, t2.second});
    if (t1.first > 0) pq.push(t1);
    if (t2.first > 0) pq.push(t2);
  }
  cout << ans.size() << endl;
  for (auto x : ans) {
    cout << x.first << " " << x.second << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
