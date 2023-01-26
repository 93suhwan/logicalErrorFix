#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a[N], tr[N];
vector<int> V;
int find(int x) {
  int l = 0, r = V.size() - 1;
  while (l < r) {
    int mid = l + r >> 1;
    if (V[mid] >= x)
      r = mid;
    else
      l = mid + 1;
  }
  return r + 1;
}
vector<int>::iterator unique(vector<int> &a) {
  int j = 0;
  for (int i = 0; i < a.size(); i++)
    if (!i || a[i] != a[i - 1]) a[j++] = a[i];
  return a.begin() + j;
}
inline int lowbit(int x) { return x & -x; }
void add(int x, int y) {
  for (; x <= n; x += lowbit(x)) tr[x] += y;
}
int calPre(int x) {
  int ans = 0;
  for (; x; x -= lowbit(x)) ans += tr[x];
  return ans;
}
int calMin(int x) {
  x = find(x);
  add(x, 1);
  return min(calPre(x - 1), calPre(n) - calPre(x));
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    V.clear();
    memset(tr, 0, sizeof tr);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      V.push_back(a[i]);
    }
    sort(V.begin(), V.end());
    V.erase(unique(V), V.end());
    int res = 0;
    for (int i = 0; i < n; i++) res += calMin(a[i]);
    cout << res << endl;
  }
  return 0;
}
