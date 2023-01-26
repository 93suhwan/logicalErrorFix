#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e4 + 10;
int ans[Maxn];
int tmp[Maxn];
int example[3];
int main() {
  int cas;
  cin >> cas;
  while (cas--) {
    int n, x, cnt = 0, l = 0, r = 0;
    cin >> n;
    for (int i = 1; i <= n; i += 3) {
      cout << "? " << i << " " << i + 1 << " " << i + 2 << '\n';
      cin >> tmp[i];
      if (tmp[1] != tmp[i]) {
        l = 1, r = i;
      }
    }
    cout << "? " << l << " " << l + 1 << " " << r << '\n';
    cin >> x;
    if (x != tmp[l]) {
      example[tmp[r]] = r;
      example[tmp[l]] = l + 2;
    } else {
      cout << "? " << l << " " << l + 1 << " " << r + 1 << '\n';
      cin >> x;
      if (x != tmp[l]) {
        example[tmp[r]] = r + 1;
        example[tmp[l]] = l + 2;
      } else {
        example[tmp[l]] = l;
        cout << "? " << l << " " << r << " " << r + 1 << '\n';
        cin >> x;
        if (x != tmp[r]) {
          cout << "? " << l << " " << r << " " << r + 2 << '\n';
          cin >> x;
          if (x != tmp[r])
            example[tmp[r]] = r + 1;
          else
            example[tmp[r]] = r;
        } else {
          example[tmp[r]] = r;
        }
      }
    }
    for (int i = 1; i <= n; i += 3) {
      cout << "? " << i << " " << i + 1 << " " << example[1 - tmp[i]] << '\n';
      cin >> x;
      if (x == tmp[i]) {
        ans[i] = ans[i + 1] = tmp[i];
        cout << "? " << i + 2 << " " << i << " " << example[1 - tmp[i]] << '\n';
        cin >> ans[i + 2];
      } else {
        ans[i + 2] = tmp[i];
        cout << "? " << i + 2 << " " << i << " " << example[1 - tmp[i]] << '\n';
        cin >> ans[i];
        ans[i + 1] = 1 - ans[i];
      }
      cnt += 3 - (ans[i] + ans[i + 1] + ans[i + 2]);
    }
    cout << "! " << cnt;
    for (int i = 1; i <= n; i++)
      if (!ans[i]) cout << " " << i;
    cout << endl;
  }
  fflush(stdout);
}
