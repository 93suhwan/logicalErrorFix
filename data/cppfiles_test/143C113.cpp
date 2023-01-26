#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, a[200005], ldon;
    map<int, int> m;
    deque<int> dq;
    long long sum = 0;
    bool possible = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]]++;
    }
    sort(a, a + n);
    for (int i = 0; i < n + 1; i++) {
      if (!possible) {
        cout << -1 << " ";
      } else {
        cout << m[i] + sum << " ";
        if (m[i] == 0) {
          if (!dq.empty()) {
            sum += i - (*dq.rbegin());
            m[*(dq.rbegin())]--;
            if (m[*(dq.rbegin())] == 1) dq.pop_back();
          } else
            possible = 0;
        } else if (m[i] > 1)
          dq.push_back(i);
      }
    }
    cout << "\n";
  }
  return 0;
}
