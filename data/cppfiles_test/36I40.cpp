#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long max(int a, long long b) { return max((long long)a, b); }
long long min(int a, long long b) { return min((long long)a, b); }
long long min(long long a, int b) { return min(a, (long long)b); }
long long max(long long a, int b) { return max(a, (long long)b); }
long long power(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans = (ans * a) % mod;
    }
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
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
    string s;
    if (n % 2 == 0) {
      long long k = n / 2;
      for (long long i = 0; i < k; i++) s += 'a';
      s += 'b';
      for (long long i = 0; i < k - 1; i++) s += 'a';
      cout << s << '\n';
    } else {
      long long k = (n - 1) / 2;
      for (long long i = 0; i < k; i++) s += 'a';
      s += 'b';
      for (long long i = 0; i < k - 1; i++) s += 'a';
      s += 'c';
      cout << s << '\n';
    }
  }
}
