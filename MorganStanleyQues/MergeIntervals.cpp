class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        int s = intervals[0][0], e = intervals[0][1];
        vector<vector<int>> ans;
        for(int i=1; i<n+1; i++){

            if(i==n) ans.push_back({s, e});
            else if(intervals[i][0] <= e) e = max(intervals[i][1], e);
            else{
                ans.push_back({s, e});
                s = intervals[i][0];
                e = intervals[i][1];
            }
        }

        return ans;
    }

    // TIME COMPLEXITY : O(NLOGN)
    // SPACE COMPLEXITY : O(N)
};
