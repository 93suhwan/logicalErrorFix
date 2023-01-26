#include <bits/stdc++.h>
using namespace std;
struct node {
  int now;
  int val;
} a[100005], b[100005];
bool cmp(node x, node y) { return x.val > y.val; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    int mark[100005] = {0};
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      a[i].now = b[i].now = a[i].val = b[i].val = 0;
    }
    for (int i = 1; i <= n; ++i) {
      cin >> a[i].val;
      a[i].now = i;
    }
    for (int i = 1; i <= n; ++i) {
      cin >> b[i].val;
      b[i].now = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    sort(b + 1, b + 1 + n, cmp);
    set<int> st;
    for (int i = 1; i <= n; ++i) {
      st.insert(a[i].now);
      st.insert(b[i].now);
      mark[a[i].now] = 1;
      mark[b[i].now] = 1;
      if (st.size() == i) {
        break;
      }
    }
    for (int i = 1; i <= n; ++i) {
      cout << mark[i];
    }
    cout << "\n";
  }
  return 0;
}
