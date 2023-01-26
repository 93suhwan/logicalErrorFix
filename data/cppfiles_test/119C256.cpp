#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long total = 0;
    for (long long int i = 0; i < n; i++) {
      total += a[i];
    }
    if (total % n == 0) {
      cout << "0" << endl;
    } else {
      cout << "1" << endl;
    }
  }
  return 0;
}
