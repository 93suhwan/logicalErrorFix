#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long hours = 0, canShare = 1, comps, cabels, j = 0;
    cin >> comps >> cabels;
    comps -= 1;
    while (comps > 0) {
      if (canShare > cabels) {
        canShare = cabels;
      } else if (canShare < cabels) {
        canShare = pow(2, j);
        j++;
        if (canShare > cabels) {
          canShare = cabels;
        }
      } else if (comps > 100) {
        long long hours2 = comps / canShare;
        comps -= hours2 * canShare;
        hours += hours2;
      } else {
        comps -= canShare;
        hours++;
      }
    }
    cout << hours << "\n";
  }
  return 0;
}
