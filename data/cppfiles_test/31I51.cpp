#include <bits/stdc++.h>
using namespace std;
int f(int a, long long int* d) {
  if (a == d[a]) return a;
  return d[a] = f(d[a], d);
}
void u(int a, int b, long long int* d, long long int* s) {
  a = f(a, d);
  b = f(b, d);
  if (a != b) {
    d[b] = a;
    s[a] += s[b];
  }
}
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long int binpow(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
int main() {
  int w;
  long long int a, b, n, c;
  long long int t;
  cin >> w;
  while (w--) {
    cin >> n;
    int d[n + 1];
    for (int i = 0; i < n; i++) cin >> d[i];
    int p[n + 1];
    if (n % 2 == 0) {
      for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
          p[i] = -d[i + 1];
        else
          p[i] = d[i - 1];
      }
    } else {
      for (int i = 0; i < n - 1; i++) {
        if (i % 2 == 0)
          p[i] = -d[i + 1];
        else
          p[i] = d[i - 1];
      }
      if (d[n - 1] > 0 && p[n - 2] > 0) {
        p[n - 2] -= d[n - 1];
        p[n - 1] = d[n - 2];
      }
      pair<int, int> k = {100000, -1};
      for (int i = 0; i < n - 1; i++) {
        if (abs(p[i] + d[n - 1]) != 0 && i % 2 == 0) {
          p[i] += d[n - 1];
          p[n - 1] = -d[i];
          break;
        }
      }
    }
    for (int i = 0; i < n; i++) cout << p[i] << " ";
    cout << "\n";
  }
}
