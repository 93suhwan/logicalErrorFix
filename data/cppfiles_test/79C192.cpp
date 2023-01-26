#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long k;
    cin >> k;
    string s;
    cin >> s;
    vector<long long> v;
    long long num = -1;
    for (int i = s.length() - 1; i >= 0; i--) {
      if ((s[i] - '0') % 10 == 2 || (s[i] - '0') % 10 == 5 ||
          (s[i] - '0') % 10 == 3 || (s[i] - '0') % 10 == 7) {
        v.push_back((s[i] - '0') % 10);
      } else {
        num = (s[i] - '0') % 10;
      }
    }
    if (v.size() != k) {
      cout << 1 << "\n";
      cout << num << "\n";
    } else {
      bool nflag = true;
      cout << 2 << "\n";
      for (int i = 0; i < v.size(); i++) {
        if (v[i] == 2) {
          for (int j = i + 1; j < v.size(); j++) {
            if (v[j] == 7 || v[j] == 3 || v[j] == 5 || v[j] == 2) {
              cout << v[j] << "" << v[i] << "\n";
              nflag = false;
              break;
            }
          }
        } else if (v[i] == 7) {
          for (int j = i + 1; j < v.size(); j++) {
            if (v[j] == 2 || v[j] == 7 || v[j] == 5) {
              cout << v[j] << "" << v[i] << "\n";
              nflag = false;
              break;
            }
          }
        } else if (v[i] == 5) {
          for (int j = i + 1; j < v.size(); j++) {
            if (v[j] == 2 || v[j] == 7 || v[j] == 5 || v[j] == 3) {
              cout << v[j] << "" << v[i] << "\n";
              nflag = false;
              break;
            }
          }
        } else if (v[i] == 3) {
          for (int j = i + 1; j < v.size(); j++) {
            if (v[j] == 3) {
              cout << v[j] << "" << v[i] << "\n";
              nflag = false;
              break;
            }
          }
        }
        if (!nflag) break;
      }
    }
  }
}
