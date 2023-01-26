#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int k;
    cin >> k;
    string s;
    cin >> s;
    int f = 1;
    unordered_map<int, int> mp;
    for (int i = 0; i < k; i++) {
      int l = s[i] - '0';
      if ((l > 2 && l % 2 == 0) || (l > 3 && l % 3 == 0) || l == 1) {
        cout << 1 << endl;
        cout << l << endl;
        f = 0;
        break;
      }
      mp[l]++;
    }
    if (f == 1)
      for (int i = 0; i < k; i++) {
        if (f == 1) {
          if (s[i] == '2') {
            mp[2]--;
            if (mp[2] >= 1) {
              f = 0;
              cout << "2" << endl;
              cout << "22" << endl;
            } else if (mp.find(5) != mp.end()) {
              f = 0;
              cout << "2" << endl;
              cout << "25" << endl;
            } else if (mp.find(7) != mp.end()) {
              f = 0;
              cout << "2" << endl;
              cout << "27" << endl;
            }
          } else if (s[i] == '3') {
            mp[3]--;
            if (mp[3] > 1) {
              f = 0;
              cout << "2" << endl;
              cout << "33" << endl;
            } else if (mp.find(5) != mp.end()) {
              f = 0;
              cout << "2" << endl;
              cout << "35" << endl;
            } else if (mp.find(2) != mp.end()) {
              f = 0;
              cout << "2" << endl;
              cout << "32" << endl;
            }
          } else if (s[i] == '5') {
            mp[5]--;
            if (mp[5] >= 1) {
              f = 0;
              cout << "2" << endl;
              cout << "55" << endl;
            } else if (mp.find(7) != mp.end()) {
              f = 0;
              cout << "2" << endl;
              cout << "57" << endl;
            } else if (mp.find(2) != mp.end()) {
              f = 0;
              cout << "2" << endl;
              cout << "52" << endl;
            }
          } else {
            mp[7]--;
            if (mp[7] >= 1) {
              f = 0;
              cout << "2" << endl;
              cout << "77" << endl;
            } else if (mp.find(5) != mp.end()) {
              f = 0;
              cout << "2" << endl;
              cout << "75" << endl;
            } else if (mp.find(2) != mp.end()) {
              f = 0;
              cout << "2" << endl;
              cout << "72" << endl;
            }
          }
        } else
          break;
      }
  }
}
