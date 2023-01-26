#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string a;
    string b;
    cin >> a >> b;
    int ans = 1;
    for (int j = 0; j < n; j++)
      if (a[j] == '1' && b[j] == '1') ans = 0;
    if (ans)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
