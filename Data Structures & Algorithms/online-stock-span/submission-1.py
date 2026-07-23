class StockSpanner:
    __slots__ = ('stack')

    def __init__(self):
        self.stack = []
        

    def next(self, price: int) -> int:
        if len(self.stack) == 0:
            self.stack.append((price, 1))
            return 1
        else:
            total = 1
            while self.stack and self.stack[-1][0] <= price:
                total+=self.stack.pop()[1]
            self.stack.append((price, total))
            return total

        


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)