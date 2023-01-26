#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  cin.ignore();
  while (test--) {
    string s1;
    getline(cin, s1);
    vector<char> c;
    if (s1.length() % 2 == 0) {
      int size1, flag = 0, x = 0;
      size1 = s1.length() / 2;
      while (x < size1) {
        c.push_back(s1[x]);
        x++;
      }
      int i = size1;
      int j = 0;
      while (i < s1.length()) {
        if (s1[i] == c[j]) {
          i++;
          j++;
          flag = 1;
        } else {
          flag = 0;
          break;
        }
      }
      if (flag == 0) {
        cout << "NO" << endl;
      } else {
        cout << "YES"
             << "\n";
      }
    } else {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}
