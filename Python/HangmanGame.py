import random
with open ("words.txt","r") as file:
    line=file.readlines()
    
    
#wordbank=["pancakes","optimum","kindled","painter","violin","newton","amsterdam","lotus","joker"]
#word=wordbank[random.randint(0,len(wordbank)-1)]
    
word=line[random.randint(0,len(line)-1)]
guessword=" "*len(word)
S1="HANGMAN"
chance=7
while(chance!=0 and guessword!=word):
    letter=input("guess letter\t").lower()
    if letter in word:
     for i in range(len(word)):
      if word[i]==letter:
          guessword=guessword[:i] + letter + guessword[i+1:]
    else:
         chance-=1
         print("YOU ARE " + S1[0:7-chance])
         print("chances left=",chance)
    print(guessword)

if chance>0 :
    print("you won !")
else:
    print("The word was :",word,"\n you lost!")
