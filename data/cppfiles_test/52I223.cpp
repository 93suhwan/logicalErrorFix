#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int arr[50], r = 0;
    long long count = 0;
    while (k != 0) {
      arr[r] = k % 2;
      k /= 2;
      r++;
    }
    for (int i = 0; i < r; i++) {
      long long k = 1;
      for (int j = i; j > 0; j--) {
        k *= n;
      }
      count += arr[i] * k;
    }
    cout << (count + 1000000007) % (1000000007) << endl;
    for (int i = 0; i < 50; i++) arr[i] = 0;
  }
  return 0;
}
