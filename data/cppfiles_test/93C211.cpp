#include <bits/stdc++.h>
using namespace std;
int computeXOR(int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    int x = computeXOR(a - 1);
    int j = x ^ b;
    long long ans;
    if (j == a) {
      cout << a + 2 << endl;
      continue;
    }
    if (j == 0) {
      cout << a << endl;
    } else {
      cout << a + 1 << endl;
    }
  }
  return 0;
}
