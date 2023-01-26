#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long int sum;
  cin >> n;
  int num[n];
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    sum = 1;
    for (int j = 3; j <= num[i] * 2; j++) {
      sum *= j;
      if (sum >= 1000000007) {
        sum %= 1000000007;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
