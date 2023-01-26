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
      int sumb = 0;
      int sumc = 0;
      while (j < str1.size() && str1[j] == 'a') {
        j++;
      }
      if (str1[0] == 'a' && j < str1.size() && str1[j] == 'b') {
        j1 = j;
        while (j < str1.size() && str1[j] == 'b') {
          j++;
          sumb++;
        }
        if (j < str1.size() && str1[j] == 'c') {
          while (j < str1.size() && str1[j] == 'c') {
            sumc++;
            j++;
          }
        }
      }
      if (sumb > 0 && sumc > 0) {
        for (j = j1; j < j1 + sumc; j++) {
          str1[j] = 'c';
        }
        for (j = j1 + sumc; j < j1 + sumc + sumb; j++) {
          str1[j] = 'b';
        }
      }
    }
    cout << str1 << endl;
  }
}
