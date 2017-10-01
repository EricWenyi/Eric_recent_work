import math

def subsequence(sub):
	if len(sub) == 0:
		return 0
	if len(sub) == 1:
		return sub[0]
	temp = len(sub) * min(sub)
	return max(temp, subsequence(sub[:(len(sub)/2)]), subsequence(sub[(len(sub)/2):]))



if __name__ == "__main__":
	sequence = [1,11,12,5]
	res = subsequence(sequence)
	print(res)