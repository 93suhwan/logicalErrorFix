#include <bits/stdc++.h>
using namespace std;
int p[1000001];
int inc[1000001];
int decc[1000001];
int main() {
  int t, n;
  cin >> t;
outer:
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    int last = -1000001;
    int i;
    for (i = 0; i < n; i++) {
      if (-p[i] > last) {
        inc[i] = 1;
        last = -p[i];
        continue;
      }
      if (p[i] > last) {
        inc[i] = 1;
        last = p[i];
        continue;
      }
      break;
    }
    for (; i < n; i++) inc[i] = 0;
    last = 1000001;
    decc[n] = 1;
    for (i = n - 1; i >= 0; i--) {
      if (p[i] < last) {
        decc[i] = 1;
        last = p[i];
        continue;
      }
      if (-p[i] < last) {
        decc[i] = 1;
        last = -p[i];
        continue;
      }
      break;
    }
    for (; i >= 0; i--) decc[i] = 0;
    int done = 0;
    for (i = 0; i < n; i++) {
      if (inc[i] && decc[i + 1]) {
        cout << "YES " << endl;
        last = -1000001;
        for (int j = 0; j <= i; j++) {
          if (-p[j] > last)
            last = -p[j];
          else
            last = p[j];
          cout << last << " ";
        }
        last = -1000001;
        for (int j = i + 1; j < n; j++) {
          if (-p[j] > last)
            last = -p[j];
          else
            last = p[j];
          cout << last << " ";
        }
        cout << endl;
        done = 1;
        break;
      }
    }
    if (!done) cout << "NO" << endl;
  }
}
