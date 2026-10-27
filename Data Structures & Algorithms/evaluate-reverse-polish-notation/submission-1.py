class Solution:            
    def evalRPN(self, tokens: list[str]) -> int:
        stack = []

        for token in tokens:
            if token in "+-*/":
                # Đứa lấy ra đầu tiên là toán hạng BÊN PHẢI
                right = stack.pop()
                # Đứa lấy ra thứ hai là toán hạng BÊN TRÁI
                left = stack.pop()

                match token:
                    case "+": stack.append(left + right)
                    case "-": stack.append(left - right)  # Đã sửa lại thứ tự
                    case "*": stack.append(left * right)
                    case "/": stack.append(int(left / right)) # Đã sửa lại thứ tự
            else:
                stack.append(int(token))

        return stack[0]