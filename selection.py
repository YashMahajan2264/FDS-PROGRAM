def selection_sort(arr,n):
    for i in range(0,n-1):
        mina=i
        for j in range(i+1,n):
            mina=j
            if(arr[i]>arr[mina]):
                 arr[mina],arr[i]=arr[i],arr[mina]
       
    print("Marks after sorting: ",arr)

def bubble_sort(arr,n):
    for i in range(0,n):
        for j in range(0,n-i-1):
            if(arr[j]>arr[j+1]):
                arr[j],arr[j+1]=arr[j+1],arr[j]
    print("Marks after sorting: ",arr)

def top_five(arr,n):
    print("Top five scores:")
    for i in range(0,5):
        print(arr[n-i-1],end=" ")

n=int(input("enter the no of student: "))
arr=[]
for i in range(0,n):
    b=float(input())
    arr.append(b)

c=int(input("Enter your choice" ))
if c==1:
    print("Marks before sorting: ",arr)
    selection_sort(arr,n)
    top_five(arr,n)
elif c==2:
    print("Marks before sorting: ",arr)
    bubble_sort(arr,n)
    top_five(arr,n)
else:
    print("Invalid choice")
