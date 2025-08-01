def max_subarray(nums:list[int], DEBUG:bool=False) -> int:
    n = len(nums)
    if DEBUG: print(nums) 
    max_sum = nums[0]
    for i in range(1, n):
        if nums[i-1] > 0:
            nums[i] += nums[i-1]
        max_sum = max(max_sum, nums[i])
    if DEBUG: print(nums)

    return max_sum