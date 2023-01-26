#include <bits/stdc++.h>
using namespace std;
long long int t, n, m, k;
string str;
vector<long long int> vect;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> str;
    bool all = 1;
    vect.clear();
    for (long long int i = 0; i < n; i++) {
      if (str[i] == 'R') {
        vect.push_back(0);
        all = 0;
      } else if (str[i] == 'B') {
        vect.push_back(1);
        all = 0;
      } else
        vect.push_back(2);
    }
    if (!all) {
      for (long long int i = 0; i < n; i++) {
        if (i > 0) {
          if (vect[i - 1] != 2 && vect[i] == 2) {
            vect[i] = !(vect[i - 1]);
          }
        }
      }
      for (long long int i = n - 1; i >= 0; i--) {
        if (vect[i] == 2 && vect[i + 1] != 2) {
          vect[i] = !(vect[i + 1]);
        }
      }
      for (long long int i = 0; i < n; i++) {
        if (vect[i]) {
          cout << "B";
        } else
          cout << "R";
      }
    } else {
      bool say = 0;
      for (long long int i = 0; i < n; i++) {
        if (say) {
          cout << "R";
        } else {
          cout << "B";
        }
        say = !say;
      }
    }
    cout << endl;
  }
}
