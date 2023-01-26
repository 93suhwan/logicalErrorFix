#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define f first
#define s second
using namespace std;
const int mxn=2e5+5;
const int inf=1e9;

struct BIT
{
    int bit[mxn] = {};

    void update(int p,int v) {
        if(p==0) return;
        for(;p<mxn;p+=p&-p) bit[p]=max(bit[p],v);
    }
    int query(int p) {
        int r=0;
        for(;p>0;p-=p&-p) r=max(r,bit[p]);
        return r;
    }
} bt;
int main() {
    int n;
    cin >> n;
    int a[n + 1];


    vector<pii> v;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i - a[i] >= 0) v.emplace_back(i - a[i], a[i]);
    }

    if(v.empty()) {
        cout<<0<<endl;
        return 0;
    }



    sort(v.begin(), v.end());


    int dp[n + 1] = {};

    dp[0] = 1;
    bt.update(v[0].s, 1);
    int ans = 0;


    for(int i = 1; i < v.size(); i++) {

        dp[i] = bt.query(v[i].s) + 1;
        ans = max(ans, dp[i]);
        bt.update(v[i].s, dp[i]);

    }

    
    cout<<ans<<endl;
    
}