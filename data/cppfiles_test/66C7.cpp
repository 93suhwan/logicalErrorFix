#include <bits/stdc++.h>
using namespace std;
int main() {
  int mas[1001];
  int a = 1;
  for (int i = 1; i <= 1000; i++) {
    mas[i] = a;
    a++;
    if (a % 3 == 0 || a % 10 == 3) a++;
    if (a % 3 == 0 || a % 10 == 3) a++;
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int f;
    cin >> f;
    cout << mas[f] << endl;
  }
  return 0;
}
