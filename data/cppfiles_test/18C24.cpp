#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, d;
    cin >> n >> d;
    long long a[n];
    long long i;
    queue<long long> q;
    bool visited[n];
    memset(visited, false, sizeof(visited));
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 0) {
        q.push(i);
        visited[i] = true;
      }
    }
    long long ans = 0;
    while (!q.empty()) {
      int sz = q.size();
      for (i = 0; i < sz; i++) {
        long long tp = q.front();
        q.pop();
        long long new_pos = (tp + d) % n;
        if (!visited[new_pos]) {
          q.push(new_pos);
          visited[new_pos] = true;
        }
      }
      ans++;
    }
    ans--;
    for (i = 0; i < n; i++) {
      if (!visited[i]) {
        ans = -1;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
