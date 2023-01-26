#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
priority_queue<long long int, vector<long long int>, greater<long long int> >
    san;
bool sortBysec(pair<long long int, long long int> a,
               pair<long long int, long long int> b) {
  return a.second < b.second;
}
bool sortbysecTuple(const tuple<int, int, int>& a,
                    const tuple<int, int, int>& b) {
  return (get<1>(a) < get<1>(b));
}
long long int bigMod(long long int a, long long int n, long long int m) {
  long long int res = 1;
  while (n) {
    if (n % 2 == 1) {
      res = (res * a) % m;
      n--;
    } else {
      a = (a * a) % m;
      n = n / 2;
    }
  }
  return res;
}
long long int power(long long int n, long long int m) {
  long long int ans = 1;
  while (m) {
    ans *= n;
    m--;
  }
  return ans;
}
long long int tree[3 * 200005];
long long int query(long long int node, long long int b, long long int e,
                    long long int i, long long int j) {
  if (i > e || j < b) {
    return 0;
  }
  if (b >= i && e <= j) return tree[node];
  long long int l = 2 * node;
  long long int r = l + 1;
  long long int m = (b + e) / 2;
  long long int x1 = query(l, b, m, i, j);
  long long int x2 = query(r, m + 1, e, i, j);
  return x1 + x2;
}
void update(long long int node, long long int b, long long int e,
            long long int i, long long int newval) {
  if (i > e || i < b) return;
  if (b >= i && e <= i) {
    tree[node] += newval;
    return;
  }
  long long int l = 2 * node;
  long long int r = l + 1;
  long long int m = (b + e) / 2;
  update(l, b, m, i, newval);
  update(r, m + 1, e, i, newval);
  tree[node] = tree[l] + tree[r];
}
long long int uniquePathsWithObstacles(long long int ara[], long long int n,
                                       long long int m) {
  long long int path[n + 1][m + 1];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1, i = 0, n, m, j, l, k, x, y, z, d, a, h, w, b, c, p, e, q,
                tt = 0, r;
  while (t--) {
    cin >> n >> m;
    vector<long long int> ans;
    vector<long long int> let[26];
    string s[n + 5];
    for (i = 1; i <= n; i++) {
      cin >> s[i];
      ans.push_back(i);
    }
    for (i = m - 1; i >= 0; i--) {
      for (j = 0; j < 26; j++) {
        let[j].clear();
      }
      for (j = 1; j <= n; j++) {
        p = ans[j - 1];
        x = s[p][i] - 'A';
        let[x].push_back(ans[j - 1]);
      }
      ans.clear();
      if (i % 2 == 0) {
        for (j = 0; j <= 25; j++) {
          for (k = 0; k < let[j].size(); k++) {
            ans.push_back(let[j][k]);
          }
        }
      } else {
        for (j = 25; j >= 0; j--) {
          for (k = 0; k < let[j].size(); k++) {
            ans.push_back(let[j][k]);
          }
        }
      }
    }
    for (i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
