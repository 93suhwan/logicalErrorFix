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
      int first = 0, last = 0;
      if (c > 0) {
        first = vec[0];
        last = vec[vec.size() - 1];
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (i == j) {
            cout << "X";
          } else if (s[i] == '1' && s[j] == '1') {
            cout << "=";
          } else if (s[i] == '1' && s[j] == '2') {
            cout << "+";
          } else if (s[i] == '2' && s[j] == '1') {
            cout << "-";
          } else if (s[i] == '2' && i == first) {
            if (j == last) {
              cout << "-";
            } else {
              cout << "+";
            }
          } else if (s[i] == '2' && i == last) {
            if (j == first) {
              cout << "+";
            } else {
              cout << "-";
            }
          } else if (s[i] == '2' && i > j && s[j] == '2') {
            cout << "-";
          } else if (s[i] == '2' && i < j && s[j] == '2') {
            cout << "+";
          }
        }
        cout << endl;
      }
    }
  }
  return 0;
}
