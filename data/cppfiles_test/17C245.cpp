#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int max(long long int x, long long int y) {
  return x ^ ((x ^ y) & -(x < y));
}
long long int min(long long int x, long long int y) {
  return y ^ ((x ^ y) & -(x < y));
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int power(long long int a, long long int b) {
  long long int ans = 1;
  while (b) {
    ans = ans % 1000000000 + 7;
    a = a % 1000000000 + 7;
    if (b & 1) ans = ans * a;
    b = b >> 1;
    a = a * a;
  }
  return ans;
}
void fastscan(long long int &number) {
  bool negative = false;
  register long long int c;
  number = 0;
  c = getchar();
  if (c == '-') {
    negative = true;
    c = getchar();
  }
  for (; (c > 47 && c < 58); c = getchar()) number = number * 10 + c - 48;
  if (negative) number *= -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n][5];
    for (long long int i = 0; i < n; i++) {
      for (long long int j = 0; j < 5; j++) cin >> a[i][j];
    }
    long long int best = 0;
    for (long long int i = 1; i < n; i++) {
      long long int co = 0;
      for (long long int j = 0; j < 5; j++) {
        if (a[i][j] < a[best][j]) co++;
      }
      if (co >= 3) best = i;
    }
    long long int f = 0;
    for (long long int i = 0; i < n; i++) {
      long long int cou = 0;
      if (i == best) continue;
      for (long long int j = 0; j < 5; j++) {
        if (a[i][j] < a[best][j]) cou++;
      }
      if (cou >= 3) {
        f = 1;
        break;
      }
    }
    if (f == 1)
      cout << "-1" << endl;
    else
      cout << best + 1 << endl;
  }
}
