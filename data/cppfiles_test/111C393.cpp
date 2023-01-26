#include <bits/stdc++.h>
using namespace std;
long n, k[51];
string s[51][51];
int main() {
  s[1][1] = "()";
  for (long i = 2; i <= 50; i++) {
    for (long j = 1; j <= i - 1; j++) s[i][j] = '(' + s[i - 1][j] + ')';
    s[i][i] = s[i - 1][1] + "()";
  }
  cin >> n;
  for (long i = 1; i <= n; i++) cin >> k[i];
  for (long i = 1; i <= n; i++)
    for (long j = 1; j <= k[i]; j++) cout << s[k[i]][j] << endl;
}
