#include <bits/stdc++.h>
using namespace std;
vector<int> f(100005);
vector<int> inv(100005);
long long int Power(long long int a, long long int b) {
  long long int p = 1;
  a = a;
  b = b;
  while (b) {
    if (b & 1) {
      p = ((p) * (a));
    }
    a = ((a) * (a));
    b = (b / 2);
  }
  return p;
}
long long int power(long long int x, long long int y,
                    long long int md = 1000000007) {
  long long int res = 1;
  x %= md;
  while (y) {
    if (y & 1) res = (res * x) % md;
    x *= x;
    if (x >= md) x %= md;
    y >>= 1;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
void init() {
  f[0] = 1;
  for (int i = 1; i < 100005; i++) f[i] = (f[i - 1] * i) % 1000000007;
  inv[100005 - 1] = power(f[100005 - 1], 1000000007 - 2, 1000000007);
  for (int i = 100005 - 2; i >= 0; i--)
    inv[i] = power(f[i], 1000000007 - 2, 1000000007);
}
int ncr(int n, int r) {
  if (r > n || r < 0) return 0;
  int ans = f[n];
  ans *= (inv[r] * inv[n - r]) % 1000000007;
  ans %= 1000000007;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    string s1, s2;
    cin >> s1 >> s2;
    int pos[26];
    int i = 0;
    for (auto it : s1) {
      pos[it - 'a'] = i;
      i++;
    }
    i = 1;
    int ans = 0;
    while (i < s2.size()) {
      ans += abs(pos[s2[i] - 'a'] - pos[s2[i - 1] - 'a']);
      i++;
    }
    cout << ans << endl;
  }
  return 0;
}
