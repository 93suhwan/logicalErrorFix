#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  for (int j = 0; j < t; j++) {
    long long n, s, y;
    cin >> n >> s;
    y = s / ((n / 2) + 1);
    cout << y << endl;
  }
  return 0;
}
