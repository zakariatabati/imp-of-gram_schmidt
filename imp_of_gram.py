import math
import copy 
def dot_prod(u,v,n):
    r=0.0
    for i in range(0,n):
        r =r+(u[i]*v[i])
    return r
def normalization(u,v,n):
    r=0.0
    l =[0]*n
    r = dot_prod(u,u,n)
    r = math.sqrt(r)
    for i in range(0,n):
        l[i] = u[i]/r
    v.append(l)

n = int(input("enter the dimension of the space :"))
m = int(input("enter the number of vectors in your family (independent) :"))

u = [[0]*n]*m
v = []
a = [[0]*n]*m
for i in range(0,m):
    print(" enter vector ",i+1,": ")
    x = list(map(int, input().split()))  
    u[i]=x
a = copy.deepcopy(u)
normalization(a[0],v,n)
for i in range(1,m):
    for j in range(1,i+1):
        for k in range(0,n):
            a[i][k] = a[i][k] - (dot_prod(u[i],v[j-1],n)*v[j-1][k])
    normalization(a[i],v,n)

print("the vector after Gram_shmidt : \n")
for i in range(0,m):
    print(" vector ",i+1,": ")
    for j in range(0,n):
        print(v[i][j])
    print("\n")     
