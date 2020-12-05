
mean=0
xi=[70,120,100]
n=len(xi)
for i in xi:
    mean+=i
mean/=n
sumOfXiminusMean=0
print("Mean:",mean)
for i in xi:
    print((i-mean)**2)
    sumOfXiminusMean+=(i-mean)**2
print(sumOfXiminusMean/(n-1))
''' class Test:
    #docstring
    """This is test"""
    def __init__(self):
        self.a=10;
        self.b=20;
        self.c=30;
    def m1(self):
        self.d=40;
    def m2(self):
        self.e=50;
    def printAll(self):
        print("From class",self.__dict__)
t1=Test()
print(Test.__doc__)
print(t1.__doc__)
t1.m1()
t2=Test()
t2.m2()
t2.printAll()
t2.x=100
t2.y=200
t2.printAll()
print(t1.__dict__)
print(t2.__dict__) '''
""" words=["go","come","sit"]
letters=['g','o']
for word in words:
    flag=True
    for letter in word:
        if letter not in letters:
            flag=False
            break
    if flag:
        print(word) """
""" inputt=[int(_) for _ in input().split()]
r=list()
zeroes=0
for value in inputt:
    if value!=0:
        r.append(value)
    else:
        zeroes+=1
for i in range(zeroes):
    r.append(0);
print(r) """