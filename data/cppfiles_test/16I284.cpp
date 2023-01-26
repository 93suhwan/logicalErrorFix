#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
pair<int, int> a[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    vector<pair<int, pair<int, int>>> v;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      int temp;
      scanf("%d", &temp);
      a[i] = {temp, i};
    }
    sort(a + 1, a + 1 + n);
    for (int i = n; i >= 1; i--) {
      if (a[i].first == 0) continue;
      for (int j = i - 1; j >= 1; j--) {
        if (a[i].first == 0) break;
        if (a[j].first == 0) continue;
        if (a[i] >= a[j]) {
          int temp = a[j].first;
          a[i].first -= temp;
          a[j].first -= temp;
          v.push_back({temp, {a[i].second, a[j].second}});
        } else {
          int temp = a[i].first;
          a[i].first -= temp;
          a[j].first -= temp;
          v.push_back({temp, {a[i].second, a[j].second}});
        }
      }
    }
    int SIZE = 0;
    for (int i = 0; i < v.size(); i++) {
      SIZE += v[i].first;
    }
    cout << SIZE << endl;
    for (int i = 0; i < v.size(); i++)
      for (int j = 0; j < v[i].first; j++) {
        cout << v[i].second.first << " " << v[i].second.second << endl;
      }
  }
  return 0;
}
