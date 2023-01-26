#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string a;
    string b;
    cin >> a;
    cin >> b;
    bool k = 0;
    for (long long i = 0; i < n; i++) {
      if (a[i] == '1' && b[i] == '1') {
        k = 1;
        break;
      }
    }
    if (k) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
