#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926536;
const int mod = 1e9 + 7;
const int inf = INT_MAX;
const long long modt = 998244353;
long long Pow(long long a, long long b) {
  if (b == 0) return (long long)1;
  long long res = 1;
  while (b) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
bool isPrime(int s) {
  for (int i = 2; i * i <= s; i++) {
    if (s % i == 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    int s = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      s += arr[i];
    }
    if (isPrime(s)) {
      for (int i = 0; i < n; i++) {
        if (!isPrime(s - arr[i])) {
          cout << n - 1 << '\n';
          for (int j = 1; j <= n; j++) {
            if (j - 1 == i) continue;
            cout << j << " ";
          }
          break;
        }
      }
    } else {
      cout << n << '\n';
      for (int i = 1; i <= n; i++) cout << i << " ";
    }
    cout << '\n';
  }
}
