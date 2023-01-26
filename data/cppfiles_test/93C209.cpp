#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long count = 0, now = 1, com = 1;
    while (now < k) {
      com *= 2;
      count++;
      now *= 2;
      if (com >= n) break;
    }
    if (com < n) {
      count += (n - com) / k;
      if ((n - com) % k != 0) {
        count++;
      }
    }
    cout << count << endl;
  }
}
