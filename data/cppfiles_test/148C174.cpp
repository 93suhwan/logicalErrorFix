#include <bits/stdc++.h>
using namespace std;
int main() {
  int cases;
  cin >> cases;
  while (cases--) {
    long long w, h;
    cin >> w >> h;
    long long n, s, b;
    long long re = 0;
    cin >> n;
    cin >> s;
    n--;
    while (n--) {
      cin >> b;
    }
    re = max((b - s) * h, re);
    cin >> n;
    cin >> s;
    n--;
    while (n--) {
      cin >> b;
    }
    re = max((b - s) * h, re);
    cin >> n;
    cin >> s;
    n--;
    while (n--) {
      cin >> b;
    }
    re = max((b - s) * w, re);
    cin >> n;
    cin >> s;
    n--;
    while (n--) {
      cin >> b;
    }
    re = max((b - s) * w, re);
    cout << re << endl;
  }
  return 0;
}
