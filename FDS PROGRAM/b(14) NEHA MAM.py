def stringlen(s):
    count=0
    for i in s:
        count+=1;
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
    temp=0;
    ans=''
    for i in range(stringlen(a)):
        b=stringlen(a[i])
        if b>temp:
            ans=a[i]
            temp=b
            
    return ans
    
def occ_char(s):
    ch=input("enter the character whose frequency to find:")
    count1=0
    for i in s:
        if i==ch:
            count1+=1
    print("frequency of occurence of character is :",count1)
    
def palindrome(str):
    str1=''
    for i in str:
        str1=i+str1
    if str==str1:
        print("The given string is palindrome")
    else:
        print("The given string is not palindrome")
        
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
            if co==(stringlen(str1)):
                print("Substring start at index",b)
                break
            else:
                print("Not found")
        
def occ_word(str):
    a=lis(str)
    b= {}
    for i in a:
        if i not in b.keys():
            b[i]=1
        else:
            b[i]+=1
    print(b)
    
str=input("enter the string:")
print()
a=lis(str)
l=longest(a)
print("The word with the longest length is:",l)
print()
occ_char(str)
print()
palindrome(str)
print()
str1=input("enter the substring:")
sub_index(str,str1)
print()
print("Occurence of each word in string:")
occ_word(str)

