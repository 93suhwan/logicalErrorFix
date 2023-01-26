//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("no-stack-protector")
#include<bits/stdc++.h>
typedef int_fast32_t in;
typedef int_fast16_t shr;
typedef int_fast64_t ll;
typedef uint_fast64_t ull;
using namespace std;

void fun(){
    in n;
    cin>>n;
    vector<in> a(n);
    for(in i=0;i<n;++i) cin>>a[i];
    string s;
    cin>>s;
    vector<in> bl,red;
    for(in i=0;i<n;++i){
        if(s[i]=='B') bl.push_back(a[i]);
        else red.push_back(a[i]);
    }
    sort(bl.begin(),bl.end());
    for(in i=0;i<bl.size();++i){
        if(bl[i]<i+1){
            cout<<"NO"<<'\n';
            return;
        }
    }
    sort(red.begin(),red.end());
    for(in i=0;i<red.size();++i){
        if(red[i]>i+1+bl.size()){
            cout<<"NO"<<'\n';
            return;
        }
    }
    cout<<"YES"<<'\n';


}
in main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    in t;
    cin>>t;
    ++t;
    while(--t) fun();
}
