#include <bits/stdc++.h>
using namespace std;
int sum;
int n;
int main() {
  int num;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    num = 1;
    sum = 0;
    char a[100000];
    for (int i = 0; a[i] != '\0'; i++) num++;
    cin >> a;
    for (int i = 0; i < num; i++) {
      if (a[i] == '0' && a[i - 1] != '0') sum += 1;
    }
    if (sum > 2) sum = 2;
    cout << sum << endl;
  }
  return 0;
}
