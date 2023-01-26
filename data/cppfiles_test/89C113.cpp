#include <bits/stdc++.h>
using namespace std;
const long long MAX = 2 * 1e5 + 1;
long long M = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> vec(n);
    for (int i = 0; i < n; i++) {
      cin >> vec[i];
    }
    for (int i = vec.size() - 1; i >= 0; i--) {
      if (vec[i] % (i + 2) != 0) {
        vec.pop_back();
      } else {
        break;
      }
    }
    if (vec.size() == 0) {
      cout << "YES\n";
      ;
      continue;
    }
    bool ans = 1;
    set<int> st;
    for (int i = 0; i < vec.size(); i++) {
      if (vec[i] % (i + 2) != 0) {
      } else {
        int num = vec[i];
        int den = i + 2;
        bool p = 0;
        int need = 0;
        while (den >= 2 && den >= i + 2 - 15) {
          if (num % den != 0) {
            p = 1;
            break;
          }
          ++need;
          --den;
        }
        if (!p || need > i) {
          ans = false;
          break;
        }
      }
    }
    if (ans) {
      cout << "YES\n";
      ;
    } else {
      cout << "NO\n";
      ;
    }
  }
  return 0;
}
