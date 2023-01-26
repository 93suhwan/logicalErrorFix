#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  for (int k = 0; k < n; k++) {
    long long a, b = 0, v, l = 0;
    cin >> a;
    string out[a];
    vector<string> arrin(a - 2);
    for (int i = 0; i < a - 2; i++) {
      cin >> arrin[i];
    }
    for (int i = 0; i < a - 3; i++) {
      if (arrin[i][1] != arrin[i + 1][0]) {
        b = 1;
        v = i + 1;
        break;
      }
    }
    if (b == 0) {
      out[0] = arrin[0][0];
      out[1] = arrin[0][1];
      for (int i = 2; i < a - 1; i++) {
        out[i] = arrin[i - 1][1];
      }
      out[a - 1] = out[a - 2];
      for (int i = 0; i < a; i++) {
        cout << out[i];
      }
      cout << endl;
    } else {
      out[0] = arrin[0][0];
      out[1] = arrin[0][1];
      for (int i = 2; i < a; i++) {
        l++;
        for (int j = l; j < a - 2; j++) {
          if (j == v) {
            out[i] = arrin[j][0];
            out[i + 1] = arrin[j][1];
            i++;
            break;
          } else {
            out[i] = arrin[j][1];
            break;
          }
        }
      }
      for (int i = 0; i < a; i++) {
        cout << out[i];
      }
      cout << endl;
    }
  }
}
