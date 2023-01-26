#include <bits/stdc++.h>
using namespace std;
int main() {
  int k = 1, t;
  cin >> t;
  while (t != 0) {
    int ar[50], counter = 0, time = 0;
    string set, inp;
    cin >> set;
    cin >> inp;
    for (int i = 0; i <= inp.length(); i++) {
      for (int j = 0; j < 26; j++) {
        if (set[j] == inp[i]) {
          ar[counter] = j;
          counter++;
        }
      }
    }
    for (int i = 0; i < counter - 1; i++) {
      time += abs(ar[i] - ar[i + 1]);
    }
    cout << time << endl;
    t--;
  }
  return 0;
}
