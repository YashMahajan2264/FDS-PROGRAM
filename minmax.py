def get_array(list, n):
    print("Enter the marks obtained by student and if student is absent give him -1: ")
    i=0
    for i in range(n):
        b=int(input())
        if b>=-1 and b<=100:
            list.append(b)
        else:
            print("Enter the marks between -1 to 100")
    print("List of marks score by student :")
    print(list,"\n")

def max_score(list,n):
    max=-4
    for i in range(n):
        if (list[i])>max:
            max=list[i]
    print("Highest score :",max)

def min_scoore(list ,n):
    min=104
    for i in range(n):
        if list[i]<min:
            min=list[i]
    print("Minimum score by student is ",min)

def fre(list ,n):
    count=0
    ans=0
    temp=0
    for i in range(n):
        for j in range(n):
            if list[i]==list[j]:
                count+=1
        if count>temp:
            temp=count
            ans=list[i]
    if(ans!=-1):
        print("marks with highest frequency is",ans)
    else:
        print("Mark with high frquency :none")

def avg(list ,n):
        sum=0
        count1=0
        for i in range(n):
            if list[i]>-1 and list[i]<=100:
                sum=sum+list[i]
            else:
                count1+=1
        avg=sum/(n-count1)
        print("Avg score of class :",avg)
        print("No of absent student :",count1)

n=int(input("Enter the no of student :"))
list=[]
get_array(list,n)
avg(list,n)
max_score(list,n)
min_scoore(list,n)
fre(list,n)
