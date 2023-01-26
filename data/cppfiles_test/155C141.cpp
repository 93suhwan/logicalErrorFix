#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long power(long long a, long long b) {
  long long res = 1;
  a = a % MOD;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % MOD;
      b--;
    }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
long long smallb(long long a, string s) {
  long long mod = 0;
  long long l = s.length();
  for (int i = 0; i < l; i++) {
    mod = (mod * 10 + (s[i] - '0')) % a;
  }
  return mod;
}
long long gcd(long long a, long long b) {
  if (!a) return b;
  return gcd(b % a, a);
}
long long gcdlarge(long long a, string s) {
  long long num = smallb(a, s);
  return gcd(a, num);
}
bool compare(pair<char, long long> p1, pair<char, long long> p2) {
  if (p1.second > p2.second) {
    return true;
  }
  return false;
}
vector<bool> prim(20000 + 1, true);
void SieveOfEratosthenes(int n) {
  for (int p = 2; p * p <= n; p++) {
    if (prim[p] == true) {
      for (int i = p * p; i <= n; i += p) prim[i] = false;
    }
  }
}
long long countDivisors(long long n) {
  long long cnt = 0;
  long long til = sqrt(n);
  for (int i = 1; i <= til; i++) {
    if (n % i == 0) {
      if (n / i == i)
        cnt++;
      else
        cnt = cnt + 2;
    }
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    string s;
    cin >> s;
    long long z = 0;
    long long o = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        z++;
      } else {
        o++;
      }
    }
    long long op = z + 1;
    vector<long long> ans(n);
    vector<bool> b(n + 1, false);
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        if (a[i] > z) {
          while (b[z] != false && z > 1) {
            z--;
          }
          ans[i] = z;
          b[z] = true;
        } else if (a[i] <= z) {
          long long p = a[i];
          while (b[p] != false && p > 1) {
            p--;
          }
          ans[i] = p;
          b[p] = true;
        }
      } else {
        if (a[i] <= op) {
          while (b[op] != false) {
            op++;
          }
          ans[i] = op;
          b[op] = true;
        } else {
          long long top = a[i];
          while (b[top] != false) {
            top++;
            if (top == n + 1) {
              top = op;
            }
          }
          ans[i] = top;
          b[top] = true;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
