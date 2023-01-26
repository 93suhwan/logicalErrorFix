#include <bits/stdc++.h>
using namespace std;
char a[100009];
int sum;
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    sum = 0;
    char a[100009];
    cin >> a;
    for (int i = 0; a[i] != '\0'; i++) {
      if (a[i] == '0' && a[i - 1] != '0') sum += 1;
    }
    if (sum > 2) sum = 2;
    cout << sum << endl;
  }
  return 0;
}
