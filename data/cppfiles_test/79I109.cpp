#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const long long int N = 1e5 + 10;
int n;
string s;
string ans;
string ans2;
string ans3;
string ans5;
string ans7;
int main() {
  ios::sync_with_stdio(false);
  long long int t = 1;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    ans.clear();
    ans2.clear();
    ans3.clear();
    ans5.clear();
    ans7.clear();
    bool if2 = false;
    bool if3 = false;
    bool if5 = false;
    bool if7 = false;
    bool exist1 = false;
    bool exist2 = false;
    for (int i = 0; i < s.size(); i++) {
      if (if2) {
        if (s[i] == '2') {
          exist2 = true;
          ans2 += "2";
          break;
        } else if (s[i] == '5') {
          exist2 = true;
          ans2 += "5";
          break;
        } else if (s[i] == '7') {
          exist2 = true;
          ans2 += "7";
          break;
        }
      }
      if (if3) {
        if (s[i] == '2') {
          exist2 = true;
          ans3 += "2";
          break;
        } else if (s[i] == '3') {
          exist2 = true;
          ans3 += "3";
          break;
        } else if (s[i] == '5') {
          exist2 = true;
          ans3 += "5";
          break;
        }
      }
      if (if5) {
        if (s[i] == '2') {
          exist2 = true;
          ans5 += "2";
          break;
        } else if (s[i] == '5') {
          exist2 = true;
          ans5 += "5";
          break;
        } else if (s[i] == '7') {
          exist2 = true;
          ans5 += "7";
          break;
        }
      }
      if (if7) {
        if (s[i] == '2') {
          exist2 = true;
          ans7 += "2";
          break;
        } else if (s[i] == '5') {
          exist2 = true;
          ans7 += "5";
          break;
        } else if (s[i] == '7') {
          exist2 = true;
          ans7 += "7";
          break;
        }
      }
      if (s[i] == '1') {
        exist1 = true;
        ans += "1";
        break;
      } else if (s[i] == '4') {
        exist1 = true;
        ans += "4";
        break;
      } else if (s[i] == '6') {
        exist1 = true;
        ans += "6";
        break;
      } else if (s[i] == '8') {
        exist1 = true;
        ans += "8";
        break;
      } else if (s[i] == '9') {
        exist1 = true;
        ans += "9";
        break;
      } else if (s[i] == '2') {
        if2 = true;
        ans2 += "2";
      } else if (s[i] == '3') {
        if3 = true;
        ans3 += "3";
      } else if (s[i] == '5') {
        if5 = true;
        ans5 += "5";
      } else if (s[i] == '7') {
        if7 = true;
        ans7 += "7";
      }
    }
    if (exist1)
      cout << "1\n" << ans << '\n';
    else if (exist2) {
      cout << "2\n";
      if (ans2.size() == 2)
        cout << ans2 << "\n";
      else if (ans3.size() == 2)
        cout << ans3 << "\n";
      else if (ans5.size() == 2)
        cout << ans5 << "\n";
      else if (ans7.size() == 2)
        cout << ans7 << "\n";
    }
  }
  return 0;
}
