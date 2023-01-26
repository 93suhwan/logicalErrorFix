#include <bits/stdc++.h>
using namespace std;
int mod = 998244353;
long long int max(long long int a, long long int b) {
  if (a >= b) return a;
  return b;
}
long long int min(long long int a, long long int b) {
  if (a <= b) return a;
  return b;
}
long long int pow(long long int a, long long int b) {
  long long int ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % mod;
    }
    b = b >> 1;
    a = (a * a) % mod;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long int x, n;
    cin >> x >> n;
    if (n == 0) {
      cout << x << "\n";
      continue;
    }
    long long int steps;
    if (x & 1) {
      steps = 1;
      long long int mod = (n - 1) % 4;
      if (mod == 1) {
        steps -= n;
      }
      if (mod == 2) {
        steps -= n;
        steps -= (n - 1);
      }
      if (mod == 3) {
        steps += n;
        steps -= (n - 1);
        steps -= (n - 2);
      }
      steps += (n - 1 - mod);
    } else {
      steps = -1;
      long long int mod = (n - 1) % 4;
      if (mod == 1) {
        steps += n;
      }
      if (mod == 2) {
        steps += n;
        steps += (n - 1);
      }
      if (mod == 3) {
        steps -= n;
        steps += (n - 1);
        steps += (n - 2);
      }
      steps -= (n - 1 - mod);
    }
    cout << (steps + x) << "\n";
  }
}
