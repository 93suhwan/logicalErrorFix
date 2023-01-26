#include <bits/stdc++.h>
using namespace std;
bool isSquare(int x) {
  int y = sqrt(x);
  return y * y == x;
}
bool isPowerOfTwo(int n) {
  if (n == 0) {
    return false;
  }
  return (ceil(log2(n)) == floor(log2(n)));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  for (long long abc = 0; abc < t; abc++) {
    int n;
    cin >> n;
    int arr[n][5];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> arr[i][j];
      }
    }
    int an = 0;
    vector<int> days(5);
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < n; j++) {
        days[i] = days[i] + arr[j][i];
      }
    }
    int count = 0;
    for (int i = 0; i < 5; i++) {
      if (days[i] >= n / 2) {
        count++;
      }
    }
    if (count < 2) {
      cout << "NO" << endl;
    } else {
      vector<int> tp(n);
      for (int i = 0; i < 4; i++) {
        if (days[i] >= n / 2) {
          for (int j = i + 1; j < 5; j++) {
            if (days[j] >= n / 2) {
              for (int k = 0; k < n; k++) {
                tp[k] = arr[k][i] + arr[k][j];
              }
              int c = 0;
              for (int k = 0; k < n; k++) {
                if (tp[k] < 1) {
                  c++;
                }
                tp[k] = 0;
              }
              if (c == 0) {
                cout << "YES" << endl;
                an = 1;
                break;
              }
            }
          }
          if (an == 1) {
            break;
          }
        }
      }
      if (an == 0) cout << "NO" << endl;
    }
  }
  return 0;
}
