#include <bits/stdc++.h>
using namespace std;
bool isPrime[21000];
int main(void) {
  for (int i = 2; i < 21000; i++) {
    if (!isPrime[i]) {
      for (int j = i + i; j < 21000; j += i) {
        isPrime[j] = true;
      }
    }
  }
  int test_case;
  cin >> test_case;
  for (int t = 0; t < test_case; t++) {
    int n, sum = 0;
    int arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
    }
    if (!isPrime[sum]) {
      bool check = false;
      for (int i = 0; i < n; i++) {
        if (isPrime[sum - arr[i]]) {
          cout << n - 1 << endl;
          check = true;
          for (int j = 0; j < n; j++) {
            if (j == i) continue;
            cout << j + 1 << " ";
          }
          break;
        }
      }
      if (!check) {
        for (int i = 0; i < n; i++) {
          for (int j = i + 1; j < n; j++) {
            if (isPrime[sum - arr[i] - arr[j]]) {
              cout << n - 2 << endl;
              for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                cout << k + 1 << " ";
              }
              break;
            }
          }
        }
      }
    } else {
      cout << n << endl;
      for (int i = 0; i < n; i++) {
        cout << i + 1 << " ";
      }
    }
    cout << endl;
  }
}
