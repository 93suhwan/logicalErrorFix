#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  vector<int> a;
  int n;
  a.resize(2e5);
  for (int i = 0; i < t; i++) {
    string s;
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> a[j];
    }
    cin >> s;
    int count = 0;
    for (int j = 0; j < n; j++) {
      if (s[j] == '1') {
        count++;
      }
    }
    if (count == n) {
      for (int j = 0; j < n; j++) {
        if (j == 0)
          cout << a[j];
        else
          cout << " " << a[j];
      }
      cout << "\n";
      continue;
    }
    count++;
    int tmp = 1;
    for (int j = 0; j < n; j++) {
      if (s[j] == '1') {
        a[j] = count++;
      } else {
        a[j] = tmp++;
      }
    }
    for (int j = 0; j < n; j++) {
      if (j == 0)
        cout << a[j];
      else
        cout << " " << a[j];
    }
    cout << "\n";
  }
  return 0;
}
