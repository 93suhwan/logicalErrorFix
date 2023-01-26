#include <bits/stdc++.h>
using namespace std;
int query(int a, int b, int c) {
  cout << "? " << ' ' << a << ' ' << b << ' ' << c << endl;
  int r;
  cin >> r;
  return r;
}
void output(set<int> imp) {
  cout << "! ";
  cout << imp.size();
  for (int i : imp) {
    cout << ' ' << i;
  }
  cout << endl;
}
void solve() {
  int n, q = 0;
  cin >> n;
  int a, b, c, x, y, z, C, I, k;
  vector<int> A(n + 1);
  for (int i = 1; i <= n; i += 3) {
    A[i] = query(i, i + 1, i + 2);
    q++;
    if (A[i]) {
      tie(a, b, c) = make_tuple(i, i + 1, i + 2);
    } else {
      tie(x, y, z) = make_tuple(i, i + 1, i + 2);
    }
  }
  k = 0;
  for (int w : {x, y, z}) {
    k += query(a, b, w);
    q++;
  }
  if (k == 3) {
    C = a;
  } else {
    C = c;
  }
  k = 0;
  for (int w : {a, b, c}) {
    k += query(x, y, w);
    q++;
  }
  if (k == 0) {
    I = x;
  } else {
    I = z;
  }
  set<int> ans;
  ans.insert(I);
  for (int i = 1; i <= n; i += 3) {
    a = i, b = i + 1, c = i + 2;
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
        q++;
        if (query(a, b, C)) {
          ans.insert(c);
          if (a == I) {
            ans.insert(a);
          } else {
            q++;
            if (query(a, I, C)) {
              ans.insert(b);
            } else {
              ans.insert(a);
            }
          }
        } else {
          ans.insert(a);
          ans.insert(b);
          if (c == I) {
            ans.insert(c);
          } else {
            q++;
            if (query(c, I, C) == 0) {
              ans.insert(c);
            }
          }
        }
      }
    } else {
      if (I == a) {
        ans.insert(a);
      } else if (I == b) {
        ans.insert(b);
      } else if (I == c) {
        ans.insert(c);
      } else {
        q++;
        if (query(a, b, I)) {
          q++;
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
  assert(q <= n + 6);
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
