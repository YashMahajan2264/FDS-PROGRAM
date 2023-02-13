def linear_search(arr,n,c):
    for i in range(n):
        if arr[i]==c:
            print("Student was found at index: ",i)
            print("Student was present in program.")
            break
    else:
        print("Student was absent in program.")

def sentinel_search(arr,n,c):
    last=arr[n-1]
    arr[n-1]=c
    i=0
    while(arr[i]!=c):
        i=i+1
    arr[n-1]=last
    if (i<n-1) or (arr[n-1]==c):
        print("Student was presemt at index: ",i)
    else:
        print("Student was absent in program")

n=int(input("Enter the no of student: "))
arr=[]
print("Enter the roll no of student: ")
for i in range(n):
    b=int(input())
    arr.append(b)
print("List of student present in program is ")
print(arr,"/n")
c=int(input("Enter the rollno of student to search: "))
print("\n")
print("1.Linear search\n2.sentinel search:")
d=int(input("Enter your choice: "))
if d==1:
    linear_search(arr,n,c)
elif d==2:
    sentinel_search(arr,n,c)