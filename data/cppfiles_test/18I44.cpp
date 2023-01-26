#include <bits/stdc++.h>
using namespace std;
class Line {
 public:
  int a, b;
  Line() {}
  Line(int a_, int b_) {
    if (a_ > b_) {
      b = a_;
      a = b_;
    } else {
      a = a_;
      b = b_;
    }
  }
  bool within(int a, int b, int c) {
    return (a < c && c < b) || (b < c && c < a);
  }
  bool intersect(const Line& other) {
    if (within(a, b, other.a) && !within(a, b, other.b)) return true;
    if (within(a, b, other.b) && !within(a, b, other.a)) return true;
    return false;
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    Line lines[n];
    bool taken[2 * n];
    for (int i = 0; i < k; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      lines[i] = Line(a, b);
      taken[a] = true;
      taken[b] = true;
    }
    vector<int> pos;
    for (int i = 0; i < 2 * n; i++)
      if (!taken[i]) pos.push_back(i);
    for (int i = 0; i < n - k; i++) {
      lines[i + k] = Line(pos[i], pos[i + n - k]);
    }
    int intersect = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (lines[i].intersect(lines[j])) intersect++;
      }
    }
    cout << intersect << '\n';
  }
}
