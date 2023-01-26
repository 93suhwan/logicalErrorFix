#include <bits/stdc++.h>
using namespace std;
const int N = 8;
int a[N][N + 2], b[N];
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    int flag = 0, sz1 = a.size(), sz2 = b.size();
    for (int i = 0; i < sz1 && flag == 0; i++) {
      if (i + 1 >= sz2 && a[i] == b[0]) {
        int j = 0, k = i, cnt = 0;
        while (k >= 0 && j < sz2 && a[k] == b[j]) {
          k--;
          j++;
          cnt++;
        }
        if (cnt == sz2) {
          flag = 1;
          break;
        }
      }
      if (a[i] == b[0]) {
        int j = 0, k = i, cnt = 0;
        while (j < sz2 && k < sz1 && b[j] == a[k]) {
          int l = j, m = k, tcnt = cnt;
          while (m >= 0 && l < sz2 && a[m] == b[l]) {
            m--;
            l++;
            tcnt++;
          }
          if (tcnt == sz2) {
            flag = 1;
            break;
          }
          j++;
          k++;
          cnt++;
        }
        if (cnt == sz2) {
          flag = 1;
          break;
        }
        if (b[j] != a[k]) {
          k--, j++;
          while (j < sz2 && k < sz1 && b[j] == a[k]) {
            k--;
            j++;
            cnt++;
          }
          if (cnt == sz2) {
            flag = 1;
          }
        }
      }
    }
    if (flag) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
