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
    vector<bool> taken(n, false);
    for (long long int i = 0; i < n; i++) {
      if (arr2[i] == '1') {
        for (int j = i - 1; j <= i + 1; j++) {
          if (j >= 0 and j < n) {
            if (!taken[j]) {
              if ((arr1[j] == '1' and j != i) or (arr1[j] == '0' and j == i)) {
                result++;
                taken[j] = true;
              }
            }
          }
        }
      }
    }
    cout << result << endl;
  }
}
