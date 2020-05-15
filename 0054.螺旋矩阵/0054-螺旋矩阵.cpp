class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size()<1)
        {
            return res;
        }
        int top=0;
        int bottom=matrix.size()-1;
        int left=0;
        int right=matrix[0].size()-1;
        while(true){
            //�� ����
            for (int i = left; i <= right; ++i)
            {
                res.push_back(matrix[top][i]);
            }
            //ȥ����һ��
            if (++top>bottom)
            {
                break;
            }
            //����
            for (int i = top; i <= bottom ; ++i)
            {
                res.push_back(matrix[i][right]);
            }
            //ȥ�����һ��
            if (--right<left)
            {
                break;
            }
            //����
            for (int i = right; i >= left ; --i)
            {
                res.push_back(matrix[bottom][i]);
            }
            //ȥ�����һ��
            if (--bottom<top)
            {
                break;
            }
            //����
            for (int i = bottom; i >= top ; --i)
            {
                res.push_back(matrix[i][left]);
            }
            //ȥ����һ��
            if (++left>right)
            {
                break;
            }
        }
        return res;
    }
};