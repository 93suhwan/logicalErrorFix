#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int arr[51] = {0};
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'E') {
        if (s[i - 1] == 'E') {
          arr[i] = arr[i - 1];
          arr[i + 1] = arr[i];
        } else {
          arr[i] = i;
          arr[i + 1] = arr[i];
        }
      } else {
        if (i == 0) {
          arr[i] = i;
          arr[i + 1] = i + 1;
        } else {
          if (s[i - 1] == 'E')
            arr[i] = arr[i - 1];
          else
            arr[i] = i;
        }
      }
    }
    int a = 0;
    for (int i = 0; i < s.length() - 1; i++) {
      if (s[i] == 'E') {
        if (arr[i] != arr[i + 1]) {
          a = 2;
          cout << "NO" << endl;
        }
        if (a == 2) break;
      } else {
        if (arr[i] == arr[i + 1]) {
          a = 2;
          cout << "NO" << endl;
        }
        if (a == 2) break;
      }
    }
    if (s[s.length() - 1] == 'N' && a != 2) {
      if (arr[0] == arr[s.length() - 1]) {
        a = 1;
        cout << "NO" << endl;
      }
    }
    if (a == 0) cout << "YES" << endl;
  }
}
