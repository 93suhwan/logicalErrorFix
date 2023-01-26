#include <bits/stdc++.h>
using namespace std;
const long long N = 60;
const long long M = 1e7;
long long t;
char s[N];
long long n;
long long visit[M + 10];
class node {
 public:
  long long num;
  long long len;
  long long pos;
};
queue<node> q;
signed main() {
  visit[1] = 1;
  for (long long i = 2; i <= M; i++) {
    if (!visit[i])
      for (long long j = i * i; j <= M; j += i) {
        visit[j] = 1;
      }
  }
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s + 1;
    while (!q.empty()) q.pop();
    bool flag = 0;
    for (long long i = 1; i <= n; i++) {
      if (s[i] == '9' || (s[i] != '2' && ((s[i] - '0') % 2) == 0)) {
        cout << 1 << endl;
        cout << s[i] << endl;
        flag = 1;
        break;
      }
      node tn;
      tn.pos = i;
      tn.len = 1;
      tn.num = s[i] - '0';
      q.push(tn);
    }
    if (flag) continue;
    while (!q.empty()) {
      long long temp = q.front().num;
      long long pos = q.front().pos;
      long long len = q.front().len;
      if (visit[temp]) {
        cout << len << endl;
        cout << temp << endl;
        break;
      }
      for (long long i = pos + 1; i <= n; i++) {
        node tn = q.front();
        tn.len++;
        tn.num *= 10;
        tn.num += s[i] - '0';
        tn.pos = i;
        q.push(tn);
      }
      q.pop();
    }
  }
  return 0;
}
