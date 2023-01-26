#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    string d;
    cin >> d;
    double n = d.length();
    int bc = 0;
    for (int i = 0; i < d.length(); i++) {
      if (d[i] == 'B') bc++;
    }
    if (ceil(n / 2) == bc)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
