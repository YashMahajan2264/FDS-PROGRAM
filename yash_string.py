def stringlen(s):
    count=0
    for i in s:
        count+=1
    return count

def lis(s):
    li=[]
    st=''
    for i in s:
        if i==" ":
            li.append(st)
            st=''
        else:
            st=st+i
    li.append(st)
    return li

def longest(a):
    temp=0
    ans=''
    for i in range(stringlen(a)):
        b=stringlen(a[i])
        if b>temp:
            temp=b
            ans=a[i]

    return ans

def occ_char(s):
    count1=0
    c=input("Enter the charcter whose frequency you have to count:")
    for i in s:
        if i==c:
            count1+=1
    if count1>1:
        print("Character occcurs",count1," times")
    else:
        print("charcter occur only one time")

def palindrome(str):
    str1=''
    for i in str:
        str1=i+str1
    if(str==str1):
        print("The given string is palindrome")
    else:
        print("The given string is not palindrome")
    
def sub_index(str,str1):
    for i in range(stringlen(str)):
        if str[i]==str1[0]:
            b=i
            co=0
            for j in range(stringlen(str1)):
                if str1[j]==str[i]:
                    co+=1
                    i+=1
                else:
                    break
            if co==stringlen(str1):
                print("Sunstring start at index ",b)
            else:
                print("Substring not found")

def occ_word(s):
    a=lis(s)
    b={}
    for i in a:
        if i not in b.keys():
            b[i]=1
        else:
            b[i]+=1
    print(b)

str=input("Enter the string :")
a=lis(str)
l=longest(a)
print("The word with longest length is ",l)
print()
occ_char(str)
print()
palindrome(str)
print()
str1=input("enter the sub-string")
sub_index(str,str1)
print()
occ_word(str)

