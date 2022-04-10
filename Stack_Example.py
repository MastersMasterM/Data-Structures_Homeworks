def push(arr,el,n,inp):
    for i in range(n-el,n):
        arr[i - 1]=arr[i]
    arr[n-1] = inp
def pop(arr,el,n):
    temp = arr[n-1]
    for i in range(n-1,n-el,-1):
        arr[i]=arr[i - 1]
    return temp
num = int(input())
string = input()
element = 0
stack = ['a'] * num
res = [0 for x in range(2 * num)]
j=0
for i in string:
    if(i == '('):
        push(stack,element,num,j)
        element = element + 1
    else:
        out = pop(stack,element,num)
        res[out] = j + 1
        res[j] = out + 1
        element = element - 1
    j = j + 1
for el in res:
    print(el,end=" ")
