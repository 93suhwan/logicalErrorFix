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
    int indexLastZero = -1;
    for (int i = 0; i < n; i++) {
      if (number[i] == '0') indexLastZero = i;
    }
    int i = indexLastZero;
    if (i == -1) {
      cout << "1 " << n / 2 << " 2 " << n / 2 + 1 << endl;
    } else if (i < n / 2) {
      cout << i + 1 << " " << n << " " << i + 2 << " " << n << endl;
    } else {
      cout << "1 " << i + 1 << " 1 " << i << endl;
    }
  }
  return 0;
}
