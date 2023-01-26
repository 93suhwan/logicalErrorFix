#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long n;
string a, b;
bool vis[1000];
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    bool ff = 0;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] == '1' && b[i] == '1') ff = 1;
    }
    if (ff)
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
