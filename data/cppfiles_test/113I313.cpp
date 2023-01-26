#include <bits/stdc++.h>
using namespace std;
long long mpow(long long a, long long b) {
  a %= 1000000007;
  if (!b) return 1;
  long long temp = mpow(a, b / 2);
  temp = (temp * temp) % 1000000007;
  if (b % 2) return (a * temp) % 1000000007;
  return temp;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long cl(long long a, long long b) {
  if (a % b) return 1 + a / b;
  return a / b;
}
string itoj(string s, int i, int j) {
  string tmp = "";
  for (int x = i; x <= j; x++) {
    tmp += s[x];
  }
  return tmp;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  pair<long long, long long> b[n];
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 0; i < n; i++) {
    b[i] = make_pair(sum - a[i], a[i]);
  }
  sort(b, b + n);
  long long m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    int idx = lower_bound(b, b + n, make_pair(x, y)) - b;
    if (idx == n - 1) {
      long long ans = 0;
      if (y > b[idx].first) {
        ans += y - b[idx].first;
      }
      if (x > b[idx].second) {
        ans += x - b[idx].second;
      }
      cout << ans << "\n";
    } else if (idx == 0) {
      long long ans = 0;
      if (y > b[idx].first) {
        ans += y - b[idx].first;
      }
      if (x > b[idx].second) {
        ans += x - b[idx].second;
      }
      idx++;
      long long ans2 = 0;
      if (y > b[idx].first) {
        ans2 += y - b[idx].first;
      }
      if (x > b[idx].second) {
        ans2 += x - b[idx].second;
      }
      cout << min(ans, ans2) << "\n";
    } else {
      long long ans = 0;
      if (y > b[idx].first) {
        ans += y - b[idx].first;
      }
      if (x > b[idx].second) {
        ans += x - b[idx].second;
      }
      int id = idx - 1;
      long long ans1 = 0;
      if (y > b[id].first) {
        ans1 += y - b[id].first;
      }
      if (x > b[idx].second) {
        ans1 += x - b[id].second;
      }
      ans = min(ans, ans1);
      idx++;
      long long ans2 = 0;
      if (y > b[idx].first) {
        ans2 += y - b[idx].first;
      }
      if (x > b[idx].second) {
        ans2 += x - b[idx].second;
      }
      cout << min(ans, ans2) << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int T = 1; T <= t; T++) {
    solve();
  }
  return 0;
}
