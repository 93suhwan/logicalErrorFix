#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int result = 0;
    int temp = 0;
    int temp1 = 0;
    for (int i = 0; i < n; i++) {
      if (s1[i] == '0' && s2[i] == '0') {
        temp += 1;
        if (temp == 2) {
          result += temp;
          temp = 0;
          temp1 = 0;
        } else {
          if (temp1 == 1) {
            result += 2;
            temp1 = 0;
            temp = 0;
          }
        }
      }
      if (s1[i] == '1' && s2[i] == '1') {
        if (temp == 1) {
          result += 2;
          temp = 0;
          temp1 = 0;
        } else {
          temp1 = 1;
        }
      }
      if ((s1[i] == '1' && s2[i] == '0') || (s1[i] == '0' && s2[i] == '1')) {
        result += 2;
        result += temp;
        temp = 0;
        temp1 = 0;
      }
    }
    result += temp;
    cout << result << endl;
  }
}
