#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  long long int arr[16] = {0};
  arr[0] = 0;
  arr[1] = 1;
  for (long long int i = 2; i <= 15; i++) arr[i] = arr[i - 1] * i;
  while (t--) {
    long long int n, m, k;
    cin >> n >> m >> k;
    if (m < n - 1 || k <= 1 || (n < 16 && m > arr[n - 1]))
      cout << "NO" << endl;
    else if (k > 3 || (k == 2 && n == 1) ||
             (k == 3 && n <= 16 && m == arr[n - 1]))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
