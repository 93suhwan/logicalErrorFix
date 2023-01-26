#include <bits/stdc++.h>
using namespace std;
char a[26];
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> a;
    char b[50];
    int c[50] = {0}, sum = 0;
    int x;
    cin >> b;
    for (int i = 0; b[i] != '\0'; i++) {
      for (int j = 0; j < 26; j++) {
        if (b[i] == a[j]) c[i] = j + 1;
      }
    }
    for (int i = 1; i < strlen(b); i++) sum += abs(c[i] - c[i - 1]);
    cout << sum << endl;
  }
  system("pause");
  return 0;
}
