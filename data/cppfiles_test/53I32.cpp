#include <bits/stdc++.h>
using namespace std;
bool temp[52];
string s;
long long tttt;
long long n, k, m, ans, maax, maxx, x;
long long a[2 * 1000 * 100];
char c;
vector<int> v;
int main() {
  cin >> tttt;
  while (tttt--) {
    cin >> n >> c;
    cin >> s;
    k = 0;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == c) {
        k++;
      }
    }
    ans = 2;
    bool fl1 = 0, fl2 = 0;
    if (k == n - 1) fl1 = 1;
    if (s[n - 1] == c) fl2 = 1;
    if (fl1) ans--;
    if (fl2) ans--;
    cout << ans << endl;
    if (!fl1) {
      cout << n << " ";
    }
    if (!fl2) {
      cout << n - 1;
    }
    if (ans != 0) {
      cout << endl;
    }
  }
  return 0;
}
