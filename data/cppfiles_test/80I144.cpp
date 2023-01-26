#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 1;
char s[maxn];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    cin >> s;
    int id = 0;
    for (int i = 0; i < n; i++)
      if (s[i] == '0') id = i + 1;
    if (id == 0)
      cout << 1 << " " << n / 2 << " " << 2 << " " << n / 2 + 1 << endl;
    if (id > n / 2)
      cout << 1 << " " << id << " " << 1 << " " << id - 1 << endl;
    else
      cout << id << " " << n << " " << id + 1 << " " << n << endl;
  }
  return 0;
}
