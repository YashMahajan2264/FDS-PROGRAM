def partition(arr, s, e):
    pivot = arr[s]
    i=s+1
    j=e-1
    while (i <= j):
        while (i<=j and pivot >= arr[i]):
            i = i + 1
        while (i<=j and pivot <=arr[j]):
            j = j - 1
        if (i <= j):
            arr[i], arr[j] = arr[j], arr[i]
        else:
            arr[s], arr[j] = arr[j], arr[s]
            return j



def quicksort(arr, s, e):
    if len(arr) == 1:
        return arr
    if e-s>1:
        p = partition(arr, s, e)
        quicksort(arr, s, p)
        quicksort(arr, p + 1, e)
    return arr


n = int(input("enter the no. of students:"))
arr = []
print("enter the percentage of students:")
for i in range(n):
    a = float(input())
    arr.append(a)
print("Percentage of student before sorting:")
print(arr)
print("Percentage of student after sorting:")
print(quicksort(arr, 0, n))
print(arr)
print("top 5 scores are:")
for i in range(0, 5):
    print(arr[n - i - 1], end=" ")