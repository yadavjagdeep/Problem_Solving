#include<bits/stdc++.h>
using namespace std;
int n;
void print(vector<vector<int>>&v){
//  int n = v[0].size();
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<v[i][j]<<" ";
    }
    cout<<"\n";
  }
  cout<<"\n";
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
//is_safe(v,2,2);
  return 0;
}
