#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const int N = 1e6 + 7;
long long fact[N];
long long infact[N];
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 0)
    return (power((a * a) % M, b / 2)) % M;
  else
    return (a * power((a * a) % M, b / 2)) % M;
}
void factorial() {
  fact[0] = 1;
  fact[1] = 1;
  for (int i = 2; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % M;
  }
  infact[N - 1] = power(fact[N - 1], M - 2) % M;
  for (int i = N - 1; i > 0; i--) {
    infact[i - 1] = (i * infact[i]) % M;
  }
}
long long ncr(long long n, long long r) {
  long long ans = 1;
  ans = (ans * fact[n]) % M;
  ans = (ans * infact[n - r]) % M;
  ans = (ans * infact[r]) % M;
  return ans;
}
bool isPali(string s) {
  long long l = 0, r = s.length() - 1;
  while (l < r) {
    if (s[l++] != s[r--]) return false;
  }
  return true;
}
bool solve(string s, string t) {
  long long i = 0, j = 0;
  if (s[i] != t[j]) i++;
  while (i <= s.length() && j <= t.length()) {
    if (s[i] != t[j])
      i += 3;
    else {
      i++;
      j++;
    }
  }
  if (i == s.length() && j == t.length())
    return true;
  else
    return false;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    long long n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    long long ans = 0;
    for (long long i = 0; i < (int)n; i++) {
      if (b[i] == '1') {
        if (a[i] == '0')
          ans++;
        else if (i == 0 && a[i + 1] == '1') {
          ans++;
          a[i + 1] = '2';
        } else if (i != 0 && i != n - 1) {
          if (a[i - 1] == '1') {
            ans++;
            a[i - 1] = '2';
          } else if (a[i + 1] == '1') {
            ans++;
            a[i + 1] = '2';
          }
        } else if (i == n - 1 && a[i - 1] == '1') {
          ans++;
          a[i - 1] = '2';
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
