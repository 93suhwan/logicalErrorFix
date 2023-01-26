#include <bits/stdc++.h>
using namespace std;
int main() {
  int num = 0;
  cin >> num;
  for (int i = 0; i < num; i++) {
    string str1;
    string str2;
    cin >> str1 >> str2;
    sort(str1.begin(), str1.end());
    if (str2 == "abc") {
      int j = 0;
      int j1 = -1;
      int j2 = -1;
      while (j < str1.size() && str1[j] == 'a') {
        j++;
      }
      if (str1[0] == 'a' && j < str1.size() && str1[j] == 'b') {
        j1 = j;
        while (j < str1.size() && str1[j] == 'b') {
          j++;
        }
        if (j < str1.size() && str1[j] == 'c') {
          j2 = j;
        }
      }
      if (j1 != -1 && j2 != -1) {
        swap(str1[j1], str1[j2]);
      }
    }
    cout << str1 << endl;
  }
}
