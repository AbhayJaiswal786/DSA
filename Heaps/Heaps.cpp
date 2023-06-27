#include<bits/stdc++.h>
#include "C:\Users\asus1\OneDrive\Attachments\__Programming\Winning Camp\DSA\_Shortcut.cpp"
using namespace std;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    //creating max heap of <pair<int,pair<int,int>> ... storing {sum of pairs , {pair's first element, pair's second element}}
    
    priority_queue<pair<int,pair<int,int>>> max_heap;
    
    for(int i = 0; i<nums1.size(); i++){
        for(int j = 0; j<nums2.size(); j++){
            if(max_heap.size()<k) max_heap.push({(nums1[i]+nums2[j]),{nums1[i],nums2[j]}}); 
            else if((max_heap.size()==k) && (nums1[i]+nums2[j]) < max_heap.top().first){
                max_heap.pop();
                max_heap.push({(nums1[i]+nums2[j]),{nums1[i],nums2[j]}});
            }
            else break;
        }
    }

    vector<vector<int>> ans;
    
    while(max_heap.size()){
        ans.push_back({max_heap.top().second.first,max_heap.top().second.second});
        max_heap.pop();
    }

    return ans;
}

int main(){
//K smallest pairs
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {3,2,1,4};
    int k = 3; //number of pairs want 
    vector<vector<int>> ans = kSmallestPairs(nums1, nums2, k);
    print_2D_vector(ans);

    vector<int> :: iterator it;
    for(it = nums2.begin(); it!=nums2.end(); it++){
        cout<<*(it)<<" ";
    }




}