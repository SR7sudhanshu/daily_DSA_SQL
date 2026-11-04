func minMergedInteger(nums []int) int {
    a := []int{}
    n := len(nums)
    for i := 0; i < n-1; i+=2 {
        s1 := strconv.Itoa(nums[i])
        s2 := strconv.Itoa(nums[i+1])

        s3 := s1 + s2
        val,_ := strconv.Atoi(s3);
        a = append(a, val);
    }
    if len(a) == 0 {
        return 0
    }
    sort.Ints(a)
    s := a[0]
    return s
}
