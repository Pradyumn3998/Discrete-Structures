'''
Counts the number of unique elements in two strings

@author : Ausaaf Nabi
@call   : CountUniqueChar(str1, str2, [verbose=1,2,..])
@param  : str1,str2: strings, verbose: int [1 or 2 ,redirects if >2 to 1]
@return : UniqueChar: int
'''
def CountUniqueChar(str1: str,str2: str,verbose=1)->int:
	str1,str2 = str1.lower(),str2.lower()
	if verbose == 1:
		str1,str2 = set(str1),set(str2)
		return len(str1.intersection(str2))
	elif verbose == 2:
		count = 0
		UniqueChar = []
		for i in max(str1,str2):
			if(i not in UniqueChar):
				UniqueChar.append(i)
				
		for char in UniqueChar:
			str1_count = str1.count(char)
			str2_count = str2.count(char)
			count += min([str1_count,str2_count])
		return count
			
	else:
		print("Redirecting to Verbose 1 | Using Sets")
		return CountUniqueChar(str1,str2,verbose=1)

def main():
	str1 = input("Enter String 1:: ")
	str2 = input("Enter String 2:: ")
	print("No. Of Unique Elements in the string are :: ", CountUniqueChar(str1,str2,2))

if __name__ == "__main__":
	main()
