#include <bits/stdc++.h>
using namespace std;
std::vector<std::string> svec;
vector<long long int> v;
void sieve(long long int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long int p = 2; p <= n; p++)
    if (prime[p]) v.push_back(p);
}
long long int gcd(long long int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a == b) return a;
  if (a > b) return gcd(a - b, b);
  return gcd(a, b - a);
}
long long int npr(int n) {
  long long int ans = 1;
  for (int i = n; i > 1; i--) {
    ans *= i;
    if (i == n - 2) {
      ans /= 2;
    }
    ans %= 1000000007;
  }
  return ans;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
void bfs(int n, vector<vector<int>>& edgelist, vector<int>& dist,
         queue<int>& q) {
  for (int i : edgelist[n]) {
    if (dist[i] != -1) continue;
    dist[i] = dist[n] + 1;
    q.push(i);
  }
  if (!q.empty()) {
    n = q.front();
    q.pop();
    bfs(n, edgelist, dist, q);
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    int a[n];
    int de = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool dead = false;
    int con = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] == 0 && a[i - 1] == 0) {
        dead = true;
        break;
      }
      if (a[i] == 1 && a[i - 1] == 1) {
        con++;
      }
    }
    int ans = con * 4;
    ans++;
    for (int i = 0; i < n; i++) {
      if (a[i] == 1) {
        ans += 1;
      }
    }
    if (dead) {
      cout << -1 << "\n";
    } else {
      cout << ans << "\n";
    }
  }
  return 0;
}
