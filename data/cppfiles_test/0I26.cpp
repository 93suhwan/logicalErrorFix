#include <bits/stdc++.h>
using namespace std;
class md {
 public:
  int id, s1, s2;
};
bool px(md a, md b) {
  if (a.s1 == b.s1) {
    return a.s2 > b.s2;
  } else {
    return a.s1 < b.s1;
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  md a[n + 5];
  for (int i = 0; i < n; i++) {
    char s;
    cin >> s;
    a[i].s1 = s - '0';
    cin >> s;
    a[i].s2 = s - '0';
    a[i].id = i;
  }
  sort(a, a + n, px);
  for (int i = 0; i < n; i++) {
    cout << a[i].id + 1 << " ";
  }
  cout << endl;
  return 0;
}
