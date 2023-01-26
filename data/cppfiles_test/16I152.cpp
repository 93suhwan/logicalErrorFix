#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long mn = 0, cnt = 0;
    priority_queue<char> pq;
    pq.push(s[0]);
    for (int i = 1; i < n; i++) {
      if (s[i] < pq.top()) cnt++;
      pq.push(s[i]);
    }
    if (cnt) cnt++;
    cout << cnt << "\n";
  }
  return 0;
}
