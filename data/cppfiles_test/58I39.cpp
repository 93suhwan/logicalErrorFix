#include <bits/stdc++.h>
using namespace std;
void run_case() {
  int n;
  cin >> n;
  vector<string> v(2);
  for (int i = 0; i < 2; i++) {
    cin >> v[i];
  }
  bool ok = true;
  for (int i = 0; i < n - 1; i++) {
    if (v[0][i] == '0' && v[0][i + 1] == '1') {
      if (v[1][i] == '1' && v[1][i + 1] == '1') {
        ok = false;
        break;
      }
    }
  }
  for (int i = 0; i < n - 1; i++) {
    if (v[1][i] == '0' && v[1][i + 1] == '1') {
      if (v[0][i] == '1' && v[0][i + 1] == '1') {
        ok = false;
        break;
      }
    }
  }
  if (ok) {
    cout << "YES" << endl;
  } else {
    cout << "No" << endl;
  }
}
int main() {
  int tc = 1;
  cin >> tc;
  while (tc--) {
    run_case();
  }
  return 0;
}
