#include <bits/stdc++.h>
#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pbds                                               \
    tree<pair<int, int>, null_type, less<pair<int, int> >, \
         rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;


using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define tr(c, it) for (auto it = (c).begin(); (it) != (c).end(); it++)
#define pres(c, val) ((c).find(val) != (c).end())      // for sets, multisets, maps etc.

// s.erase(s.lower_bound(value));   erase single instance of value from multiset s



void solve(void){

    int n; cin>>n;

    int a[n];

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    sort(a, a+n);

    for(int i=1; i<=n/2; i++){
        cout<<a[0]<<' '<<a[i]<<'\n';
    }
    

}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif



{
    int TEST_CASES=1;
    cin>>TEST_CASES;

    for(int TEST_NUM=1; TEST_NUM<=TEST_CASES; TEST_NUM++){
    //    cout<<"Case #"<<TEST_NUM<<": ";
        solve();
        cout << endl;
    }

    return 0;
}


}