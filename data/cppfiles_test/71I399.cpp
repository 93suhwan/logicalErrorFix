#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    vector<int> digits;
    long long int temp = n;
    while (temp != 0) {
      digits.push_back(temp % 10);
      temp /= 10;
    }
    reverse(digits.begin(), digits.end());
    string s = "";
    string s1 = "";
    for (int i = 0; i < digits.size(); i++) {
      if (digits[0] != 9) {
        s += to_string(digits[0]);
        s1 += to_string(digits[0] + 1);
      } else {
        s += to_string(digits[0]);
      }
    }
    if (k == 1) {
      if (digits[0] != 9) {
        long long int x = stoull(s);
        long long int y = stoull(s1);
        if (x < n) {
          cout << y << endl;
        } else {
          cout << x << endl;
        }
      } else {
        cout << s << endl;
      }
    } else {
      int i = 1;
      for (; i < n; i++) {
        int digi = s[i] - '0';
        if (digi != digits[i]) {
          s[i] = digits[i] + '0';
          break;
        }
      }
      if (i == n) {
        cout << s << endl;
      } else {
        int digi2 = s[i] - '0';
        int digi1 = s[0] - '0';
        int min_1 = min(digi1, digi2);
        int min_2 = digi1;
        if (min_1 == digi1) {
          min_2 = digi2;
        } else {
          min_2 = digi1;
        }
        bool b = false;
        bool b1 = false;
        bool b2 = false;
        int j = i + 1;
        for (; j < digits.size(); j++) {
          if (min_1 > digits[j]) {
            b = true;
            break;
          } else if (min_1 == digits[j]) {
            s[j] = digits[j] + '0';
          } else if (min_2 < digits[j]) {
            b1 = true;
            break;
          } else if (min_2 > digits[j] && min_1 != digits[j]) {
            s[j] = min_2 + '0';
            b2 = true;
            break;
          } else {
            s[j] = min_2 + '0';
          }
        }
        if (b) {
          for (int k = j; k < s.length(); k++) {
            s[k] = min_1 + '0';
          }
          cout << s << endl;
        } else if (b1) {
          if (min_2 > digits[j - 1]) {
            s[j - 1] = min_2 + '0';
            for (int k = j; k < s.length(); k++) {
              s[k] = min_1 + '0';
            }
            cout << s << endl;
          } else {
            s[i] = min_2 + 1 + '0';
            for (int k = i + 1; k < s.length(); k++) {
              s[k] = min_1 + '0';
            }
            cout << s << endl;
          }
        } else if (b2) {
          for (int k = j + 1; k < s.length(); k++) {
            s[k] = min_1 + '0';
          }
          cout << s << endl;
        } else {
          cout << s << endl;
        }
      }
    }
  }
  return 0;
}
