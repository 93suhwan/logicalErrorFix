#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool mnto(T& a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
inline bool mxto(T& a, T b) {
  return a < b ? a = b, 1 : 0;
}
int t;
int a, b;
vector<int> ans;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &a, &b);
    int n = a + b;
    ans.clear();
    for (int i = 0; i < a + 1; i++) {
      int k = 2 * i + n / 2 - a;
      if (k < 0 || k > n) continue;
      ans.push_back(k);
      if (n % 2 == 1) {
        ans.push_back(n - k);
      }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for (int i : ans) {
      printf("%d ", i);
    }
    printf("\n");
  }
  return 0;
}
