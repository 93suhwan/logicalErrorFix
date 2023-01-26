#include <bits/stdc++.h>
#define int long long int
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector <int> v;
        v.push_back(0);
        int a[n+2] = {0};
        for(int i = 1;i<= n;i++){
            cin>>a[i];
            v.push_back(a[i] );
        }
        sort(v.begin() , v.end() );
        if(n == 1){
            cout<<"YES\n";
            continue;
        }
        /*set <int> in[n+2];
        for(int i = 1;i<= n;i++){
            in[a[i] ].insert(i );
        }
        for(int i = n;i>=3;i--){
            if(v[i]  == a[i] ){continue;}
            int j = (*in[v[i] ].begin());
            if(j == 1){
                in[v[i] ].erase(1);
                in[a[i] ].erase(i );
                in[a[i] ].insert(2 );
                in[a[2] ].erase(2);
                in[a[2] ].insert(1 );

                a[1] = a[2];
                a[2] = a[i];
            }
            else{
                in[v[i] ].erase(j);
                in[a[i] ].erase(i );
                in[a[i] ].insert(1 );
                in[a[1] ].erase(1);
                in[a[1] ].insert(j );

                a[j] = a[1];
                a[1] = a[i];
            }
        }
        if(a[1] == v[1] && a[2] == v[2] ){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }*/
        int c = 0;
        for(int i = 1;i<= n;i++){
            if(v[i]  != a[i] ){
                c++;
            }
        }
        if(c%3 == 2){
            cout<<"NO\n";continue;
        }
        else{
            cout<<"YES\n";continue;
        }
    }
}
