def stringlen(s):
    count=0
    for i in s:
        count+=1
    return count
def lis(s):
    st=''
    li=[]
    for i in s:
        if i==" ":
            li.append(st)
            st=''
        else:
            st=st+i
    li.append(st)
    return li

def longest(a):
    ans=''
    temp=0
    for i in range(stringlen(a)):
        b=stringlen(a[i])
        if b>temp:
            ans=a[i]
            temp=b
    return ans
def occ_char(s):
    count1=0
    c=input("Enter the character whose occurence is to be count: ")
    for i in s:
        if i== c:
            count1+=1
    print("character appears ",count1," times")

def palindrome(s):
    str1=''
    for i in s:
        str1=i+str1
    if(str==str1):
        print("Given string is palindrome.")
    else:
        print("Given string is not palindrome")

def sub_index(str,str1):
    for i in range(stringlen(str)):
        if str[i]==str1[0]:
            b=i
            co=0
            for j in range(stringlen(str1)):
                if str[i]==str1[j]:
                    i+=1
                    co+=1
                else:
                    break
            if co==stringlen(str1):
                print("substring start at index ",b)
                break
            else:
                print("substring can not found")

def occ_word(s):
    b={}
    a=lis(s)
    for i in a:
        if i not in b.keys():
            b[i]=1
        else:
            b[i]+=1
    print(b)




str=input("Enter the string:")
print()
a=lis(str)
l=longest(a)
print("The word with longest length is ",l)
print()
occ_char(str)
print()
palindrome(str)
print()
str1=input("Enter the substring:")
sub_index(str,str1)
print()
occ_word(str)