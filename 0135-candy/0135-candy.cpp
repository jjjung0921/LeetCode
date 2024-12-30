class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1); // 모든 아이가 최소 1개의 사탕을 받음

        // 왼쪽에서 오른쪽으로 순회
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // 오른쪽에서 왼쪽으로 순회
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // 총 사탕 수 계산
        int result = 0;
        for (int candy : candies) {
            result += candy;
        }

        return result;
    }
};