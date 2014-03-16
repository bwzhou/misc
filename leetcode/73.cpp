class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // remeber if the first row and the first column contain zero.
        // cannot abuse matrix[0][0] to represent both the first row and the first column.
        bool firstColIsZero = false;
        bool firstRowIsZero = false;
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                firstColIsZero = true;
            }
        }
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[0][j] == 0) {
                firstRowIsZero = true;
            }
        }
        // summarize the locations of zero in the matrix into the first row and the first column.
        // therefore, matrix[i][0] == 0 iff matrix[i][0] is originally 0 or there exists zero in row i.
        // similarly, matrix[0][j] == 0 iff matrix[0][j] is originally 0 or there exists zero in column j.
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // set zero in the matrix except the first row and the first column.
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // finally zero the first row and the first column if necessary.
        if (firstColIsZero) {
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][0] = 0;
            }
        }
        if (firstRowIsZero) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                matrix[0][j] = 0;
            }
        }
    }
};