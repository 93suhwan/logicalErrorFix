#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set =
tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod=1e9+7;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        multiset<int>se;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            se.insert(x);
        }
        if(n==1){
            cout<<*se.begin()<<endl;
            continue;
        }
        ll sum=0;
        ll mi =-2e9;
        while(!se.empty() && (1LL**se.begin()-sum)>=mi){
            mi=1LL**se.begin()-sum;
            sum+=(1LL**se.begin()-sum);
            se.erase(se.find(*se.begin()));
        }
        cout<<mi<<endl;
    }
}
