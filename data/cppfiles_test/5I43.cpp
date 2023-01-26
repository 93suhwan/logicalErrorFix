#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    char arr1[n], arr2[n];
    long long int result = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> arr1[i];
    }
    for (long long int i = 0; i < n; i++) {
      cin >> arr2[i];
    }
    for (long long int i = 0; i < n; i++) {
      if (arr2[i] == '1') {
        if (arr1[i] == '0' or (i - 1 >= 0 and arr1[i - 1] == '1') or
            (i + 1 < n and arr1[i + 1] == '1'))
          result++;
      }
    }
    cout << result << endl;
  }
}
