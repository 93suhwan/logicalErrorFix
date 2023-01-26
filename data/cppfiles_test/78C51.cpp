#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  return (a == 0) ? b : gcd(b % a, a);
}
void testCase() {
  int n;
  cin >> n;
  vector<int> a(n);
  int bits[32];
  for (int i = 0; i < 32; i++) bits[i] = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = x;
    if (x == 0) {
      bits[31]++;
      continue;
    }
    for (int k = 0; k < 31; k++) {
      if ((1 << k) & x) {
        bits[k]++;
      }
    }
  }
  set<int> numbers;
  for (int i = 0; i < 31; i++) {
    if (bits[i]) numbers.insert(bits[i]);
  }
  int GCD = 0;
  for (auto i : numbers) {
    GCD = gcd(GCD, i);
  }
  for (int i = 1; i <= n; i++) {
    if (GCD % i == 0) {
      cout << i << " ";
    }
  }
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    testCase();
  }
  return 0;
}
