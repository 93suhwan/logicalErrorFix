#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  int count = 0;
  char digit[110];
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    for (int l = 0; l < n; l++) {
      cin >> digit[l];
    }
    for (int j = 0; j < n; j++) {
      if (digit[j] != '0') {
        int var = n - 1;
        if (digit[j] == digit[var]) {
          while (digit[var] != '0') {
            int temp = digit[var];
            temp--;
            digit[var] = temp;
            count++;
          }
          if (digit[j] != digit[var]) {
            digit[var] = digit[j];
            digit[j] = '0';
            count++;
            while (digit[var] != '0') {
              int temp = digit[var];
              temp--;
              digit[var] = temp;
              count++;
            }
          }
        } else if (digit[var] == '0') {
          digit[var] = digit[j];
          digit[j] = '0';
          count++;
          while (digit[var] != '0') {
            int temp = digit[var];
            temp--;
            digit[var] = temp;
            count++;
          }
        } else if (digit[var] != '0') {
          while (digit[var] != '0') {
            int temp = digit[var];
            temp--;
            digit[var] = temp;
            count++;
          }
          digit[var] = digit[j];
          digit[j] = '0';
          count++;
          while (digit[var] != '0') {
            int temp = digit[var];
            temp--;
            digit[var] = temp;
            count++;
          }
        }
      } else if (digit[j] == '0') {
        int a;
      }
    }
    cout << count << endl;
    count = 0;
  }
  return 0;
}
