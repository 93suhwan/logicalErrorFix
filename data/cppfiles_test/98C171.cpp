#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string keyboard, str;
    cin >> keyboard >> str;
    int sum = 0;
    int i1, i2;
    for (int i = 1; i < str.length(); i++) {
      if (str[i] != str[i - 1]) {
        i1 = keyboard.find(str[i - 1]);
        i2 = keyboard.find(str[i]);
        int diff = i2 - i1;
        sum = sum + abs(diff);
      }
    }
    cout << sum << endl;
  }
}
