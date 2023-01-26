/*
 * File created on 12/11/2021 at 16:51:26.
 * Link to problem: 
 * Description: 
 * Time complexity: O()
 * Space complexity: O()
 * Status: ---
 * Copyright: Ⓒ 2021 Francois Vogel
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

using namespace std;
using namespace __gnu_pbds;

#define mp pair<pii, int>
#define pii pair<int, int>
#define f first
#define s second

#define vi vector<int>
#define all(x) x.begin(), x.end()
#define size(x) (int)((x).size())
#define pb push_back
#define ins insert
#define cls clear

#define ll long long
#define ld long double

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int p2 = 1<<17;

struct Segtree {
    Segtree() {
        t = new int [p2*2];
        for (int i = 0; i < p2*2; i++) t[i] = 0;
    }
    void add(int x) {
        for (x += p2; x; x /= 2) t[x]++;
    }
    int get(int b, int e) {
        b += p2;
        e += p2;
        int r = 0;
        while (b <= e) {
            if (b%2 == 1) r += t[b++];
            if (e%2 == 0) r += t[e--];
            b /= 2;
            e /= 2;
        }
        return r;
    }
    int* t;
};

int get2(vector<mp> b) {
    int n = size(b);
    set<int> se;
    for (mp i : b) se.ins(i.f.s);
    map<int, int> compress;
    int k = 0;
    for (int i : se) compress[i] = k++;
    for (int i = 0; i < n; i++) b[i].f.s = compress[b[i].f.s];
    sort(all(b));
    int tot0 = 0;
    for (mp i : b) if (i.s == 0) tot0++;
    Segtree st [3];
    for (int i = 0; i < 3; i++) st[i] = Segtree();
    int res = 0;
    int till = 0;
    for (int i = 0; i < size(se); i++) {
        while (till < n && b[till].f.f <= i) {
            st[b[till].s].add(b[till].f.s);
            till++;
        }
        int cut = 0;
        for (int j = (1<<17); j; j /= 2) {
            int typ1 = st[1].get(0, cut);
            int typ2 = st[2].get(cut+1, size(se)-1);
            if (typ1 == typ2) break;
            else if (typ1 > typ2) {
                cut -= j;
                cut = max(0, cut);
            }
            else { // tup1 < typ2
                cut += j;
                cut = min(size(se)-1, cut);
            }
        }
        int typ0 = tot0-st[0].get(0, p2-1);
        int typ1 = st[1].get(0, cut);
        int typ2 = st[2].get(cut+1, size(se)-1);
        int loc = min(min(typ0, typ1), typ2);
        res = max(res, loc);
    }
    return res;
}

int get(vector<mp> b) {
    int n = size(b);
    set<int> se;
    for (int i = 0; i < n; i++) se.ins(b[i].f.f);
    map<int, int> compress;
    int k = 0;
    for (int i : se) compress[i] = k++;
    for (int i = 0; i < n; i++) b[i].f.f = compress[b[i].f.f];
    Segtree st [3];
    for (int i = 0; i < 3; i++) st[i] = Segtree();
    for (mp i : b) st[i.s].add(i.f.f);
    int start = 0;
    int end = 1;
    int res = 0;
    while (start < size(se) && end < size(se)) {
        if (end < size(se)-1 && min(st[1].get(start+1, end+1), st[2].get(end+2, size(se)-1)) >= min(st[1].get(start+1, end), st[2].get(end+1, size(se)-1))) {
            end++;
        }
        else {
            start++;
        }
        int loc = min(min(st[0].get(0, start), st[1].get(start+1, end)), st[2].get(end+1, size(se)-1));
        res = max(res, loc);
    }
    int res2 = get2(b);
    return max(res, res2);
}

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<mp> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i].f.f >> b[i].f.s >> b[i].s;
        b[i].s--;
    }
    int res = 0;
    vi perm = {0, 1, 2};
    do {
        vi undo(3);
        for (int i = 0; i < 3; i++) undo[perm[i]] = i;
        for (int i = 0; i < n; i++) b[i].s = perm[b[i].s];
        int l1 = get(b);
        for (int i = 0; i < n; i++) swap(b[i].f.f, b[i].f.s);
        int l2 = get(b);
        for (int i = 0; i < n; i++) swap(b[i].f.f, b[i].f.s);
        res = max(res, max(l1, l2));
        for (int i = 0; i < n; i++) b[i].s = undo[b[i].s];
    } while (next_permutation(all(perm)));
    cout << res*3;

    cout.flush();
    int d = 0;
    d++;
}