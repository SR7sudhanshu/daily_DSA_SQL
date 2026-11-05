func findTheDistanceValue(arr1 []int, arr2 []int, d int) int {
    count := 0
    for _, val := range arr1 {
        found := false
        for _, v := range arr2 {
            diff := val - v
            if diff < 0 {
                diff = -diff
            }
            if diff <= d {
                found = true
                break
            }
        }
        if !found {
            count++
        }
    }
    return count
}