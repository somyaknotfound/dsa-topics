class Solution {
public:

    /*
     * Finds the row index having the maximum element
     * in the given column.
     *
     * Parameters:
     * mat  -> Input matrix
     * n    -> Number of rows
     * m    -> Number of columns (unused but kept for clarity)
     * col  -> Column whose maximum element is required
     *
     * Returns:
     * Row index containing the maximum value in column 'col'
     *
     * Time Complexity: O(n)
     */
    int findMaxIndex(vector<vector<int>>& mat, int n, int m, int col) {
        int index = -1;
        int maxVal = -1;

        for (int i = 0; i < n; i++) {
            if (mat[i][col] > maxVal) {
                maxVal = mat[i][col];
                index = i;
            }
        }

        return index;
    }

    /*
     * Finds a Peak Element in a 2D Grid.
     *
     * A peak element is an element strictly greater than
     * its left and right neighbours.
     *
     * Approach:
     * 1. Perform Binary Search on columns.
     * 2. For the middle column, find the row containing
     *    the maximum element.
     * 3. Compare this element with its left and right neighbours.
     * 4. If it is greater than both, it is a peak.
     * 5. Otherwise move towards the larger neighbour because
     *    a peak is guaranteed to exist in that direction.
     *
     * Parameters:
     * mat -> Input n × m matrix
     *
     * Returns:
     * {row, column} of any peak element.
     *
     * Time Complexity:
     * O(n * log m)
     *   - O(n) to find column maximum
     *   - Done for O(log m) binary search iterations
     *
     * Space Complexity:
     * O(1)
     */
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m - 1;

        while (low <= high) {
            int mid = (low + high) >> 1;

            // Row having maximum value in current column
            int row = findMaxIndex(mat, n, m, mid);

            // Left neighbour (or -1 if column doesn't exist)
            int left = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;

            // Right neighbour (or -1 if column doesn't exist)
            int right = (mid + 1 < m) ? mat[row][mid + 1] : -1;

            // Peak found
            if (mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};
            }

            // Peak lies on the left side
            else if (mat[row][mid] < left) {
                high = mid - 1;
            }

            // Peak lies on the right side
            else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};
