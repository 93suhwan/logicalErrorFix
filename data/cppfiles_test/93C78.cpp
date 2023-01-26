#include <bits/stdc++.h>
using namespace std;
long long inf = 1e13 + 100, mod = 1e9 + 7;
long long pre[300005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  pre[0] = 0;
  for (long long i = 1; i <= 300000; i++) pre[i] = pre[i - 1] ^ i;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    long long x = pre[a - 1];
    if (x == b)
      cout << a;
    else {
      long long last = b ^ x;
      if (last == a)
        cout << a + 2;
      else
        cout << a + 1;
    }
    cout << "\n";
  }
  return 0;
}
