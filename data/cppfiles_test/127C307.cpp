#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007ll;
const long long int num = (1 << 24);
vector<int> prim;
long long int pow(long long int n, long long int x = 2ll) {
  if (n == 0ll)
    return 1ll;
  else if (n == 1ll)
    return (x % mod);
  else {
    if (n % 2 == 1ll)
      return ((x % mod) * (pow(n / 2, ((x * x) % mod)) % mod)) % mod;
    else
      return (pow(n / 2, ((x * x) % mod)) % mod);
  }
}
void SieveOfEratosthenes() {
  bool prime[num + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= num; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= num; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p <= num; p++)
    if (prime[p]) prim.push_back(p);
}
int gcdExtended(int a, int b, int *x, int *y) {
  if (a == 0) {
    *x = 0;
    *y = 1;
    return b;
  }
  int x1, y1;
  int gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
int gcd(int a, int b) {
  int x, y;
  return gcdExtended(a, b, &x, &y);
}
vector<int> getFact(int x) {
  vector<int> result;
  int i = 1;
  while (i * i <= x) {
    if (x % i == 0) {
      result.push_back(i);
      if (x / i != i) {
        result.push_back(x / i);
      }
    }
    i++;
  }
  return result;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T, n;
  cin >> T;
  string s, t, ans;
  while (T--) {
    cin >> s;
    cin >> t;
    int a[26];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < s.size(); i++) {
      a[s[i] - 'a']++;
    }
    ans = "";
    if (((t[0] == 'a') && (t[1] == 'b') && (t[2] == 'c')) && (a[0] != 0)) {
      for (int i = 0; i < a[0]; i++) {
        ans = ans + 'a';
      }
      for (int i = 0; i < a[2]; i++) {
        ans = ans + 'c';
      }
      for (int i = 0; i < a[1]; i++) {
        ans = ans + 'b';
      }
      for (int i = 3; i < 26; i++) {
        for (int j = 0; j < a[i]; j++) {
          ans = ans + (char)('a' + i);
        }
      }
    } else {
      for (int i = 0; i < 26; i++) {
        for (int j = 0; j < a[i]; j++) {
          ans = ans + (char)('a' + i);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
