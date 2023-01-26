#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
bool primes[10000000];
using namespace std;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
  return a.first > b.first;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> vec;
    int c = 0, k = 1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '2') {
        c++;
        vec.push_back(i);
      }
    }
    if (c == 1) {
      cout << "NO" << endl;
    } else if (c == 2) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      for (int i = 0; i < n; i++) {
        int f = 0;
        for (int j = 0; j < n; j++) {
          if (i == j) {
            cout << "X";
          } else if (s[i] == '1' && s[j] == '1') {
            cout << "=";
          } else if (s[i] == '1' && s[j] == '2') {
            cout << "+";
          } else if (s[i] == '2' && s[j] == '1') {
            cout << "-";
          } else if (s[i] == '2' && f == 0 && vec[k] == j) {
            cout << "+";
            k++;
            if (k == vec.size()) {
              k = 0;
            }
            f = 1;
          } else if (s[i] == '2' && s[j] == '2') {
            cout << "-";
          }
        }
        cout << endl;
      }
    }
  }
  return 0;
}
