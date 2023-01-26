#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long int k;
    scanf("%lld", &k);
    long long int n = sqrt(k);
    double difference = (k - n * n);
    if (difference == 0) {
      cout << n << " "
           << "1" << endl;
    } else {
      long long int t = int(sqrt(k));
      long long int diff = int(k - (t * t));
      if (diff <= t) {
        cout << diff << " " << t + 1 << endl;
      } else {
        cout << t + 1 << " " << 2 * t + 2 - diff << endl;
      }
    }
  }
  return 0;
}
