#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, i;
  long int blocks, tmp;
  double avg, sum = 0;
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
      cout << "1" << endl;
    n--;
    sum = 0;
  }
  return 0;
}
