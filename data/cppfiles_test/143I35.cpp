#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll  long long
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
#define pii pair<int,pi>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define rng(i,a,b) for(int i=a;i<b;i++)
#define ar array
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


void run_case(){
    //mex = i [0,1,2,...i-1] 
    //if i there -> increment
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> f;
    rep(i,n){
        cin >> a[i];
        ++f[a[i]];    
    }
    int c=0,pr_mex=1e9;
    cout<<f[0]<<" ";
    if(f[0]>0){
    }
    else
        pr_mex=-1;
    rng(i,1,n+1){
        if(pr_mex==-1){
            cout<<-1<<" ";
            continue;
        }
        auto it = f.lower_bound(i-1);

        if(it!=f.end() && it->F==(i-1)){
            int x=0;
            if(f.count(i))
                x=f[i];
            cout<<c+x<<" ";
            pr_mex=c+x;
            --f[i-1];
            if(f[i-1]==0)
                f.erase(i-1);
        }
        else{
            if(it==f.begin()){
                pr_mex=-1;
                cout<<-1<<" ";
            }
            else{
                --it;
                c+=i-1-it->F;
                --f[it->F];
                if(f[it->F]==0)
                    f.erase(it->F);
                int x=0;
                if(f.count(i))
                    x=f[i];
                cout<<c+x<<" ";
                pr_mex=c+x;
            }
        }
    }
    cout<<"\n";
}
 
int main(){
    fast;
    int t;
    cin >> t;
    while(t--){
        run_case();
 
    }
}