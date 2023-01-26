#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int k;
    cin >> k;
    string str;
    cin >> str;
    vector<int> count(10, 0);
    int possible = 0;
    for (int i = 0; i < str.length(); i++) {
      count[str[i] - '0']++;
      if (str[i] == '4' || str[i] == '6' || str[i] == '8' || str[i] == '9' ||
          str[i] == '1') {
        cout << 1 << endl << str[i] << endl;
        possible++;
        break;
      }
    }
    if (possible) continue;
    int two = -1;
    int five = -1;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == '2') two = i;
      if (str[i] == '5') five = i;
    }
    if (two != -1 && two) {
      cout << 2 << endl << str[two - 1] << str[two] << endl;
      continue;
    }
    if (five != -1 && five) {
      cout << 2 << endl << str[five - 1] << str[five] << endl;
      continue;
    }
    possible = 0;
    for (int i = 2; i < 10; i++)
      if (count[i] >= 2) {
        possible = 1;
        cout << 2 << endl << char(i + 48) << char(i + 48) << endl;
        break;
      }
    if (possible) continue;
    if (str == "237") cout << 2 << endl << "27" << endl;
    if (str == "273") cout << 2 << endl << "27" << endl;
    if (str == "573") cout << 2 << endl << "57" << endl;
    if (str == "537") cout << 2 << endl << "57" << endl;
    if (str == "57") cout << 2 << endl << "57" << endl;
    if (str == "27") cout << 2 << endl << "27" << endl;
  }
}
