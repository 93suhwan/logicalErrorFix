#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
unsigned long long min(unsigned long long x, unsigned long long y) {
  if (x < y) return x;
  return y;
}
unsigned long long max(unsigned long long x, unsigned long long y) {
  if (x < y) return y;
  return x;
}
long long min(long long x, long long y) {
  if (x < y) return x;
  return y;
}
long long max(long long x, long long y) {
  if (x < y) return y;
  return x;
}
double min(double x, double y) {
  if (x < y) return x;
  return y;
}
double max(double x, double y) {
  if (x < y) return y;
  return x;
}
unsigned long long gcd(unsigned long long x, unsigned long long y) {
  if (!x) return y;
  if (!y) return x;
  if (x > y) swap(x, y);
  return gcd(x, y % x);
}
unsigned long long inv(unsigned long long a, unsigned long long c) {
  if (a == 1) {
    return 1;
  }
  return ((c - (c / a)) * inv(c % a, c)) % c;
}
void printv(vector<int> &a) {
  int n = a.size();
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << " END\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    bool sorted = true;
    for (int i = 1; i < n; ++i) {
      if (a[i] > a[i + 1]) sorted = false;
    }
    int ans = 0;
    while (!sorted) {
      ans++;
      if (ans & 1) {
        for (int i = 1; i <= n - 2; i += 2) {
          if (a[i] > a[i + 1]) {
            swap(a[i], a[i + 1]);
          }
        }
      } else {
        for (int i = 2; i <= n - 1; i += 2) {
          if (a[i] > a[i + 1]) {
            swap(a[i], a[i + 1]);
          }
        }
      }
      sorted = true;
      for (int i = 1; i < n; ++i) {
        if (a[i] > a[i + 1]) sorted = false;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
