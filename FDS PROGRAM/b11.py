def minput(r,c,matrix):
    print("Enter the no rowise:")
    for i in range(0,r):
        a=[]
        for j in range(0,c):
            b=int(input())
            a.append(b)
        matrix.append(a)

def moutput(r,c,matrix):
    for i in range(r):
        for j in range (c):
            print(matrix[i][j]," ")
        print()

def add(r1,c1,matrix1,matrix2):
    a=[]
    for i in range (r1):
        b=[]
        for j in range (c1):
            b.append(matrix1[i][j]+matrix2[i][j])
        a.append(b)
    print("Addition of matrix is ")
    moutput(r1,c1,a)

def transpose(r1,c1,matrix1):
    a=[]
    for i in range (r1):
        b=[]
        for j in range (c1):
            b.append(matrix1[j][i])
        a.append(b)
    print("Transpose of matrix is ")
    moutput(r1,c1,a)
    return a

def sub(r1,c1,matrix1,matrix2):
    a=[]
    for i in range (r1):
        b=[]
        for j in range (c1):
            b.append(matrix1[i][j]-matrix2[i][j])
        a.append(b)
    print("Subtraction of matrix is ")
    moutput(r1,c1,a)

def multiply(r1,c2,matrix1,matrix2):
    matrix3=[]
    for i in range (r1):
        c=[]
        for j in range (c2):
            g=0
            for k in range (r1):
                g=g+(matrix1[i][k]*matrix2[k][j])
            c.append(g)
        matrix3.append(c)

    print("Multiplication of two matrices is")
    moutput(r1,c2,matrix3)




r1=int(input("row 1"))
c1=int(input("col 1"))
matrix1=[]
minput(r1,c1,matrix1)
r2=int(input("row r2"))
c2=int(input("col c2"))
matrix2=[]
minput(r2,c2,matrix2)
print("Matrix 1 is")
moutput(r1,c1,matrix1)
print("Matrix 2 is")
moutput(r2,c2,matrix2)

add(r1,c1,matrix1,matrix2)
sub(r1,c1,matrix1,matrix2)
transpose(r1,c1,matrix1)
multiply(r1,c2,matrix1,matrix2)