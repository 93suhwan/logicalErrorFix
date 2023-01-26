#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int sum = floor(sqrt(n)) + floor(cbrt(n)), count = 0;
    for (int i = 1; i * i * i <= n; i++) {
      if (sqrt(i * i * i) == floor(sqrt(i * i * i))) count++;
    }
    cout << sum - count << endl;
  }
  return 0;
}
