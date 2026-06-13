def transpose(l):
   #****allocation****
   ln=[]
   for i in range (0,len(l[0])):
       ln.append([])
   for i in range (0,len(l[0])):
      for k in range (0,len(l)):
       ln[i].append([])
  #****computation****

   for i in range (0,len(l[0])):
      for k in range (0,len(l)):
       ln[i][k]=l[k][i]

   return (ln)
print(transpose([[1,2,3,4],[5,6,7,8]]))
