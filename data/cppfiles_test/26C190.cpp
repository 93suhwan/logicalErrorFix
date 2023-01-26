#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  long long a[100000];
  long long p = 1;
  long long l = 1000000000 + 7;
  for (int i = 0; i < 100000; i++) {
    p = p * (2 * i + 1) % l;
    if (i > 0) p = p * (2 * i + 2) % l;
    a[i] = p;
  }
  for (; t > 0; t--) {
    long n;
    cin >> n;
    cout << a[n - 1] << "\n";
  }
  return 0;
}
