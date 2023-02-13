def selection_sort(arr,n):
    for i in range(n-1):
        mina=i
        for j in range(i+1,n):
            if(arr[j]<arr[mina]):
                mina=j
        arr[i],arr[mina]=arr[mina],arr[j]
    print("Marks after sorting:",arr)

def bubble_sort(arr,n):
    for i in range(n):
        for j in range(0,n-i-1):
            if arr[j]>arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]
    print("Marks after sorting:",arr)

def top_five(arr,n):
    for i in range(0,5):
        print(arr[n-i-1],end=" ")

print("1.Selection sort")
print("2.Bubble sort")
arr=[]
n=int(input("Enter the no of student:"))

for i in range(n):
    b=float(input("Enter the percentage:"))
    arr.append(b)

print("Marks before sortong:",arr)
selection_sort(arr,n)
top_five(arr,n)

print("Marks before sorting:",arr)
bubble_sort(arr,n)
top_five(arr,n)