#include <bits/stdc++.h>
using namespace std;
long long factorial(long long n) {
  long long k = n;
  long long fact = 1;
  if (n == 0) {
    return 1;
  }
  while (k >= 1) {
    fact *= k;
    k--;
  }
  return fact;
}
bool isPrime(long long n) {
  if (n == 1) return true;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
struct comp {
  bool operator()(pair<long long, long long>& a,
                  pair<long long, long long>& b) {
    return a.second < b.second;
  }
};
void solve() {
  long long n;
  cin >> n;
  vector<long long> ar(n);
  priority_queue<pair<long long, long long>,
                 vector<pair<long long, long long> >, comp>
      pq;
  for (long long i = 0; i < n; i++) cin >> ar[i], pq.push({i + 1, ar[i]});
  long long k = 0;
  vector<vector<long long> > res;
  while ((long long)pq.size() > 1) {
    auto it1 = pq.top();
    pq.pop();
    auto it2 = pq.top();
    pq.pop();
    res.push_back({it1.first, it2.first, it2.second});
    k += res.back()[2];
    pq.push({it1.first, it1.second - it2.second});
  }
  cout << k << "\n";
  for (long long i = 0; i < (long long)res.size(); i++) {
    long long tmp = res[i][2];
    while (tmp--) {
      cout << res[i][0] << " " << res[i][1] << "\n";
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
