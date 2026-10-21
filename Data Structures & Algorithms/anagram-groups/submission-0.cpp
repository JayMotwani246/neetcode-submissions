class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,vector<string>> store;

        for(int i=0;i<strs.size();i++){
            string count(26,'0');

            for(int j=0;j<strs[i].size();j++){
                count[strs[i][j]-'a']++;
                
            }

            store[count].push_back(strs[i]);

        }

        vector<vector<string>> result;

        for(auto& pair:store){

            result.push_back(pair.second);
            
        }
        return result;


        
    }
};
