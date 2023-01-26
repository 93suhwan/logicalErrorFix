#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
const ll inf = 2e18;
const ll mod = 1e9 + 7;
const ll N = 2e5 + 5;
void code() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int idx = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      idx = i;
      break;
    }
  }
  if (idx == -1) {
    cout << "1 " << n / 2 << " " << n / 2 + 1 << " " << n - (n & 1) << "\n";
    return;
  } else if (idx < n / 2) {
    cout << idx + 1 << " " << n << " " << idx + 2 << " " << n << "\n";
    return;
  } else {
    cout << 1 << " " << idx + 1 << " " << 1 << " " << idx << "\n";
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t-- > 0) {
    code();
  }
}
