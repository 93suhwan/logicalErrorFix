#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    int count1, count2;
    long long s = 0;
    string str1, str2;
    cin >> str1 >> str2;
    for (int i = 1; i < str2.length(); i++) {
      for (int j = 0; j < str1.length(); j++) {
        if (str2[i - 1] == str1[j]) {
          count1 = j + 1;
        }
        if (str2[i] == str1[j]) {
          count2 = j + 1;
        }
      }
      s += abs(count1 - count2);
    }
    cout << s << endl;
  }
  return 0;
}
