#include<bits/stdc++.h>
using namespace std;
int n;
bool flag;
bool cmp(vector<int>v1,vector<int>v2){
  for(int i=0;i<v1.size();i++){
    if(v1[i]>v2[i])
    return v1<v2;
  }
return v2<v1;
}
void permute_ans(vector<vector<int>>&ans){
  sort(ans.begin(),ans.end(),cmp);
  cout<<'[';
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
      cout<<ans[i][j]<<" ";
    }
  }
    cout<<']';
    cout<<" ";
  //cout<<'\n';
}
void print(vector<vector<int>>&v){
//  int n = v[0].size();
vector<vector<int>>ans;
  for(int i=0;i<n;i++){
    vector<int>row;
    for(int j=0;j<n;j++){
      //cout<<v[i][j]<<" ";
      if(v[i][j]==1)
      row.push_back(j+1);
    }
    //cout<<"\n";
    ans.push_back(row);
  }
  permute_ans(ans);
  //cout<<"\n";
}
/************is_safe function ******************/
bool is_safe(vector<vector<int>>&v,int k,int l){

  //bottom Check
  for(int i=k+1;i<n;i++){
  // cout<<i<<l<<" ";
  if(v[i][l]==1)
  return false;
  }
  //top Check
  for(int i=k-1;i>=0;i--){
    // cout<<i<<l<<" ";
    if(v[i][l]==1)
    return false;
  }
  //left Check
  for(int i=l-1;i>=0;i--){
      //cout<<k<<i<<" ";
      if(v[k][i]==1)
      return false;
  }
  //right Check
  for(int i=l+1;i<n;i++){
      //cout<<k<<i<<" ";
      if(v[k][i]==1)
      return false;
  }
  //principal diagonal top Check
  int j=l-1;
  for(int i=k-1;i>=0 && j>=0;i--,j--){
    //  cout<<i<<j<<" ";
    if(v[i][j]==1)
    return false;
  }
  //principal diagonal bottom Check
   j=l+1;
  for(int i=k+1;i<n && j<n;i++,j++){
   // cout<<i<<j<<" ";
   if(v[i][j]==1)
   return false;
  }
  //non-principal diagonal top Check
  j=l+1;
  for(int i=k-1;i>=0 && j<n;i--,j++){
     //cout<<i<<j<<" ";
     if(v[i][j]==1)
     return false;
  }
  //non-principal diagonal bottom Check
  j=l-1;
  for(int i=k+1;i<n && j>=0;i++,j--){
  //  cout<<i<<j<<" ";
    if(v[i][j]==1)
    return false;
  }
return true;
}

/***********************************************/
void N_queen(vector<vector<int>>&v,int k){
  if(k==n){
    flag=false;
    print(v);
    return;
  }
  for(int i=0;i<n;i++){
    if(is_safe(v,k,i)){
      v[k][i]=1;
      N_queen(v,k+1);
      v[k][i]=0;
    }
  }
}
int main(){
  int t;cin>>t;
  while(t--){
    flag=true;
    cin>>n;
    vector<vector<int>>v;
    for(int i=0;i<n;i++){
      vector<int>row;
      for(int j=0;j<n;j++){
        row.push_back(0);
      }
      v.push_back(row);
    }
   N_queen(v,0);
   if(flag==true)
   cout<<-1;
   cout<<'\n';
  //is_safe(v,2,2);
  }

  return 0;
}
