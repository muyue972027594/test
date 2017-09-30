#!/usr/bin/python3


#print("**********\n*        *\n*        *\n**********")


'''
name = input("请输入姓名")
age = input("请输入年龄")
print("%s,%d"%(name,int(age)))

'''


'''
high = input("请输入身高(cm)")
print("身高%.2f英尺"%(float(high)/2.54))

'''


'''
num = input("\
        1.站点a->\n\
        2.站点b->\n\
        3.站点c->\n\
        4.站点d->\n请输入目的站点的编号")
print("价格%.2f"%(int(num)*0.5))

'''

'''
num = input("请输入一个整数\n>>>>>>")
i = 2
while i <= int(num) / 2:
    if 0 == int(num) % i:
        break
    i += 1

if i > int(num) / 2:
    print(num + "是素数")
else:
    print(num + "不是素数")
'''

'''
num = input("请输入您的用电量\n>>>>>>>")
if int(num) < 170:
#    print(num + "度电，需交费 " + str(int(num) * 0.477) + " 元")
    print("%s 度电，需交费 %.2f 元"%(num,(int(num) * 0.477)))
elif int(num) < 260:
#    print(num + "度电，需交费 " + str(int(num) * 0.527) + " 元")
    print("%s 度电，需交费 %.2f 元"%(num,(int(num) * 0.527)))
else:
#    print(num + "度电，需交费 " + str(int(num) * 0.777) + " 元")
    print("%s 度电，需交费 %.2f 元"%(num,(int(num) * 0.777)))
'''


'''
a = [11,22,24,29,30,32]
print(a)

a.append(28)
print(a)

a.insert(a.index(29) + 1,57)
print(a)

a[a.index(11)] = 6
print(a)

a.remove(32)
print(a)

a.sort()
print(a)

'''

'''
b = [1,2,3,4,5]

b1 = b + [6,7,8]
print(b1)

b2 = b + list(range(6,9))
print(b2)

b.append(6)
b.append(7)
b.append(8)
print(b)

print(b[4:2:-1])

b3 = b[3:5]
b3.reverse()
print(b3)

if 2 in b:
    print("在")
else:
    print("不在")

'''


'''
b = [23,45,22,44,25,66,78]

b11 = []
for x in b:
    if x % 2 != 0:
        b11.append(x)
print(b11)

b12 = []
for x in b[:2]:
    b12.append('the content ' + str(x))

print(b12)

b13 = []
for x in b[:2]:
    b13.append(''.join(['the content ',str(x)]))

print(b13)

i = 0
b14 = []
for x in b:
    b14.append(x + 2)
print(b)
print(b14)

for x in b:
    b[i] = x + 2
    i += 1
print(b)

'''



print(list(range(11,40,11)))

a = [i * 10 + i for i in range(1,4)]
print(a)







