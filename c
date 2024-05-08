q1
class myset:
    def _init_(self):
        self.card =0
        self.data = []
        self.card = int(input("enter no. of elements: "))
        for i in range (0,self.card):
            temp = int(input("enter the element: "))
            self.data.append(temp)
    def display(self):
        print (self.data)
    def ismember(self):
        n = int(input("enter the no. which you want to find "))
        if n in self.data:
            print("given element is in set")
        else:
            print("given element is not in set")
    def removedup(self):
        D =[]
        for i in self.data:
            if i not in D:
                D.append(i)
        self.data = D
    def union(self,other):
        U = self.data.copy()
        U.extend(i for i in other.data if i not in U)
        print(U)
    def intersect(self,other):
        I = [i for i in self.data if i in other.data]
        print(I)

    def difference(self,other):
        D = [i for i in self.data if i not in other.data]
        print(D)

    def sym_diff(self,other):
        S= [i for i in self.data if i not in other.data]
        S1= [j for j in other.data if j not in self.data]
        S.extend(S1)
        print (S)
        
    def cartesian(self,other):
        l=[]
        for i in self.data:
            for j in other.data:
                l.append((i,j))
        print(l)
    
    def is_subset(self,other):
        for i in self.data:
            if i not in other.data:
                return False
        return True

set2=myset()
set2.display()
set1=myset()
set1.display()
set1.removedup()
set2.removedup()
set3=set1.union(set2)
set4=set1.intersect(set2)
set5=set1.cartesian(set2)
set6=set1.difference(set2)
set7=set1.sym_diff(set2)
set8 = myset()
print(set8.is_subset(set2))




q3
def permute(num):
    if len(num) == 1:
        return [num]
    result = []
    for i in range(len(num)):
        f_num = num[i]
        rem_num = num[:i] + num[i+1:]
        for i in permute(rem_num):
            result.append([f_num] + i)
    return result

numbers = input("Enter a list of numbers separated by space: ").split()
numbers = [int(num) for num in numbers]
print("All permutations of", numbers, "are:")
print(permute(numbers))


q4
n=int(input('Enter variables:'))
c=int(input('Enter the value of equivalent:'))
l=[0 for _ in range(n+1)]

def sol(n,c):
    if n==1:
        l[n]=c
        print(l[1:])
    else:
        for i in range(c+1):
            l[n]=i
            sol(n-1, c-i)
            
sol(n,c)


q6
def complete_graph(matrix):
    n = len(matrix)
    for i in range(n):
        for j in range(n):
            if i != j and (matrix[i][j] == 0 or matrix[j][i] == 0):
                return False
    return True

def get_matrix():
    n = int(input("Enter size of matrix: "))
    matrix = []
    for i in range(n):
        row = input("Enter row " + str(i+1) + ": ")
        row = [int(x) for x in row.split()]
        matrix.append(row)
    return matrix

matrix = get_matrix()

if complete_graph(matrix):
    print("Graph is complete.")
else:
    print("Graph is not complete.")




relation
class Relation:
    def get_matrix():
        rows= int(input("enter no. of rows "))
        columns = int(input("enter no. of columns "))
        mat = []
        for i in range(rows):
            r = []
            for j in range(columns):
                r.append(int(input()))
            mat.append(r)
        for i in range (rows):
            for j in range (columns):
                print(mat[i][j], end ='')
            print()    

    def _init_(self,matrix):
        
        self.matrix = matrix
        self.R = 0
        self.A = 0
        self.T = 0
        self.S = 0

    def is_reflexive(self):
        
        n = len(self.matrix)
        for i in range(n):
            if self.matrix[i][i] == 0:
                return False
        self.R += 1
        return True


    def is_symmetric(self):
        
        n = len(self.matrix)
        for i in range(n):
            for j in range(n):
                if self.matrix[i][j] != self.matrix[j][i]:
                    return False
        self.S += 1
        return True

    def is_transitive(self):
        
        n = len(self.matrix)
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    if self.matrix[i][j] == 1 and self.matrix[j][k] == 1 and self.matrix[i][k] == 0:
                        return False
        self.T += 1
        return True
    def is_antisymmetric(self):
        n=len(self.matrix)
        for i in range(n):
            for j in range(n):
                if (self.matrix[i][j]==self.matrix[j][i]) and (i!=j):
                    return False
        self.A += 1
        return True 
    def eq_relation(self):
        if self.R == 1 and self.S == 1 and self.T == 1:
            return True
        return False

    def por(self):
        if self.R == 1 and self.A == 1 and self.T == 1:
            return True
        return False
    
matrix = [
    [1, 0, 1],
    [0, 1, 0],
    [1, 0, 1]
]
relation = Relation(matrix) 
relation.get_matrix()

print("Is reflexive:", relation.is_reflexive())
print("Is symmetric:", relation.is_symmetric())
print("Is transitive:", relation.is_transitive())
print("is antisymmetric", relation.is_antisymmetric())
print("is eq", relation.eq_relation())
print("is por", relation.por())




polyclass
class poly:
    def _init_(self,cx2,cx,c):
        self.lst = [c, cx, cx2]

    def add(self,other):
        m = self.lst
        n = other.lst
        l = []
        j = min(len(m),len(n))
        for i in range(j):
            l.append(m[i]+n[i])
        if len(m)>len(n):
            l.extend(m[j:])
        else:
            l.extend(n[j:])
        return poly(*l)

    def sub(self,other):
        m = self.lst
        n = other.lst
        l = []
        j = min(len(m),len(n))
        for i in range(j):
            l.append(m[i]-n[i])
        if len(m)>len(n):
            l.extend(m[j:])
        else:
            l.extend(-1*i for i in n[j:])
        return poly(*l)

    def val(self,x):
        value = 0
        value = sum(x**i * self.lst[i] for i in range(len(self.lst)))
        return value

    def display(self):
        print(self.lst[2],"x^2", self.lst[1],"x",self.lst[0])

p1 = poly(2,3,5)
p2 = poly(4,3,7)
p3 = p1.add(p2)
p4 = p1.sub(p2)
p1.display()  # prints "2 x^2 3 x 5"
p2.display()  # prints "4 x^2 3 x 7"
p3.display()  # prints "6 x^2 6 x 12"
p4.display()  # prints "2 x^2 -3 x -2"
print(p3.val(2))  # prints 64
print(p4.val(3))  # prints 29


  
  adjclass
def adj_list(lst1):
    new_lst=[]
    for i in range(len(lst1)):
        lst2=[]
        for j in range(len(lst1)):
            print("Enter 1 if edge {",lst1[i],",",lst1[j],"} is in graph else 0")
            num=int(input())
            if num==1:
                lst2.append(lst1[j])
            else:
                continue
        new_lst.append(lst2)
    return new_lst
def check_comp(a,graph):
    flag = True
    for i in range(len(a)):
        for j in range(len(a)):
             if a[i]!=a[j] and graph[i] in a[i]:
                 flag=False
    if flag==True:
         print("given graph is complete")
    else:
         print("given graph is not complete")
num=int(input("Enter the number of vertex:"))
vertex=[]
for i in range(num):
    p=input("Enter vertex:")
    vertex.append(p)
graph=adj_list(vertex)
check_comp(graph,vertex)



  

