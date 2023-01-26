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
    x = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == c) {
        k++;
        if (i >= n / 2) {
          x = i;
        }
      }
    }
    if (k == n) {
      cout << 0 << endl;
      continue;
    }
    if (x != 0) {
      cout << 1 << endl << x + 1 << endl;
      continue;
    }
    cout << 2 << endl << n - 1 << " " << n << endl;
  }
  return 0;
}
