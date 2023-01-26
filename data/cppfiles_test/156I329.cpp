#include <bits/stdc++.h>
using namespace std;
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long calc(int a, int b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
unsigned long long power(unsigned long long x, int y, int p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
unsigned long long modInverse(unsigned long long n, int p) {
  return power(n, p - 2, p);
}
long long fac[100001];
void solve() {
  fac[0] = 1;
  for (int i = 1; i <= 100000; i++) fac[i] = (fac[i - 1] * i) % 1000000007;
}
unsigned long long nCrModPFermat(unsigned long long n, int r, int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
int main() {
  c_p_c();
  int x = 1;
  cin >> x;
  while (x--) {
    long long n, k;
    cin >> n >> k;
    long long arr[n];
    long long s = 0;
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
      s += arr[i];
    }
    sort(arr, arr + n);
    long long x = arr[0];
    if (arr[0] * n <= k) {
      long long i = n - 1;
      long long ans = 0;
      while (s > k && i > 0) {
        s -= arr[i] - arr[0];
        ans++;
        i--;
      }
      long long ans2 = ans;
      i++;
      while (i < n) {
        if (s + arr[i] <= k) {
          ans2--;
          ans = min(ans, ans2);
          s += arr[i] - arr[0];
        } else {
          long long y2 = s - k + arr[i];
          long long y3;
          if (y2 % (n - i) == 0)
            y3 = y2 / (n - i);
          else
            y3 = y2 / (n - i) + 1;
          ans2 += y3 - 1;
          s += arr[i] - arr[0];
          s -= (n - i) * (y3);
          arr[0] -= y3;
          ans = min(ans, ans2);
        }
        i++;
      }
      cout << ans << endl;
    } else {
      long long y = k / n;
      long long ans = arr[0] - y;
      s -= arr[0] - y;
      long long i = n - 1;
      arr[0] = y;
      while (s > k && i > 0) {
        s -= arr[i] - arr[0];
        ans++;
        i--;
      }
      long long ans2 = ans;
      i++;
      while (i < n) {
        if (s + arr[i] <= k) {
          ans2--;
          ans = min(ans, ans2);
          s += arr[i] - arr[0];
        } else {
          long long y2 = s - k + arr[i];
          long long y3;
          if (y2 % (n - i) == 0)
            y3 = y2 / (n - i);
          else
            y3 = y2 / (n - i) + 1;
          ans2 += y3 - 1;
          s += arr[i] - arr[0];
          s -= (n - i) * (y3);
          arr[0] -= y3;
          ans = min(ans, ans2);
        }
        i++;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
