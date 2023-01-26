#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int maxn = 1e5 + 10;
const int mod = 998244353;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n + 1, 0), r(n + 1, 1), l(n + 1, 1);
  for (int i = 1; i <= n; i++) l[i] = i, r[i] = i, scanf("%d", &a[i]);
  for (int i = 2; i <= n; i++)
    if (a[i - 1] > a[i]) l[i] = l[i - 1];
  for (int i = n - 1; i >= 1; i--)
    if (a[i] < a[i + 1]) r[i] = r[i + 1];
  int flag = 0;
  int i = 1, j = n;
  int MIN = -1;
  while (i <= j) {
    if (a[i] == a[j]) {
      int tmp = (min(j, r[i]) - i + 1) % 2;
      tmp |= (j - max(i, l[j]) + 1) % 2;
      if (tmp) {
        if (!flag)
          cout << "Alice" << endl;
        else {
          cout << "Bob" << endl;
        }
        return 0;
      }
      if (flag)
        cout << "Alice" << endl;
      else
        cout << "Bob" << endl;
      return 0;
    } else if (a[i] > a[j]) {
      int tmp = (min(j, r[i]) - i + 1) % 2;
      if (tmp) {
        if (!flag)
          cout << "Alice" << endl;
        else {
          cout << "Bob" << endl;
        }
        return 0;
      } else {
        if (a[j] > MIN) {
          MIN = a[j];
          j--;
        } else {
          if (flag)
            cout << "Alice" << endl;
          else
            cout << "Bob" << endl;
          return 0;
        }
      }
    } else {
      int tmp = (j - max(i, l[j]) + 1) % 2;
      if (tmp) {
        if (!flag)
          cout << "Alice" << endl;
        else {
          cout << "Bob" << endl;
        }
        return 0;
      } else {
        if (a[i] > MIN) {
          MIN = a[i];
          i++;
        } else {
          if (flag)
            cout << "Alice" << endl;
          else
            cout << "Bob" << endl;
          return 0;
        }
      }
    }
    flag ^= 1;
  }
  return 0;
}
