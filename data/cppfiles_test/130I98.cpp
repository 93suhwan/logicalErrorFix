#include <bits/stdc++.h>
using namespace std;
int query(int a, int b, int c) {
  cout << "? " << ' ' << a << ' ' << b << ' ' << c << endl;
  int r;
  cin >> r;
  return r;
}
void output(set<int> imp) {
  cout << "!";
  cout << " " << imp.size();
  for (int i : imp) {
    cout << ' ' << i;
  }
  cout << endl;
}
void solve() {
  int n;
  cin >> n;
  tuple<int, int, int> cm, im;
  vector<int> A(n + 5);
  for (int i = 1; i <= n; i += 3) {
    int r;
    r = query(i, i + 1, i + 2);
    if (r == 0) {
      im = {i, i + 1, i + 2};
    } else {
      cm = {i, i + 1, i + 2};
    }
    A[i] = r;
  }
  int C, I, k;
  int a, b, c, x, y, z;
  tie(a, b, c) = cm;
  tie(x, y, z) = im;
  k = 0;
  for (int w : {x, y, z}) {
    k += query(a, b, w);
  }
  if (k <= 1) {
    C = c;
  } else {
    C = a;
  }
  k = 0;
  for (int w : {a, b, c}) {
    k += query(x, y, w);
  }
  if (k >= 2) {
    I = z;
  } else {
    I = x;
  }
  set<int> ans;
  ans.insert(I);
  for (int i = 1; i <= n; i += 3) {
    int a = i, b = i + 1, c = i + 2;
    if (A[i] == 0) {
      if (C == a) {
        ans.insert(b);
        ans.insert(c);
      } else if (C == b) {
        ans.insert(a);
        ans.insert(c);
      } else if (C == c) {
        ans.insert(a);
        ans.insert(b);
      } else {
        int r = query(a, b, C);
        if (r == 1) {
          ans.insert(c);
          if (a == I) {
            ans.insert(a);
          } else {
            if (query(a, I, C)) {
              ans.insert(b);
            }
          }
        } else {
          ans.insert(a);
          ans.insert(b);
          if (c == I) {
            ans.insert(c);
          } else {
            if (query(c, I, C) == 0) {
              ans.insert(c);
            }
          }
        }
      }
    }
    if (A[i] == 1) {
      if (I == a) {
        ans.insert(a);
      } else if (I == b) {
        ans.insert(b);
      } else if (I == c) {
        ans.insert(c);
      } else {
        int r = query(a, b, I);
        if (r == 1) {
          if (query(c, C, I) == 0) {
            ans.insert(c);
          }
        } else {
          if (query(a, I, C)) {
            ans.insert(b);
          } else {
            ans.insert(a);
          }
        }
      }
    }
  }
  output(ans);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
