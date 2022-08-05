def main():
    arr = [4,2,1,3]

def minimumAbsDifference(arr):
    arr.sort()
    minAbsDif = arr[1] - arr[0]
    ans = []
    for i in range(len(arr)-1):
        for j in range(i+1,len(arr)):
            if arr[j]-arr[i] == minAbsDif:
                ans.append([arr[0],arr[i]])
