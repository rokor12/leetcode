def main():
    arr = [4,2,1,3]
    ans = minimumAbsDifference(arr)
    print(ans)

def minimumAbsDifference(arr):
    arr.sort()
    minAbsDif = arr[1] - arr[0]
    ans = []
    for i in range(len(arr)-1):
        if arr[i+1] - arr[i] < minAbsDif:
            minAbsDif = arr[i+1] - arr[i]
            ans = [[arr[i],arr[i+1]]]
        elif arr[i+1]-arr[i] == minAbsDif:
            ans.append([arr[i],arr[i+1]])
    return ans
main()
