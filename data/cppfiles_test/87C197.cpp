#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long j = 1, y = 0, x = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > j) {
        x = a[i] - j;
        y += a[i] - j;
        j = a[i] + 1;
      } else {
        j++;
      }
    }
    cout << y << "\n";
  }
  return 0;
}
