#!/usr/bin/python3


'''
a = (1,4,5,6,7)

#判断元素4是否在元组里
if 4 in a:
    print("在")
else:
    print("不再")

#把元素5修改成8
print(a)
b = list(a)
b[b.index(5)] = 8
a = tuple(b)
print(a)

'''



'''
#将a字符串的数字取出，并输出成一个新的字符串
a = input("请输入一个字符串\n")

b = "".join(x for x in a if x.isdigit())

print(a)
print(b)

'''


'''
#统计a字符串出现的每个字母的出现次数
a = "absdDababsbasba"
#a1 = ""
#for x in a:
#    if x >= 'A' and x <= 'Z':
#        x = x.swapcase()
#    a1 += x
a1 = a.lower()
b = {x:a1.count(x) for x in set(a1)}
print(a)
print(b)

'''



'''
#字符串多次出现的字母，仅留最先出现的一个

a = "acdacddddffa"
print(a)
print(''.join(x for x in set(a)))

'''

'''

#将a字符串反转并输出
a = "asdfgh"

print(a[::-1])
'''

'''
#字典练习



ainfo = {'ab':'liming','ac':20}

#添加
ainfo['sex'] = 'man'
ainfo.update(dict(age=20))

print(ainfo)

#输出结果：['ab','ac']

b = [x for x in ainfo.keys() if len(x) < 3]
print(b)


#输出结果：['liming',20]

c = [ainfo[y] for y in [x for x in ainfo.keys() if len(x) < 3]]
print (c)


#返回键名ab对应的值

print(ainfo['ab'])
print(ainfo.get('ab'))



#删除键名ac对应的值

print(ainfo.pop('ac'))

#del ainfo['ac']

print(ainfo)



'''




'''

#元组

a = (1,2,3)


#实现(5,2,3)
b = list(a)
b[0] = 5
a = tuple(b)

print(a)



#判断2是否在元组里

if 2 in a:
    print("在")
else:
    print("不再")

'''



'''
#集合

a = set(['a','b','c'])
b = set(['b','e','f','g'])
a.add('jay')

print(a)

#for x in b:
#    a.add(x)

a = set(list(a)+list(b))

print(a)

'''



'''
#输出结果：[1 love python,2 love python,3 love python,.... 10 love python]

a = [str(x) + ' love python' for x in range(1,11)]

print(a)


#输出结果：[(0,0),(0,2),(2,0),(2,2)]

b = [(x,y) for x in (0,2) for y in (0,2)]
print(b)

'''

a = [1,2,3]
b = a[:]

print(b)

del a
print(b)







