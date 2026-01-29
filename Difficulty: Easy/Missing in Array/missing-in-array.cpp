class Solution {
  public:
    int missingNum(vector<int>& arr) {
        int n = arr.size() + 1;   // because one number is missing
        long long total = (long long)n * (n + 1) / 2;

        long long sum = 0;
        for (int x : arr) {
            sum += x;
        }

        return total - sum;
    }
};
