func minOperations(nums []int, locked []int, k int) int {
    n := len(locked)
    d := make([]int, n+3);

    for i, val := range nums {
        if val != i + 1 {
            req := val - 1
            curr := i
            d[min(req, curr)]++
            d[max(req, curr) + 1]--
        }
    }

    for i := 1; i < n; i++ {
        d[i] += d[i - 1]
    }

    ans := 0

    for i := 0; i < n; i++ {
        count := 0
        for j:=i + 1; j < n; j++ {
            if nums[j] < nums[i] {
                count++;
            } 
        }
            ans += count
    }

    lock := 0
    for i := 0; i < n; i++ {
        if d[i] > 0 && locked[i] == 1 {
            lock++
        }
    }
    if lock > k {
        return -1
    }
    
    return ans + lock
}