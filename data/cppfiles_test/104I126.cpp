#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int db = 0;
    vector<int> v(n), ki;
    int ind = -1, ossz = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      ossz += v[i];
      if ((ossz & 1) == 0 && v[i] == 0) ind = i;
      if (ind == -1) {
        if (i > 2 && v[i - 1] == 0 && v[i - 2] == 0) {
          v[i - 2] = v[i - 1] = 1;
          ossz += 2;
          ki.push_back(i - 2);
        } else if (i > 1 && v[i - 1] == 0 && v[i - 2] == 1 && v[i] == 1) {
          v[i - 2] = v[i] = 0;
          ossz -= 2;
          ki.push_back(i - 1);
          ind = i - 1;
        }
      }
    }
    if ((ossz & 1) || ind == -1) {
      cout << "NO\n";
      continue;
    }
    cout << ind << " ind\n";
    for (int i = ind; i > 1; i--) {
      if (v[i - 1] == 1 && v[i - 2] == 1) {
        ki.push_back(i - 1);
        v[i - 1] = v[i - 2] = 0;
      } else if (v[i - 1] == 1 && v[i - 2] == 0) {
        ki.push_back(i - 2);
        if (v[i - 3] == 0) {
          ki.push_back(i - 1);
          v[i - 1] = 0;
          v[i - 3] = 1;
        } else {
          v[i - 1] = v[i - 3] = 0;
        }
      }
    }
    for (int i = ind; i < n - 2; i++) {
      if (v[i + 1] == 1 && v[i + 2] == 1) {
        ki.push_back(i + 1);
        v[i + 1] = v[i + 2] = 0;
      } else if (v[i + 1] == 1 && v[i + 2] == 0) {
        ki.push_back(i + 2);
        if (v[i + 3] == 0) {
          ki.push_back(i + 1);
          v[i + 1] = 0;
          v[i + 3] = 1;
        } else {
          v[i + 1] = v[i + 3] = 0;
        }
      }
    }
    cout << "YES\n";
    cout << ki.size() << '\n';
    for (int i = 0; i < (int)ki.size(); i++)
      cout << ki[i] << " \n"[i == (int)ki.size() - 1];
  }
  return 0;
}
