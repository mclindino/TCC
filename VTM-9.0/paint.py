import pandas as pd
from tkinter import *

df = pd.read_csv("paint.csv", header=None)
df.columns = ['height', 'width', 'tl_x', 'tl_y', 'br_x', 'br_y', 'gop', 'qt', 'mt']
root = Tk()
w_root = Canvas(root, width=int(df['width'][0]), height=int(df['height'][0]))

for index, row in df.iterrows():
    if(int(row['gop']) == 3):
    	if(int(row['qt'] == 0)):
    		w_root.create_rectangle(int(row['tl_x']), int(row['tl_y']), int(row['br_x']), int(row['br_y']), fill='green')
    	if(int(row['qt'] == 1)):
    		w_root.create_rectangle(int(row['tl_x']), int(row['tl_y']), int(row['br_x']), int(row['br_y']), fill='blue')
    	if(int(row['qt'] == 2)):
    		w_root.create_rectangle(int(row['tl_x']), int(row['tl_y']), int(row['br_x']), int(row['br_y']), fill='red')
    	if(int(row['qt'] == 3)):
    		w_root.create_rectangle(int(row['tl_x']), int(row['tl_y']), int(row['br_x']), int(row['br_y']), fill='yellow')
    	if(int(row['qt'] == 4)):
    		w_root.create_rectangle(int(row['tl_x']), int(row['tl_y']), int(row['br_x']), int(row['br_y']), fill='orange')
w_root.pack()
mainloop()