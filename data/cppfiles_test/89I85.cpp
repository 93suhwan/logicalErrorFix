#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int testcase;
  cin >> testcase;
  while (testcase--) {
    long long int n;
    cin >> n;
    long long int i;
    long long int arr[n];
    for (i = 0; i < n; i++) {
      cin >> arr[i];
    }
    if (arr[0] % 2 == 0) {
      cout << "NO"
           << "\n";
    } else {
      cout << "YES"
           << "\n";
    }
  }
  return 0;
}
