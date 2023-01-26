#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 10;
double eps = 1e-8;
struct Node {
  int val, num;
  Node() {
    val = 0;
    num = 0;
  }
};
bool operator<(Node a, Node b) { return a.val > b.val; }
int a[200005];
int l = 1, r = 1;
string ans[] = {"Alice", "Bob"};
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 2; i <= n; i++)
    if (a[i - 1] < a[i])
      l++;
    else
      break;
  for (int i = n; i >= 2; i--)
    if (a[i] < a[i - 1])
      r++;
    else
      break;
  int i = 1, j = n;
  int k = 1;
  while (1) {
    if (l == 0) {
      if (r % 2 == 1)
        cout << ans[(k - 1) % 2] << endl;
      else
        cout << ans[k % 2] << endl;
      return 0;
    }
    if (r == 0) {
      if (l % 2 == 1)
        cout << ans[(k - 1) % 2] << endl;
      else
        cout << ans[k % 2] << endl;
      return 0;
    }
    if ((a[i] > a[j] && l % 2 == 1) || (a[i] < a[j] && r % 2 == 1)) {
      cout << ans[(k - 1) % 2] << endl;
      return 0;
    }
    if (a[i] == a[j] && (l % 2 == 1 || r % 2 == 1)) {
      cout << ans[(k - 1) % 2] << endl;
      return 0;
    }
    if (a[i] > a[j])
      j--, r--;
    else if (a[i] <= a[j])
      i++, l--;
    k++;
  }
  return 0;
}
