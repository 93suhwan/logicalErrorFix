#include <bits/stdc++.h>
using namespace std;


//#define int long long 


const int N = 4e5 + 10;


struct DSU{
     vector <int> p, sz;
     DSU(int n = 0) : p(n + 1), sz(n + 1, 1) {
         for(int i = 1; i <= n; i++) p[i] = i;
     }
     int find(int x) {
         return (p[x] ^ x) ? (p[x] = find(p[x])) : p[x];
     }
     int operator [](int x) {
        return find(x);
     }
     int merge(int x, int y) {
         if((x = find(x)) ^ (y = find(y))) p[x] = y, sz[y] += sz[x];
         return x ^ y;
     }
}; 


using LL = long long;



LL a[N], b[N], cnt[N], ans[N];



LL final_ans[N];



#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 


  
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 


ordered_set ost[N];



void print(ordered_set &A) {
    for(int x: A) 
        cout << x << " ";
    cout << endl;
}


LL Merge(ordered_set &A, ordered_set &B, int cnt_a, int cnt_b, LL score_a, LL score_b) {
    if(A.size() > B.size()) {
        swap(A, B);
        swap(cnt_b, cnt_a);
        swap(score_b, score_a);
    }


    LL cur_ans = score_b;

    for(auto x: A) {
        int len = B.size();
        int y = *B.find_by_order(len - cnt_b);
        if(x >= y) {
            cur_ans += x - y;
        }
        B.insert(x);
        /*cout << len - cnt_b << " " << cur_ans << endl;*/
    }

    for(int i = 1; i <= cnt_a; i++) {
        int len = B.size();
        cur_ans += *B.find_by_order(len - cnt_b - i);
    }

    A.clear();

    return cur_ans;
}



int32_t main() {
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    

    int n, m, q; cin >> n >> m >> q;


    vector <pair <int, int>> v;


    long long cur_ans = 0;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        v.push_back(make_pair(a[i], i));
        cur_ans += a[i];
        cnt[i]++;
        ans[i] += a[i];

        ost[i].insert(a[i]);
    }

    for(int i = 1; i <= m; i++) {
        cin >> b[i];
        v.push_back(make_pair(b[i], i + n));
        ost[i + n].insert(b[i]);
    }


    sort(v.begin(), v.end());

    DSU dsu(n + m);


    vector <tuple <int, int, int>> t;

    for(int i = 0; i < n + m - 1; i++) {
        auto [x1, i1] = v[i];
        auto [x2, i2] = v[i + 1];
        t.push_back(make_tuple(x2 - x1, i1, i2));
    }

    sort(t.begin(), t.end(), greater <tuple <int, int, int>>());


    vector <pair <int, int>> Q;

    for(int i = 1; i <= q; i++) {
        int k; cin >> k;
        Q.push_back(make_pair(k, i));
    }


    sort(Q.begin(), Q.end());


    for(auto [k, idx]: Q) {
        while(t.size() and get<0>(t.back()) <= k) {
            auto [xx, i1, i2] = t.back(); t.pop_back();

            i1 = dsu[i1];
            i2 = dsu[i2];

            if(i1 != i2) {


                if(ost[i1].size() > ost[i2].size()) swap(i1, i2);

                dsu.merge(i1, i2);

                cur_ans -= (ans[i1] + ans[i2]);

                ans[i2] = Merge(ost[i1], ost[i2], cnt[i1], cnt[i2], ans[i1], ans[i2]);
                cnt[i2] += cnt[i1];
                cur_ans += ans[i2];
            }
        }

        final_ans[idx] = cur_ans;
    }

    for(int i = 1; i <= q; i++) cout << final_ans[i] << endl;



}