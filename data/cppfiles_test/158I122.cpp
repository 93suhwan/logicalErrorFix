#include <bits/stdc++.h>
typedef std::pair<int,int> pii;
int main()
{
    int t;
    std::cin>>t;
    for(int __=0;__!=t;++__){
        int n,m;
        std::cin>>n>>m;
        long long best=0;
        long long espera[n];for(auto&x:espera)std::cin>>x;
        std::string s[n];for(auto&x:s)std::cin>>x;
        std::vector<int> v;
        for(int i=0;i!=(1<<n);++i){
            std::vector<pii> deltas;
            for(int j=0;j!=m;++j){
                long long delta=0;
                for(int k=0;k!=n;++k){
                    if((s[k][j]-'0')==((bool)(i&(1<<k))))++delta;else --delta;
                }
                deltas.push_back({delta,j});
            }
            std::sort(deltas.begin(),deltas.end());
            long long estudantes[n]={};
            long long ans=0;
            for(int j=0;j!=m;++j){
                for(int k=0;k!=n;++k){
                    if(s[k][deltas[j].second]=='1'){
                        estudantes[k]+=j+1;
                    }
                }
            }
           // for(int j=0;j!=n;++j)std::cout<<estudantes[j]<<" ";std::cout<<"\n";
            for(int j=0;j!=n;++j)ans+=abs(estudantes[j]-espera[j]);
            if(best<ans){
                best=ans;
             //   std::cout<<ans<<" a\n";
                v.clear();
                for(int i=0;i!=m;++i)v.push_back(0);
                for(int i=0;i!=m;++i){
                    v[deltas[i].second]=i+1;
                }
            }
        }
       // std::cout<<best<<"\n";
        for(auto&x:v)std::cout<<x<<" ";std::cout<<"\n";
    }
}
