#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      if (str[i] == '1') a++;
      if (str[i] == '2') b++;
    }
    if (b > 0 && b < 3) {
      cout << "NO" << endl;
      continue;
    }
    int arr[b];
    int l = 0;
    for (int i = 0; i < n; i++) {
      if (str[i] == '2') {
        arr[l] = i;
        l++;
      }
    }
    cout << "YES" << endl;
    int flag = 0;
    for (int i = 0; i < n; i++) {
      int flag1 = 0;
      for (int j = 0; j < n; j++) {
        if (i == j)
          cout << "X";
        else if (str[i] == '1')
          cout << "=";
        else {
          if (str[j] == '1')
            cout << "=";
          else {
            if (str[j] == '1')
              cout << "=";
            else if (flag + 1 >= b) {
              if (j == arr[0])
                cout << "+";
              else
                cout << "-";
            } else {
              if (j == arr[flag + 1] && flag1 == 0) {
                cout << "+";
                flag++;
                flag1++;
              } else
                cout << "-";
            }
          }
        }
      }
      cout << endl;
    }
  }
}
