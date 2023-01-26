#include <bits/stdc++.h>
using namespace std;
const int N = 2E5 + 10;
int a[N], b[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    string s;
    cin >> s;
    vector<int> r, b;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'R')
        r.push_back(a[i + 1]);
      else
        b.push_back(a[i + 1]);
    }
    sort(b.begin(), b.end());
    sort(r.begin(), r.end());
    reverse(r.begin(), r.end());
    bool ok = true;
    int cnt = 1;
    for (int i = 0; i < b.size(); i++) {
      if (b[i] >= cnt)
        cnt++;
      else {
        ok = false;
        break;
      }
    }
    cnt = n;
    for (int i = 0; i < r.size(); i++) {
      if (r[i] <= cnt)
        cnt--;
      else {
        ok = false;
        break;
      }
    }
    if (!ok)
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
