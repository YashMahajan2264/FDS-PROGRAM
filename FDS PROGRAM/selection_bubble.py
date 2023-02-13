def selection_sort(arr,n):
    for i in range(0,n-1):
        mina=i
        for j in range(i+1,n):
            mina=j
        (arr[i],arr[mina])=(arr[mina],arr[i])
    print("Marks after sorting:",arr)

def bubble_sort(arr,n):
    for i in range(0,n):
        for j in range(0,n-i-1):
            if arr[j]>arr[j+1]:
                (arr[j],arr[j+1])=(arr[j+1],arr[j])
    print("Marks after Sorting:",arr)

def top_five(arr,n):
    print("Top five scores are:")
    for i in range(0,5):
        print(arr[n-i-1],end=" ")

print("1.Selection sort")
print("2.bubble sort")
c=int(input("enter your choice"))

if c==1 or c==2:
    n=int(input("Enter the no of student"))
    arr=[]
    print("Enter the percentage of students")
    for i in range(n):
        b=float(input())
        arr.append(b)

elif c==1:
    print("Marks before sorting:",arr)
    selection_sort(arr,n)
    top_five(arr,n)

elif c==2:
    print("Marks before sorting:",arr)
    bubble_sort(arr,n)
    top_five(arr,n)
