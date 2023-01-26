#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, i;
  int blocks, tmp;
  float avg, sum = 0;
  cin >> n;
  while (n) {
    cin >> blocks;
    for (i = 0; i < blocks; i++) {
      cin >> tmp;
      sum += tmp;
    }
    avg = sum / blocks;
    if (avg == (int)avg)
      cout << "0" << endl;
    else
      cout << sum - ((int)(avg)) * blocks << endl;
    n--;
    sum = 0;
  }
  return 0;
}
