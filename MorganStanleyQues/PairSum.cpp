vector<vector<int>> pairSum(vector<int> &arr, int s){

   // ------------------- APPROACH - 1 (TWO POINTER APPROACH) ------------------
   
   // multiset<pair<int, int>> ansSet;

   // unordered_map<int, int> freq;

   // vector<int> uniquearr;

   // for(int k=0; k<arr.size(); k++){
   //    if(!freq.count(arr[k])) uniquearr.push_back(arr[k]);
   //    freq[arr[k]]++;
   // }

   // sort(uniquearr.begin(), uniquearr.end());
   
   // for(int k=0; k<uniquearr.size(); k++){
   //    if(uniquearr[k]+uniquearr[k] == s){

   //       int f = freq[uniquearr[k]];

   //       for(int l=0; l< (f*(f-1)) / 2; l++){
   //       ansSet.insert({uniquearr[k], uniquearr[k]});
   //       }
   //    }
   // }

   // int i=0, j=uniquearr.size()-1;

   // while(i<j){
   //    int sum = uniquearr[i] + uniquearr[j];
   //    if(sum < s){
   //       i++;
   //    }else if(sum > s){
   //       j--;
   //    }else{
   //       int f = freq[uniquearr[i]] * freq[uniquearr[j]];
   //       while(f-->0)
   //       ansSet.insert({uniquearr[i], uniquearr[j]});
           
   //       i++; j--;
   //    }
   // }

   // vector<vector<int>> ans;

   // for(auto p : ansSet){
   //    vector<int> pair = {p.first, p.second};
   //    ans.push_back(pair);
   // }

   // return ans;

   // -------------------- APPROACH - 2 (USING HASHMAP) ------------------

   vector<vector<int>> ans;
   unordered_map<int, int> freq;

   for(int i=0; i<arr.size(); i++){
      int pairs = freq[s-arr[i]];

      vector<int> p(2);
      if (arr[i] < s - arr[i]) {
         p[0] = arr[i];
         p[1] = s - arr[i];
      } else{
         p[0] = s - arr[i];
         p[1] = arr[i];
      }

      while(pairs-- > 0){
        ans.push_back(p);
      }

      freq[arr[i]]++;
   }

   sort(ans.begin(), ans.end());

   return ans;

}
