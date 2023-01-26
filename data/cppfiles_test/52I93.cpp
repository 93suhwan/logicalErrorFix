#include <bits/stdc++.h>
using namespace std;
void decToBinary(int k, int n) {
  int binary[32];
  long long l = pow(10, 9);
  long long sum = 0;
  int i = 0;
  while (n > 0) {
    binary[i] = n % 2;
    n = n / 2;
    i++;
  }
  for (int j = 0; j <= i; j++) {
    if (binary[j] == 1) {
      sum += pow(k, j);
    }
  }
  cout << sum % (l + 7) << endl;
}
int main() {
  int t, n, k;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> n;
    cin >> k;
    decToBinary(n, k);
  }
  return 0;
}
