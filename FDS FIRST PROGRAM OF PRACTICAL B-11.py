def linear_search(a,n,c):
    for i in range(n):
        if c==a[i]:
             print(c,"is present at index:",i)
             print("student was present in program.")
             break
    else:
        print("student was absent in program.")
        
def sentinelSearch(a,n,c):
    last=a[n-1]
    a[n-1]=c
    i=0
    
    while (a[i]!=c):
        i+=1
    a[n-1]=last

    if((i<n-1) or (a[n-1]==c)):
        print(c,"is present at index ",i)
        print("Student was present in program.")
    else:
        print("student was absent in progrram")

n=int(input("Enter the number of students="))
a=[]
for i in range(n):
    b=int(input())
    a.append(b)
print("List of student present in program:")
print(a,"\n")

c=int(input("enter the roll no of student to search:"))
print("Select yhe searching method:")
print("1.Linear Search\n2.Sentinal Search")
d=int(input())

if(d==1):
    linear_search(a,n,c)
elif(d==2):
    sentinelSearch(a,n,c)



    
    

    
