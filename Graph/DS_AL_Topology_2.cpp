#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 #define WHITE 0
 #define GRAY 1
 #define BLACK 2

 vector<int>graph[100];
 int runner[100];
 vector<int>result;
 bool cycle;

 void dfs(int start)
 {
     runner[start]=GRAY;

     sort(graph[start].begin(),graph[start].end());

     for(int i=graph[start].size()-1;i>=0;i--)
     {
         int next=graph[start][i];

         if(runner[next]==WHITE)
         {
             dfs(next);
         }
         else if(runner[next]==GRAY)
         {
             cycle=true;
             return;
         }
     }
     runner[start]=BLACK;
     result.push_back(start);
 }

 int main(void)
 {
     cycle=false;
     int nodes,edges;
     cin>>nodes>>edges;
     for(int i=0;i<edges;i++)
     {
         int a,b;
         cin>>a>>b;
         graph[a].push_back(b);
     }
     for(int i=nodes;i>=1;i--)
     {
         if(runner[i]==WHITE)
         {
             dfs(i);
         }
     }
     if(cycle==true)
     {
         cout<<"You Failed"<<endl;
     }
     else
     {
         for(int i=result.size()-1;i>=0;i--)
         {
             cout<<result[i]<<" ";
         }
     }
 }












