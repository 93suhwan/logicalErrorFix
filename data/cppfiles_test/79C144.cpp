#include <bits/stdc++.h>
using namespace std;
int main() {
  int com[] = {1, 4, 6, 8, 9};
  long long int t;
  cin >> t;
  while (t--) {
    int64_t k;
    cin >> k;
    string n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n.size(); i++) {
      m[n[i] - '0']++;
    }
    int flag = 1;
    for (auto it : m) {
      if (it.first == 1 || it.first == 4 || it.first == 6 || it.first == 8 ||
          it.first == 9) {
        flag = 0;
        cout << 1 << endl << it.first << endl;
        break;
      }
    }
    if (flag) {
      for (auto it : m) {
        if (it.second > 1) {
          cout << 2 << endl << it.first << it.first << endl;
          flag = 0;
          break;
        }
      }
      if (n == "32" || n == "35") {
        flag = 0;
        cout << 2 << endl << n << endl;
      }
    }
    if (flag) {
      stack<int> s;
      string temp = "";
      for (int i = 0; i < n.size(); i++) {
        if (n[i] != '3') {
          temp += n[i];
        }
        if (temp.size() == 2) {
          break;
        }
      }
      cout << 2 << endl << temp << endl;
    }
  }
}
