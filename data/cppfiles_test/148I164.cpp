#include <bits/stdc++.h>
using namespace std;
int main() {
  int cases;
  cin >> cases;
  while (cases--) {
    int w, h;
    cin >> w >> h;
    int l;
    cin >> l;
    int a1, a2, a3, a4;
    int temp;
    int b;
    for (int i = 0; i < l; i++) {
      if (i == 0)
        cin >> b;
      else
        cin >> temp;
    }
    a1 = (temp - b) * h;
    cin >> l;
    for (int i = 0; i < l; i++) {
      if (i == 0)
        cin >> b;
      else
        cin >> temp;
    }
    a2 = (temp - b) * h;
    cin >> l;
    for (int i = 0; i < l; i++) {
      if (i == 0)
        cin >> b;
      else
        cin >> temp;
    }
    a3 = (temp - b) * w;
    cin >> l;
    for (int i = 0; i < l; i++) {
      if (i == 0)
        cin >> b;
      else
        cin >> temp;
    }
    a4 = (temp - b) * w;
    cout << max({a1, a2, a3, a4}) << '\n';
  }
  return 0;
}
