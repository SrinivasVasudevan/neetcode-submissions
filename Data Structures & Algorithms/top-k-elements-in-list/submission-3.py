class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        cnt = [0]*2002
        for num in nums:
            cnt[num+1000]+=1
        heap = []
        for idx, val in enumerate(cnt):
            if len(heap) < k:
                heapq.heappush(heap,(val, idx-1000))
            else:
                heapq.heappushpop(heap,(val, idx-1000))

        return [v for cnt, v in heap]
        