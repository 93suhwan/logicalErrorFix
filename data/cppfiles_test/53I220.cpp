#include <bits/stdc++.h>
using namespace std;
long long int Mod = 1e9 + 1;
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long int check = 0;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] <= a[i + 1]) {
        continue;
      } else {
        check++;
      }
    }
    if (check + 1 == k) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
}
