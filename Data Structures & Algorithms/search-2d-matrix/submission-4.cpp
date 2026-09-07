class Solution {
public:

    int RowNumber(vector<vector<int>> &matrix, int target){
        int top = 0;
        int bottom = matrix.size()-1;
        int mid  = (top + bottom)/2;

        if (target<matrix[0][0] || target > matrix[matrix.size()-1][matrix[0].size()-1]){
            return -1;
        }

        while(top<=bottom){

            if(target>matrix[mid][matrix[0].size()-1]){
                top = mid + 1;
            }
            else if(target<matrix[mid][0]){
                bottom = mid - 1;
            }
            else{
                return mid;
            }
            mid = (top + bottom)/2;
            
        }
        return mid;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int finalRow = RowNumber(matrix, target);
        if(finalRow == -1){
            return false;
        }
        int left = 0;
        int right  = matrix[finalRow].size()-1;
        int mid = (left + right)/2;


        while (left<=right){
            if(matrix[finalRow][mid]==target){
                return true;
            }
            else if(matrix[finalRow][mid]>target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
            mid = (left + right)/2;
        }
        return false;
    }


        
        
   
};
