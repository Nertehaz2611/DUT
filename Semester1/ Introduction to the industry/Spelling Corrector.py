from textblob import TextBlob
from tkinter import *
#Function to check the spelling and show the corrected spelling
def checkSpelling():
 a = text.get() #Getting the word user entered
 b = TextBlob(a) #Getting the object for the word
 correctedText.set("The corrected word is: "+str(b.correct())) #Showing the corrected word
#Creating the window
wn = Tk()
wn.title("DataFlair Spell Checker")
wn.geometry('500x250')
wn.config(bg='SlateGray1')
#Creating the variables to get the word and set the correct word
text=StringVar(wn)
correctedText =StringVar(wn)

#The main label
Label(wn, text='DataFlair Spell Checker',bg='SlateGray1',
fg='gray30', font=('Times', 20,'bold')).place(x=130, y=10)

#Getting the input of word from the user
Label(wn, text='Please enter the word',bg='SlateGray1',font=('calibre',13,'normal'), anchor="e", justify=CENTER).place(x=160, y=70)

Entry(wn,textvariable=text, bg='white', width=35,font=('calibre',13,'normal')).place(x=70,y=110)
#Label to show the correct word 
opLabel = Label(wn, textvariable=correctedText,fg='black',anchor="e",font=('calibre',13,'normal'), justify=LEFT).place(x=132, y=150)

#Button to do the spell check
Button(wn, text="Click Me", bg='SlateGray4',font=('calibre', 13),
command=checkSpelling).place(x=180, y=190)

#Runs the window till it is closed by the user
wn.mainloop()