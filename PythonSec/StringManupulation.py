def IsCharacterinString(msg,char):
	for i in msg:
		if i == char:
			return True
	return false

def CountOccurence(msg,char):
	count = 0
	for i in msg:
		if i == char:
			count += 1
	return count

def ReplaceCharInString(msg,str1,str2,delim=' '):
	if len(str1) == 1:		
		s = list(msg)
		for i in range(0,len(msg)):
			if s[i] == str1:
				s[i] = str2
		changedMessage = ''.join(s)
		return changedMessage
	
	elif len(str1) > 1 :
		words = list(msg.split(delim))
		print(words)
		res = [elem if elem != str1 else str2 for elem in words]
		print(res)
		changedMessage = " ".join(res)
		return changedMessage
		 				
def main():
	msg = input("Enter the String :: ")
	char = input("Enter the Character to be searched :: ")
	if IsCharacterinString(msg,char) == True :
		print("The Character is present") 
	else: 
		print("Character is not present in the given string")
	print("Character appeared in the message ", CountOccurence(msg,char), " times")
	char1 = input("Enter the Character to be replaced:: ")
	char2 = input("Enter the Character to replace :: ")
	print("String after Manupulation:: ")
	print(ReplaceCharInString(msg,char1,char2))
	
if __name__ == "__main__":
	main()
	
