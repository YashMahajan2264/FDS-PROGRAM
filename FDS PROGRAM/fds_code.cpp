print ("******FDS EXAM ANALYSIS******") 
marklist=[] 
n=int(input("Enter the number of student :")) 
print("Enter the marks out of 100") 
print("Enter -1 for absent student") 
for i in range (n): 
   mark=int(input(f"Enter the marks of student {i+1}:")) 
   marklist.append(mark) 
 
total=0 
max_val=marklist[0] 
min_val=marklist[0] 
frequency=[] 
absent_student=0 
for mark in marklist: 
  if mark==(-1): 
    absent_student+=1 
  elif mark<min_val: 
    min_val=mark 
  else: 
    total+=mark 
for mark in marklist: 
  if 100>max_val<mark: 
    max_val=mark 
 
for i in range(0,n): 
  icount=0 
  imarks=marklist[i] 
  for j in range(0,n): 
    if(marklist[j]==imarks): 
     icount=icount+1 
     frequency.append(icount) 
highest_frequency=frequency[0] 
loc=0 
for i in range(0,n): 
  if(frequency[i]>highest_frequency): 
    highest_frequency=frequency[i] 
    loc=i 
hf=marklist[loc] 
 
print(f"average marks of the subject={total/len(marklist)}") 
print(f"Maximum marks in subject is {max_val} and minimum marks in subject is {min_val}") 
print(f"number of absent student= {absent_student}") 
print("mark with highest frequency:",hf)
