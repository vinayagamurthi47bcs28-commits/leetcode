class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def valid_parentheses(n, open_count, curr, res):
            if len(curr) == 2 * n:
                res.append(curr)
                return
            if open_count < n:
                valid_parentheses(n, open_count + 1, curr + '(', res)
            if len(curr) - open_count < open_count:
                valid_parentheses(n, open_count, curr + ')', res)
        result = []
        valid_parentheses(n, 0, '', result)
        return result
