# A Dynamic Programming based Python
    # Program for 0-1 Knapsack problem
    # Returns the maximum value that can
    # be put in a knapsack of capacity W
class Dynamic:
    def dynamicApproach(self,weights, values, capacity, totalWeights, table):
        '''
        :param weights: Values from input w file
        :param values: Values from input v file
        :param totalWeights: Value from c file
        :param totalWeights: Number of weights
        :param table: 2D Table Array
        :return:
        '''
        # Build table K[][] in bottom up manner
        for i in range(totalWeights+1):
            for w in range(capacity + 1):
                if i == 0 or w == 0:
                    table[i][w] = 0
                elif weights[i-1] <= w:
                    table[i][w] = max(values[i-1] + table[i-1][(w - weights[i-1])], table[i-1][w])
                else:
                    table[i][w] = table[i-1][w]

        return table[totalWeights][capacity]


    def dynamicOptimal(self,weights, capacity, totalWeights, table):
        '''
        :param weights: Array of weights
        :param capacity: Max weight capacity
        :param totalWeights: Total number of weights
        :param table: 2D Table Array
        :return: Optimal values
        '''
        optimal = []
        i = totalWeights
        j = capacity

        while i > 0 and j > 0:
            if table[i][j] > table[i-1][j]:
                optimal.insert(0, i)
                i -=1
                j -= weights[i]
            else:
                i -= 1

        return optimal
