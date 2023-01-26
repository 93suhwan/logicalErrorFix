#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b);
unsigned long long int gcd(unsigned long long int a, unsigned long long int b);
int prime(long long int n);
long long int power(long long int x, long long int y);
long long int nCr(long long int n, long long int r, long long int p);
long long int sum(long long int n) { return (n * (n + 1)) / 2; }
long long int cei(long long int a, long long int b) {
  return a / b + ((a % b) ? 1 : 0);
}
bool valid(int x, int y, int n, int m) {
  return (x > -1 && x < n && y > -1 && y < m);
}
void solve() {
  long long int n;
  cin >> n;
  priority_queue<long long int, vector<long long int>, greater<long long int>>
      r, b;
  vector<long long int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  string a;
  cin >> a;
  for (int i = 0; i < n; i++) {
    if (a[i] == 'R')
      r.push(v[i]);
    else
      b.push(v[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (!b.empty() && b.top() >= i) {
      b.pop();
    } else if (!r.empty() && r.top() <= i) {
      r.pop();
    } else {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1, p = 0;
  cin >> t;
  while (t-- && ++p) {
    solve();
  }
}
long long int nCr(long long int n, long long int r, long long int p) {
  if (r > n - r) r = n - r;
  long long int C[r + 1];
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j - 1]) % p;
  }
  return C[r];
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
  if (a == 1 || b == 1) return 1;
  if (b == 0) return a;
  return gcd(b, a % b);
}
int prime(long long int n) {
  int flag = 1;
  for (long long int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      flag = 0;
      break;
    }
  }
  return flag;
}
long long int power(long long int x, long long int y) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2) % 1000000007;
  if (y % 2 == 0)
    return (temp * temp) % 1000000007;
  else
    return (((x * temp) % 1000000007) * temp) % 1000000007;
}
