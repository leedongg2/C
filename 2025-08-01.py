# from tkinter import *
# from random import *
# from time import *
# def success():
#     result.set('성공!')
# def peg(event):
#     window.after(142,pe)
# def pe():
#     x=randint(0,window.winfo_width())
#     y=randint(0,window.winfo_height())
#     btn.place(x=x,y=y)
#
# window=Tk()
# window.title('bt')
# result=StringVar()
# result.set('진행중')
# label=Label(window,textvariable=result)
# label.pack()
# btn=Button(window,text='눌러봐라',command=success)
# btn.place(x=100,y=100)
# btn.bind("<Enter>",peg)
# window.mainloop()




from tkinter import *
from time import *
def calculate():
    fir=entry.get()
    sec=entry1.get()
    gae=spin.get()
    if gae=="+":
        result=int(fir)+int(sec)
    if gae=="-":
        result=int(fir)-int(sec)
    if gae=="x":
        result=int(fir)*int(sec)
    if gae=="÷":
        result=int(fir)/int(sec)
    if gae=="나머지":
        result=int(fir)%int(sec)
    counter.set(result)
def eras():
    entry.delete(0,END)
    entry1.delete(0,END)
    counter.set(0)
window = Tk()
window.title('gaysange')
counter=IntVar()
label=Label(window, textvariable=counter)
label.pack()
entry=Entry(window)
entry.place(x=100,y=150)
entry1=Entry(window)
entry1.place(x=500,y=150)
choose=["+","-","x","÷","나머지"]
spin=Spinbox(window, values=choose)
spin.place(x=300,y=150)
btn=Button(window, text='계산',command=calculate)
btn.place(x=800,y=150)
erbt=Button(window, text='모두 지우기',command=eras)
erbt.place(x=300,y=300)
window.mainloop()
