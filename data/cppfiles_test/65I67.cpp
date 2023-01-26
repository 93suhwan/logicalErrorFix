//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
//#define int ll
#define endl '\n'
#define double long double
const int N=1000010;
const ll mod=1000000007;
int a[N];
int c[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    vector<pair<int,int> >ans;
    string s;cin>>s;
    for (int i=0;i<n;i++){
        c[i]=(s[i]=='R');
    }
    for (int i=1;i<=n;i++){
        ans.push_back({a[i],(c[n-1]+n-i)%2});
    }
    int last=-1;
    for (int i=0;i<n;i++){
        if (ans[i].second==c[i]){
//            cout<<i<<" "<<last+1<<endl;
            if (last!=-1){
                for (int j=last;j<i;j++) swap(ans[j],ans[j+1]);
                swap(ans[last],ans[last+1]);
            } else {
                for (int j=1;j<=i;j++) swap(ans[j-1],ans[j]);
            }
//            for (int j=last+2;j<=i;j++){
//                swap(ans[j-1],ans[j]);
//            }
            last=i;
        }
    }
//    for (int i=n-2;i>=0;i--){
//        if (c[i]!=ans[i].second) swap(ans[i],ans[i+1]);
//    }
    for (auto cur:ans){
        cout<<cur.first<<" ";
        if (cur.second) cout<<"R\n";
        else cout<<"L\n";
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}

