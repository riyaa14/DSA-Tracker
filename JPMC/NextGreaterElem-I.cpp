class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums2Map;

        for(int i=0; i<nums2.size(); i++){
            nums2Map[nums2[i]] = i;
        }

        vector<int> nextGreaterElem(nums2.size(), -1);
        vector<int> ans;

        // for(int x : nums1){
        //     int idx = nums2Map[x];

        //     int elem = -1 , j;
        //     for(j=idx+1; j<nums2.size(); j++){

        //         if(nums2[j]>x){ 
        //             nextGreaterElem[idx] = nums2[j];
        //             break;
        //         }

        //         if(nextGreaterElem[j]!=-1 and nextGreaterElem[j]>x) {
        //             // if(nums[j] > x) { nextGreaterElem[idx]; break; }
        //             nextGreaterElem[idx] = nextGreaterElem[j];
        //             break;
        //         }
        //     }

        //     ans.push_back(nextGreaterElem[idx]);
        // }

        stack<int> s;
        s.push(nums2[nums2.size()-1]);

        for(int i=nums2.size()-2; i>=0; i--){

            while(!s.empty() and s.top()<nums2[i]) s.pop();

            if(s.empty()) nextGreaterElem[i] = -1;
            else nextGreaterElem[i] = s.top();

            s.push(nums2[i]);

        }

        for(int x: nums1){
            ans.push_back(nextGreaterElem[nums2Map[x]]);
        }

        return ans;
    }
};
