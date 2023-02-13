def partition(arr,s,e):
    pivot=arr[s]
    i=s+1
    j=e-1
    while(i<=j):
        while(i<=j and pivot>=arr[i]):
            i=i+1
        while(i<=j and pivot<=arr[j]):
            j=j-1
        if(i<=j):
            arr[i],arr[j]=arr[j],arr[i]
        else:
            arr[s],arr[j]=arr[j],arr[s]
    return j

def quick_sort(arr,s,e):
    if(len(arr)==1):
        return arr
    elif e-s>1:
        p=partition(arr,s,e)
        quick_sort(arr,s,p)
        quick_sort(arr,p+1,e)

    


n=int(input("Enter the number of students:"))
arr=[]
print("Enter the percentage of students:")
for i in range(n):
    b=float(input())
    arr.append(b)
print("Mark before sorting:")
print(arr)
print("Marks after sorting:")
quick_sort(arr,0,n)
print(arr)
print("Top five scores are:")
for i in range(0,5):
    print(arr[n-i-1],end=" ")