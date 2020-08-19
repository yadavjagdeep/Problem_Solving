#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxsum(vector<int>&v){
  int msum = v[0];
  int sum=v[0];
  for(int i=1;i<v.size();i++){
    sum = (sum+v[i])>v[i] ? (sum+v[i]):v[i];
    msum = sum>msum?sum:msum;
  }
  return msum;
}
int main(){
  int n;cin>>n;
  std::vector<int> v;
  for(int i=0;i<n;i++){
    int val;cin>>val;
    v.push_back(val);
  }
  cout<<maxsum(v)<<endl;
return 0;
}
