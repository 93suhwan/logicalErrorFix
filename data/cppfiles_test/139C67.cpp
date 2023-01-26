#include <bits/stdc++.h>
using namespace std;
long long int t, n, i = 0, j = 0, k = 0, l = 0;
int main() {
  scanf("%lli", &t);
  while (t--) {
    string s;
    cin >> s;
    long long int l = s.size(), c = 0;
    for (i = 0, j = l / 2; i < l, j < l; i++, j++) {
      if (s[i] != s[j]) c = 1;
    }
    if (c || l % 2)
      printf("NO\n");
    else
      printf("YES\n");
  }
  cerr << "[Execution : " << (1.0 * clock()) / CLOCKS_PER_SEC << "s]" << endl;
  return 0;
}
