#include <bits/stdc++.h>
using namespace std;
int t, a[2];
string s;
int main() {
  scanf("%d", &t);
  while (t--) {
    cin >> s;
    a[0] = a[1] = a[2] = 0;
    for (int i = 0; i < s.length(); ++i) a[s[i] - 'A']++;
    if (a[0] + a[2] == a[1])
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
