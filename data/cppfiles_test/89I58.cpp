//never stop solving!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include<bits/stdc++.h>
#define int long long
using namespace std;


void testcase(){
    int n;cin>>n;
    vector<int>a(n);

    for(int i=0;i<n;i++)cin>>a[i];

    int p=1;
    for(int i=1;i<=n;i++){
        p*=i+1;
        if(p>1e9)break;

        if(gcd(a[i-1],p)>1){
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
}





signed
main() {
#if!ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);cin.tie(0);



    int t;cin>>t;while(t--)
        testcase();
    
    
    exit(EXIT_SUCCESS);
}








