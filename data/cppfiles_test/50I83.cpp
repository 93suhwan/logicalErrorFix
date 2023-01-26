/*   author:  LiZnB
     created: 13.12.2021 00:45:31
_________     _________    ________                                
 __  ____/___________  /_______  __/_______________________________ 
 _  /    _  __ \  __  /_  _ \_  /_ _  __ \_  ___/  ___/  _ \_  ___/ 
 / /___  / /_/ / /_/ / /  __/  __/ / /_/ /  /   / /__ /  __/(__  )  
 \____/  \____/\__,_/  \___//_/    \____//_/    \___/ \___//____/   
*/

#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Node {
    int l, r;
    mutable int val;
    Node(const int &a, const int &b, const int &c) : l(a), r(b), val(c) {}
    bool operator < (const Node & oth) const {
        return l < oth.l;
    }
};
const int N = 2e5 + 10;

const int MOD = 998244353;
struct ODT {
    
    set<Node> odt;
    ODT() {
      odt.insert((Node){1, 2000000000, 0});
    }

    auto split(int x) { // n 可以考虑去掉，让ODT可以处理大区间
        auto it = --odt.upper_bound((Node) {x, 0, 0});
        if (it->l == x) return it;
        int l = it->l, r = it -> r, val = it->val;
        odt.erase(it);
        odt.insert((Node) {l, x - 1, val});
        return odt.insert((Node) {x, r, val}).first;
    }

    void assign(int l, int r, int val) {
        auto itr = split(r + 1);  // 必须先右后左, 因为split右端点会让已经split的左端点失效
        auto itl = split(l);
        odt.erase(itl, itr);
        odt.insert((Node) {l, r, val});
    }
    int sum (int l, int r) {
        auto itr = split(r + 1);  // 必须先右后左, 因为split右端点会让已经split的左端点失效
        auto itl = split(l);
        int res = 0;
        while (itl != itr) {
          res += ((itl->val) * (itl->r - itl->l + 1)) % MOD;
          res %= MOD;
          itl++;
        }
        return res;
    }
    void dp1(int l, int r, int sum) {
        auto itr = split(r + 1);  // 必须先右后左, 因为split右端点会让已经split的左端点失效
        auto itl = split(l);
        while (itl != itr) {
          itl->val *= -1;
          itl->val = (itl->val + sum + MOD) % MOD;
          itl++;
        }
    }
} f[N];


signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  f[1].assign(1, a[1], 1);
  for (int i = 2; i <= n; i++) {
    if (a[i - 1] >= a[i]) {
      f[i] = f[i - 1];
      f[i].dp1(1, a[i], f[i - 1].sum(1, 1000000000ll));
    } else if (a[i - 1] < a[i]) {
      f[i] = f[i - 1];
      f[i].assign(a[i - 1] + 1, a[i], f[i - 1].sum(1, a[i - 1]));
      f[i].dp1(1, a[i - 1], f[i - 1].sum(1, 1000000000ll));
    } 
  }
  cout << f[n].sum(1, 1e9);
  return 0;
}


