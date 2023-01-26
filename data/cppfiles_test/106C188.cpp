#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 9;
int binexp(long long a, int b) {
  int s = 1;
  while (b) {
    if (b & 1) s = (s * a) % 1000000007;
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return s;
}
void quiet() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << (i + 1) << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    quiet();
  }
}
