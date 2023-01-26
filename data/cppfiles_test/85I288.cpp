#include <bits/stdc++.h>
using namespace std;
int a;
int sum;
int n;
int main() {
  char a[10009];
  cin >> n;
  for (int i = 1; i <= n; i++) {
    sum = 0;
    cin >> a;
    for (int i = 0; i <= strlen(a); i++) {
      if (a[i] == '0') sum += 1;
    }
    cout << sum << endl;
  }
  return 0;
}
