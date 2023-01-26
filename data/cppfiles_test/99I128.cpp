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
    long long int n, k;
    cin >> n >> k;
    if (k == 0) {
      cout << n << "\n";
      continue;
    }
    long long int steps;
    if (n % 2 == 0) {
      steps = -1;
      long long int mod = (k - 1) % 4;
      for (long long int i = 0; i < mod; i++) {
        steps += (k - i);
      }
      steps -= (k - mod - 1);
    } else {
      steps = 1;
      long long int mod = (k - 1) % 4;
      for (long long int i = 0; i < mod; i++) {
        steps -= (k - i);
      }
      steps += (k - mod - 1);
    }
    cout << steps + n << "\n";
  }
}
