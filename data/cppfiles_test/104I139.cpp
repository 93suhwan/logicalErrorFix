#include <bits/stdc++.h>
using namespace std;
int a[200001];
void op(int i) {
  int res = a[i] ^ a[i + 1] ^ a[i + 2];
  a[i] = a[i + 1] = a[i + 2] = res;
}
vector<int> push_left(int i) {
  vector<int> v;
  while (a[i] == 0 && a[i - 1] == 1 && a[i - 2] == 1) {
    op(i - 2);
    v.push_back(i - 2);
    i -= 2;
  }
  return v;
}
vector<int> push_right(int i, int n) {
  vector<int> v;
  while (i + 2 <= n && a[i] == 0 && a[i + 1] == 1 && a[i + 2] == 1) {
    op(i);
    v.push_back(i);
    i += 2;
  }
  return v;
}
int main() {
  int i, t;
  for (scanf("%d", &t); t--;) {
    int n;
    vector<int> v, ans;
    int cum = 0;
    for (scanf("%d", &n), i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      cum += a[i];
    }
    if (cum == 0) {
      printf("YES\n0\n");
      continue;
    } else if ((cum & 1) || cum == n) {
      printf("NO\n");
      continue;
    }
    int stk = 1;
    int last = a[1];
    for (i = 2; i <= n; ++i) {
      if (last != a[i]) {
        if (last == 0) stk = -stk;
        v.push_back(stk);
        stk = 1;
        last = a[i];
      } else
        ++stk;
    }
    if (last == 0) stk = -stk;
    v.push_back(stk);
    bool y = 1;
    int ix = 1;
    int l = -1, r = -1;
    int left, right;
    for (i = 0; y && i < v.size(); ++i) {
      if (v[i] > 0) {
        if (v[i] & 1) {
          if (l < 0) {
            l = i;
            left = ix;
          } else {
            r = i;
            right = ix;
            int num = 0;
            int b = 0;
            for (int j = l + 1; j < r; ++j) b += abs(v[j]);
            if (b & 1) {
              int cur = left + v[l];
              while (cur < right) {
                while (a[cur + 1] == 0) {
                  op(cur - 1);
                  ans.push_back(cur - 1);
                  cur += 2;
                }
                op(cur - 1);
                ans.push_back(cur - 1);
                auto push_vec = push_left(cur - 1);
                ans.insert(ans.end(), push_vec.begin(), push_vec.end());
                push_vec = push_right(cur + 1, n);
                ans.insert(ans.end(), push_vec.begin(), push_vec.end());
                cur += 3;
                cur = max(cur, ans.back() + 4);
              }
            } else {
              if (l == 0 && r + 1 == v.size())
                y = 0;
              else {
                int cur = left + v[l];
                while (cur + 1 < right + v[r]) {
                  if (a[cur] + a[cur + 1] == 0) {
                    op(cur - 1);
                    ans.push_back(cur - 1);
                  }
                  cur += 2;
                }
                if (l > 0) {
                  cur = left - 1;
                  auto push_vec = push_right(cur, n);
                  ans.insert(ans.end(), push_vec.begin(), push_vec.end());
                } else {
                  cur = right + v[r];
                  auto push_vec = push_left(cur);
                  ans.insert(ans.end(), push_vec.begin(), push_vec.end());
                }
              }
            }
            l = -1;
          }
        } else {
          if (l < 0) {
            if (i + 1 < v.size()) {
              int pick = ix + v[i] - 2;
              for (int done = 0; done < v[i]; done += 2) {
                ans.push_back(pick);
                op(pick);
                pick -= 2;
              }
            } else if (i > 0) {
              int pick = ix - 1;
              for (int done = 0; done < v[i]; done += 2) {
                ans.push_back(pick);
                op(pick);
                pick += 2;
              }
            } else
              y = 0;
          }
        }
        ix += v[i];
      } else
        ix -= v[i];
    }
    cum = 0;
    for (i = 1; i <= n; ++i) cum += a[i];
    if (cum) y = 0;
    if (y) {
      printf("YES\n%d\n", ans.size());
      for (auto x : ans) printf("%d ", x);
      puts("");
    } else
      printf("NO\n");
  }
  return 0;
}
