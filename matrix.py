def minput(r,c,matrix):
    print("Enter the number row wise: ")
    for i in range(r):
        a=[]
        for j in range(c):
            b=int(input())
            a.append(b)
        matrix.append(a)
    
def moutput(r,c,matrix):
    for i in range(r):
        for j in range(c):
            print(matrix[i][j],end=" ")
        print()

def addition(r1,c1,matrix1,matrix2):
    a=[]
    for i in range(r1):
        b=[]
        for j in range(c1):
            b.append(matrix1[i][j]+matrix2[i][j])
        a.append(b)
    print("Addition of two matrices: ")
    moutput(r1,c1,a)

def subtraction(r1,c1,matrix1,matrix2):
    a=[]
    for i in range(r1):
        b=[]
        for j in range(c1):
            b.append(matrix1[i][j]-matrix2[i][j])
        a.append(b)
    print("Subtraction of two matrices: ")
    moutput(r1,c1,a)

def transpose(r1,c1,matrix1):
    a=[]
    for i in range(r1):
        b=[]
        for j in range(c1):
            b.append(matrix1[j][i])
        a.append(b)
    print("Transpose of matrices: ")
    moutput(r1,c1,a)

def multiplication(r1,c2,matrix1,matrix2):
    matrix3=[]
    for i in range(r1):
        a=[]
        for j in range(c2):
            g=0
            for k in range(r1):
                g=g+(matrix1[i][k]*matrix2[k][j])
            a.append(g)
        matrix3.append(a)
    print("Multiplication of two matrices: ")
    moutput(r1,c2,matrix3)
r1=int(input())
c1=int(input())
matrix1=[]
minput(r1,c1,matrix1)
r2=int(input())
c2=int(input())
matrix2=[]
minput(r2,c2,matrix2)
print("Matrix 1 :")
moutput(r1,c1,matrix1)
print("matrix 2: ")
moutput(r2,c2,matrix2)
addition(r1,c1,matrix1,matrix2)
subtraction(r1,c1,matrix1,matrix2)
multiplication(r1,c2,matrix1,matrix2)
transpose(r1,c1,matrix1)