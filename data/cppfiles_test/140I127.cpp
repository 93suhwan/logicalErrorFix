#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int c = 0;
  for (int i = 0; i * i <= n; i++) {
    c++;
  }
  for (int i = 0; i * i * i <= n; i++) {
    c++;
  }
  for (int i = 0; i * i * i * i * i * i <= n; i++) {
    c--;
  }
  cout << c;
  return 0;
}
