#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define int long long

typedef
tree<
pair<int,int>,
null_type,
greater<pair<int,int>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

struct Q{
    int l,k,idx;
    Q(){}
    Q(int _l,int _k,int _idx){
        l=_l;
        k=_k;
        idx=_idx;
    }
};
void add(ordered_set&s, int x,map<int,int>&mp){
    auto it=mp.find(x);
    if(it!=mp.end()){
        s.erase(s.find_by_order(s.order_of_key({it->first,it->second})));
        s.insert({it->first,it->second+1});
        it->second++;
    }
    else{
        s.insert({x,1});
        mp.insert({x,1});
    }
}
void rem(ordered_set&s, int x,map<int,int>&mp){
    auto it=mp.find(x);
    if(it!=mp.end()){
        s.erase(s.find_by_order(s.order_of_key({it->first,it->second})));
        if(it->second>1){
            s.insert({it->first,it->second-1});
            it->second--;
        }
        else{
            mp.erase(it);
        }
    }
    else{
        assert(0);
    }
}
void dfs(int he,int pa, vector<vector<int>>&gr, vector<int>&a, vector<int>&ans, vector<vector<Q>>&qry, ordered_set&s,map<int,int>&mp){
    add(s,a[he],mp);
    for(auto q:qry[he]){
        int n=s.size();
        int l=q.l;
        int k=q.k;
        int idx=q.idx;
        if(k>n){
            ans[idx]=-1;
        }
        else{
            pair<int,int>p=*s.find_by_order(k-1);
            if(p.second<l) ans[idx]=-1;
            else ans[idx]=p.first+1;
        }
    }
    for(auto x:gr[he]){
        if(x!=pa){
            dfs(x,he,gr,a,ans,qry,s,mp);
        }
    }
    rem(s,a[he],mp);
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vector<vector<int>>gr(n);
        for(int i=1;i<n;i++){
            int x;
            cin>>x;
            --x;
            gr[x].push_back(i);
            gr[i].push_back(x);
        }
        vector<int>ans(n);
        vector<vector<Q>>qry(n);
        for(int i=0;i<q;i++){
            int v,l,k;
            cin>>v>>l>>k;
            --v;
            qry[v].push_back(Q(l,k,i));
        }
        ordered_set s;
        map<int,int>mp;
        dfs(0,-1,gr,a,ans,qry,s,mp);
        for(int i=0;i<q;i++){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}