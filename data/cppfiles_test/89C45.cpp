#include <bits/stdc++.h>
using namespace std;
const long long M = 2e5 + 2;
const long long MOD = 1e9 + 7;
long long n, a[M];
bool ans;
int main() {
  long long pp;
  cin >> pp;
  while (pp--) {
    ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
      ans = 0;
      for (int j = i + 2; j != 1; j--) {
        if (a[i] % j != 0) {
          ans = 1;
          break;
        }
      }
      if (!ans) {
        cout << "NO"
             << "\n";
        break;
      }
    }
    if (ans)
      cout << "YES"
           << "\n";
  }
  return 0;
}
