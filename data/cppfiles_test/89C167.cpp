#include <bits/stdc++.h>
using namespace std;
void pre() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    bool ok = true;
    for (long long int i = 0; i < n; i++) {
      bool found = false;
      for (long long int j = i + 2; j >= 2; j--) {
        if (arr[i] % j != 0) {
          found = true;
          break;
        }
      }
      if (!found) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
