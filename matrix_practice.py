def minput(r,c,matrix):
    print("Enter the no row wise:")
    for i in range(r):
        a=[]
        for j in range(c):
            b=int(input())
            a.append(b)
        matrix.append(a)
    print(matrix)

def moutput(r,c,matrix):
    for i in range(r):
        for j in range(c):
            print(matrix[i][j]," ")
        print("\n")
def add(r1,c1,matrix1,matrix2):
    a=[]
    for i in range(r1):
        b=[]
        for j in range(c1):
            b.append(matrix1[i][j]+matrix2[i][j])
        a.append(b)
    print("Addition of two matrix:")
    moutput(r1,c1,a)

def subtract(r1,c1,matrix1,matrix2):
    a=[]
    for i in range(r1):
        b=[]
        for j in range(c1):
            b.append(matrix1[i][j]-matrix2[i][j])
        a.append(b)
    print("subtraction of two matrix:")
    moutput(r1,c1,a)

def transpose(r1,c1,matrix1):
    a=[]
    for i in range(r1):
        b=[]
        for j in range(c1):
            b.append(matrix1[j][i])
        a.append(b)
    print("Transpose of matrix:")
    moutput(r1,c1,matrix1)

def multiply(r1,c2,matrix1,matrix2):
    matrix3=[]
    for i in range(r1):
        a=[]
        for j in range(c2):
            g=0
            for k in range(r1):
                g=g+(matrix1[i][k]*matrix2[k][j])
                a.append(g)
            matrix3.append(a)
    print("Multiplication of two matrices:")
    moutput(r1,c2,matrix3)

r1=int(input("enter the row1:"))
c1=int(input("enter the col1:"))
matrix1=[]
minput(r1,c1,matrix1)
r2=int(input("enter the row2:"))
c2=int(input("enter the col2:"))
matrix2=[]
minput(r1,c1,matrix2)
print("Matrix 1:")
moutput(r1,c1,matrix1)
print("Matrix 2:")
moutput(r2,c2,matrix2)

add(r1,c1,matrix1,matrix2)
subtract(r1,c1,matrix1,matrix2)
transpose(r1,c1,matrix1)
multiply(r1,c2,matrix1,matrix2)

