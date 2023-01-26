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
    long long ans;
    if (x == b) {
      ans = a;
    } else if (x == 0 && b == a) {
      ans = a + 2;
    } else {
      ans = a + 1;
    }
    cout << ans << endl;
  }
  return 0;
}
