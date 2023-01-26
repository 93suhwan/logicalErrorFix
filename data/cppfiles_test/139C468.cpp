#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int mid, i, j;
    string a;
    cin >> a;
    if ((a.length()) % 2) {
      cout << "NO\n";
      continue;
    }
    mid = (a.length()) / 2;
    j = mid;
    i = 0;
    while (i < mid) {
      if (a[i] == a[j]) {
        i++;
        j++;
      } else {
        cout << "NO\n";
        break;
      }
    }
    if (i == mid) {
      cout << "YES\n";
    }
  }
}
