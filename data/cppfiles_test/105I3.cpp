#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node{
    int a,b,m;
    int ind,ans;
    int l,r;
};

bool intersect(pair<int,int> &seg, pair<int,int> a){
    int l = max(seg.first,a.first), r = min(seg.second,a.second);

    if(l<=r){
        seg = {l,r};
        return 1;
    }
    else{
        return 0;
    }
}

int solve(vector<node> &a, vector<int> &arr){
    int n = a.size(), ans = 0;

    sort(a.begin(),a.end(),[](node &p, node &q){
        return make_pair(p.l,p.r)<make_pair(q.l,q.r);
    });

    int la = 0;
    pair<int,int> seg(a[0].l,a[0].r);
    for(int i=1;i<n;i++){
        if(intersect(seg,make_pair(a[i].l,a[i].r))){
            continue;
        }
        else{
            ans++;
            for(int j=la;j<i;j++){
                a[j].ans = seg.first;
            }
            seg = {a[i].l,a[i].r};
            la = i;
        }
    }
    for(int i=la;i<n;i++){
        a[i].ans = a[i].a-seg.first;
        arr[a[i].ind] = a[i].ans;
    }
    ans++;
    return ans;
}

void test_case(){
    int n; cin >> n;
    vector<int> a(n),b(n),m(n);
    map<int,vector<node>> mp; 
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&a[i],&b[i],&m[i]);
        mp[a[i]+b[i]-m[i]].push_back({a[i],b[i],m[i],i,-1,a[i]-min(a[i],m[i]),a[i]-max(0,m[i]-b[i])});
    }

    vector<int> arr(n);
    int ans = 0;
    for(auto pr:mp){
        ans += solve(pr.second,arr);
    }

    cout << ans << endl;

    for(int i=0;i<n;i++){
        cout << arr[i] << " " << m[i]-arr[i] << endl;
    }
    return;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}