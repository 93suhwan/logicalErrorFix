#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define openr(a) freopen(a, "r", stdin)
#define openw(a) freopen(a, "w", stdout)
#define reset(a) memset(a, 0, sizeof(a))
#define read(v) for(auto &x: v) cin >> x;
#define all(a) a.begin(),a.end()
#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef signed long long int sll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef pair<sll, sll> sii;
typedef tuple<sll, sll, sll> siii;

#define ordered_set tree<ii, null_type,less<ii>, rb_tree_tag,tree_order_statistics_node_update>

const sll maxn= 1e6;
const sll inf= 1e9;
const sll MOD= inf + 7;

// knight moves
int xkt[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int ykt[] = {-1, 1, -2, 2, -2, 2, -1, 1};

// king moves
int xkg[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ykg[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// 4 directions
int dx[]= {0, 0, -1, 1};
int dy[]= {1, -1, 0, 0};
char dc[] = {'R', 'L', 'U', 'D'};

bool cmp(const ii &a, const ii &b){
    return a.first < b.first;
}

int main(){
    //openr("input.txt");
    //openw("output.txt");
    ios::sync_with_stdio(0), cin.tie(0);
    int tc; cin >> tc;
    while(tc--){
        set<ii> color;
        int n, k; cin >> n >> k;
        vector<int> vcolor(k+1, 0);
        vector<int> ans(n);
        vector<ii> v(n);
        for(int i= 1; i<= k; i++) color.insert(ii(0, i));
        for(int i= 0; i< n; i++){
            cin >> v[i].first;
            v[i].second= i;
        }
        sort(all(v), cmp);
        int i= 0;
        while(i< n){
            int j= i;
            int cnt= 1;
            while(v[i].first== v[j].first && j< n){
                if(cnt > k){
                    j++;
                    continue;
                }
                ii t= *color.begin();
                ans[v[j].second]= t.second;
                vcolor[t.second]++;
                color.erase(t);
                color.insert(ii(t.first+1, t.second));
                j++; cnt++;
            }
            i= j;
        }
        int mini= vcolor[1];
        for(int i= 1; i<= k; i++) mini= vcolor[i];
        for(auto &i: ans){
            if(vcolor[i] > mini){
                cout << 0 << " ";
                vcolor[i]--;
            }
            else cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
