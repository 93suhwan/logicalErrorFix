#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k, x, l = 0;
    string s, a;
    cin >> n >> k >> x >> s;
    x--;
    a = "";
    for (int i = n - 1; i + 1; i--) {
      if (s[i] == 'a') a += 'a';
      l += k;
      if (i == 0 || s[i - 1] == 'a') {
        a += string(x % (l + 1), 'b');
        x = x / (l + 1);
        l = 0;
      }
    }
    reverse(a.begin(), a.end());
    cout << a << endl;
  }
}
