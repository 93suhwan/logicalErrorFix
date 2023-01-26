#include <bits/stdc++.h>
using namespace std;
struct node {
  long long a, b;
};
bool greatercomp(long long& n, long long& n1) { return n > n1; }
bool compnode(node& n, node& n1) { return n.a < n1.a; }
bool compnode2(node n, node n1) { return n.a > n1.a; }
bool compnode3(node n, node n1) {
  if (n.a < n1.a) {
    return true;
  }
  if (n.a == n1.a && n.b < n1.b) {
    return true;
  }
  return false;
}
bool comp4(node n, node n1) { return n.b < n1.b; }
long long gcd(long long n, long long n1) {
  while (n != 0 && n1 != 0) {
    if (n > n1)
      n %= n1;
    else
      n1 %= n;
  }
  return n + n1;
}
long long lcm(int n, int n1) {
  long long nod = gcd(n, n1);
  return (n / nod) * (n1 / nod) * nod;
}
vector<int> isprime;
void primenumbers(int n) {
  vector<bool> isp(1000001, 1);
  int i = 2;
  while (i * i <= n) {
    if (isp[i]) {
      int j = i + i;
      while (j <= n) {
        isp[j] = 0;
        j += i;
      }
    }
    i++;
  }
  for (int i = 2; i <= n; i++) {
    if (isp[i]) isprime.push_back(i);
  }
}
long long mod = 1000000007;
long long INF = 999999999999;
long long binpow(int n, int m) {
  if (m == 0) return 1;
  if (m % 2 == 1)
    return (binpow(n, m - 1) * n) % mod;
  else {
    long long b = binpow(n, m / 2);
    return (b * b) % mod;
  }
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      if ((i + 1) <= n / 2)
        cout << i + 1 << " " << n << " " << i + 2 << " " << n << endl;
      else
        cout << 1 << " " << i + 1 << " " << 1 << " " << i << endl;
      return;
    }
  }
  cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
