#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test;
  cin >> test;
  for (int t = 0; t < test; t++) {
    priority_queue<int> pq;
    int n, k;
    cin >> n >> k;
    int num;
    int answer = 0;
    for (int i = 0; i < n; i++) {
      cin >> num;
      pq.push(num);
    }
    for (int i = 0; i < k; i++) {
      int a, b;
      a = pq.top();
      pq.pop();
      b = pq.top();
      pq.pop();
      if (a >= b) {
        answer += b / a;
      } else {
        answer += a / b;
      }
    }
    while (!pq.empty()) {
      num = pq.top();
      answer += num;
      pq.pop();
    }
    cout << answer << "\n";
  }
  return 0;
}
