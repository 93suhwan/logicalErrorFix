#include <bits/stdc++.h>
using namespace std;
bool before(char binarr[], int n) {
  bool result = false;
  for (int i = 0; i < n / 2; i++) {
    if (binarr[i] == '0') {
      cout << i + 1 << " " << n << " " << i + 2 << " " << n;
      bool result = true;
    }
  }
  return result;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string bin;
    cin >> bin;
    char binarr[n + 1];
    strcpy(binarr, bin.c_str());
    if (before(binarr, n) == false) {
      for (int i = n - 1; i >= n / 2; i--) {
        if (binarr[i] == '0') {
          cout << 1 << " " << i + 1 << " " << 1 << " " << i;
        }
      }
    }
  }
  return 0;
}
