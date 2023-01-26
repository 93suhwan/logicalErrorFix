#include <bits/stdc++.h>
using namespace std;
long long LOL = 1e9 + 7;
long long power(long long a, long long b) {
  a %= LOL;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % LOL;
    a = a * a % LOL;
    b >>= 1;
  }
  return res;
}
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    long long n;
    long long k;
    long long sol = 0;
    cin >> n >> k;
    string arr = bitset<32>(k).to_string();
    reverse(arr.begin(), arr.end());
    for (int i = 0; i < 32; i++) {
      if (arr[i] == '1') {
        sol = (sol + power(n, i)) % LOL;
      }
    }
    cout << sol << endl;
  }
  return 0;
}
