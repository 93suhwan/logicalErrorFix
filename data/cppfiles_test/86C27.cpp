#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    long long int a[n], b[n];
    for (int i = 0; i < n; i++) {
      a[i] = s1[i];
      b[i] = s2[i];
    }
    long long int maxsum = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) maxsum += 2;
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        if (a[i] == '0') {
          if (i + 1 < n && a[i + 1] == '1' && b[i + 1] == '1') {
            maxsum += 2;
            i++;
          } else
            maxsum += 1;
        } else {
          if (i + 1 < n && a[i + 1] == '0' && b[i + 1] == '0') {
            maxsum += 2;
            i++;
          } else
            maxsum += 0;
        }
      }
    }
    cout << maxsum << endl;
  }
  return 0;
}
