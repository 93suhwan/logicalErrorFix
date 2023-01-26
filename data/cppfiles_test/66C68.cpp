#include <bits/stdc++.h>
using namespace std;
int main() {
  int buf[2] = {
      0,
  };
  map<int, int> arr;
  buf[1] = 1;
  while (buf[0] < 1001) {
    if (buf[1] % 3 > 0 && buf[1] % 10 != 3) {
      buf[0]++;
      arr[buf[0]] = buf[1];
    }
    buf[1]++;
  }
  cin >> buf[0];
  while (cin >> buf[0]) cout << arr[buf[0]] << endl;
}
