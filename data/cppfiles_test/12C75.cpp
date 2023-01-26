#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n % 2 == 0 and m % 2 == 0) {
    if (k % 2 == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    return;
  }
  int mul = n * m;
  int totalM = mul / 2;
  if (n % 2 == 0) {
    int vm = n / 2;
    int canh = (totalM - vm);
    if (canh < k) {
      cout << "NO\n";
    } else if ((canh - k) % 2 == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    return;
  } else if (m % 2 == 0) {
    int hm = m / 2;
    if (hm > k) {
      cout << "NO\n";
      return;
    }
    k -= hm;
    int canh = totalM - hm;
    if ((canh - k) % 2 == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    return;
  }
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
