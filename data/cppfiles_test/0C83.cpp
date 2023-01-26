#include <bits/stdc++.h>
using namespace std;
struct Node {
  string data;
  int pos;
};
bool cmp(Node p1, Node p2) {
  string a = p1.data;
  string b = p2.data;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == b[i]) continue;
    if (i % 2 == 0) {
      if (a[i] < b[i]) return true;
      return false;
    } else {
      if (a[i] > b[i]) return true;
      return false;
    }
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<Node> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i].data;
    s[i].pos = i + 1;
  }
  sort(s.begin(), s.end(), cmp);
  for (int i = 0; i < n; i++) {
    cout << s[i].pos << ' ';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
