#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    bitset<32> b1(n);
    bitset<32> b2(m + 1);
    vector<int> a(32), b(32);
    for (int i = 0; i < 32; i++) a[i] = b1[31 - i];
    for (int i = 0; i < 32; i++) b[i] = b2[31 - i];
    long long ans = 0;
    for (int i = 0; i < 32; i++) {
      if (a[i] == 1 && b[i] == 0)
        break;
      else
        ans += (a[i] ^ b[i]) * pow(2, 31 - i);
    }
    cout << ans << "\n";
  }
  return 0;
}
