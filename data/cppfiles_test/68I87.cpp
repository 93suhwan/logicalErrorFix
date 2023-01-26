#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int k;
    scanf("%lld", &k);
    double n = sqrt(k);
    double difference = (k - n * n);
    if (difference == 0) {
      cout << n << " "
           << "1" << endl;
    } else {
      long long int t = n;
      long long int diff = k - (t * t);
      if (diff <= t) {
        cout << diff << " " << t + 1 << endl;
      } else {
        cout << t + 1 << " " << 2 * t + 2 - diff << endl;
      }
    }
  }
  return 0;
}
