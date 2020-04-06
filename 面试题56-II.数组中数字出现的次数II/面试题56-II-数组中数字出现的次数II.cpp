class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; ++i){
            int cnt = 0;
            for(int n : nums){
                // n & 1 << i ��ֵ����0��Ϊ��
                if(n & 1 << i) cnt++;
            }
            // ����ֻ����һ�ε��Ǹ����֣��������ķ������ɶ������е�ÿһλ
            if(cnt % 3 == 1) ans ^= (1 << i);
        }
        return ans;
    }
};

