class Solution {
public:
   long long maxSum(vector<int>& nums, int k) {
       int n = nums.size();
       long long ans = LLONG_MIN;

       vector<int> sorte = nums;
       multiset<int> o, c;
       sort(sorte.begin(), sorte.end());
       
       for(int i = 0; i < max(0, n - k); i++) o.insert(sorte[i]);
       for(int i = n - 1; i >= max(0, n - k); i--) c.insert(sorte[i]);

        multiset<int> candidates, others;
       for (int i = 0; i < n; ++i) {
           long long total = 0;
            candidates = c, others = o;   
           for (int j = i; j < n; ++j) {
               if (!others.empty()) {
                   auto it = others.find(nums[j]); 
                   if (it != others.end()) {
                       others.erase(it);
                       candidates.insert(nums[j]);
                   } else {
                       auto last_it = prev(others.end()); 
                       int obiggest = *last_it;
                       others.erase(last_it);
                       candidates.insert(obiggest);
                   }
               }
               auto max_cand_it = prev(candidates.end());
               int biggest = *max_cand_it;
               total += biggest;
               candidates.erase(max_cand_it); 
               
               ans = max(ans, total);
           }
       }
       return ans;
   }
};