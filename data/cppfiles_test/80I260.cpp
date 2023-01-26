#include <bits/stdc++.h>
using namespace std;
void findDecimal(int d[], int n);
int main(int argc, char **argv) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string number;
    cin >> n >> number;
    int indexLastZero = n;
    for (int i = 0; i < n; i++) {
      if (number[i] == '0') indexLastZero = i;
    }
    int i = indexLastZero;
    if (i < n / 2) {
      cout << i + 1 << " " << n << " " << i + 2 << " " << n << endl;
    } else {
      cout << "1 " << i + 1 << " 1 " << i << endl;
    }
  }
  return 0;
}
