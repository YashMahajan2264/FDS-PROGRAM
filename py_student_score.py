def get_marks(list,n):
    print("enter the marks of students:")
    i=0
    for i in range(n):
        b=int(input())
        if(b<=100 and b>=-1):
            list.append(b)
        else:
            print("You entering invalid marks")
    print("all marks score by all students are:")
    print()
    print(list)

def max_score(list,n):
    max=-4
    for i in range(n):
        if list[i]>max:
            max=list[i]
    print("Highest mark score by an individual is ",max)

def min_score(list,n):
    min=104
    for i in range(n):
        if list[i]<min:
            min=list[i]
    print("Lowest score by an individual is ",min)

def frq(list,n):
    occ=0
    b=0
    for i in range(n):
        count=0
        for j in range(n):
            if list[i]==list[j]:
                count+=0
        if list[i]!=-1 and count>occ:
            occ=count
            b=list[i]
            
    if (occ!=1):
        print("Marks with Highest Frequency :",b)
    else:
        print("Marks with hi' ferquency : None")

def avg_score(list,n):
    sum=0
    count=0
    for i in range(n):
        if(list[i]<=100 and list[i]>=-1):
            sum=sum+list[i]
        else:
            count=count+1
    avg=sum//(n-count)
    print("Avg score of all syudent is ",avg)
  



n=int(input("Enter the number of student"))
list=[]
get_marks(list,n)
max_score(list,n)
min_score(list,n)
frq(list,n)
avg_score(list,n)