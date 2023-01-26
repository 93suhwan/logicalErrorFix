#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k, count = 0, i = 0;
    cin >> n >> k;
    n -= 1;
    while (n > 0 && pow(2, i) <= k) {
      n -= pow(2, i);
      count++;
      i++;
    }
    if (n > 0) {
      if (n % k == 0)
        count += n / k;
      else
        count += n / k + 1;
    }
    cout << count << endl;
  }
}
