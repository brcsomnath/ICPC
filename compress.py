file = open('example.txt', 'r')
s=file.read()
num = map(int, s.split())
n=0

for i in range(0,len(num)-1,2):
	d1=num[i]
	d2=num[i+1]
	dk=((d2<<8))+(d1)
	n=n+dk
	print n
