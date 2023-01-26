#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  int n;
  char s[1000];
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    cin >> s;
    int a[1000];
    int k = 0;
    int r = 1;
    for (int i = 0; i < n; i++) {
      a[i] = s[i] - '0';
    }
    int temp;
    for (int i = 0; i < n; i++) {
      while (a[n - 1] > 0) {
        a[n - 1]--;
        k++;
      }
      if (a[i] != 0) {
        temp = a[i];
        a[i] = a[n - 1];
        a[n - 1] = temp;
        k++;
      }
    }
    cout << k << endl;
  }
  return 0;
}
