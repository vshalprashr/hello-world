if __name__ == '__main__':
	n = int(input())
	arr = list(map(int,input().strip().split()))[:n]
	arr.sort()
	res=0
	for i in range(n-1,-1,-1):
		res = ((res*2) + arr[i])%1000000007
	print(res)
