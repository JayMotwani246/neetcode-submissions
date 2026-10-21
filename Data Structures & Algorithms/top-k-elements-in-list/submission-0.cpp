class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;


    unordered_map<int,int> mp;

    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;


    }

    for(auto& pair:mp){
        pq.push({pair.second,pair.first});

        if(pq.size()>k){
            pq.pop();
        }
    }

    vector<int> ans;

    for(int i=0;i<k;i++){
        int a=pq.top().second;

        ans.push_back(a);
        pq.pop();
    }
        return ans;
    }
};
