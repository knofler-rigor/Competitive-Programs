class Solution:
    def minFlips(self, s: str) -> int:
        s=[int(i) for i in s]
        odd=[0,0] 
        even=[0,0] 
        for i in range(len(s)):
            if(i%2==0):
                even[s[i]]+=1 
            else:
                odd[s[i]]+=1
        evencount=(len(s)+1)//2 
        oddcount=len(s)//2
		
        ans=min((evencount-even[0])+(oddcount-odd[1]),(evencount-even[1])+(oddcount-odd[0]))
        if(len(s)%2==0):return ans 
        for i in range(len(s)):
            even[s[i]]-=1 
            odd[s[i]]+=1
            odd,even=even,odd 
            ans=min(evencount-even[0]+oddcount-odd[1],evencount-even[1]+oddcount-odd[0],ans) 
        return ans
    
