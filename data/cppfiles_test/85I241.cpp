#include <bits/stdc++.h>
using namespace std;
int sum;
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    sum = 0;
    char a[100000];
    scanf("%s", a);
    cin >> a;
    for (int i = 0; i <= strlen(a); i++) {
      if (a[i] == '0' && a[i - 1] != '0') sum += 1;
    }
    if (sum > 2) sum = 2;
    cout << sum << endl;
  }
  return 0;
}
