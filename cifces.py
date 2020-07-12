"""
Created on Sat Jul 11 22:59:52 2020

@author: Royer Cesar Alanis Flores
"""


cif="ROYER CESAR ALANIS FLORES"
l=len(cif)
ces=""
for i in range(l):
    if(cif[i]==' '):
        ces=ces+cif[i]
    else:
        if(ord(cif[i])+5<=90):
            char=ord(cif[i])+5
        else:
            char=64+((ord(cif[i])+5)%90)
        
        ces=ces+chr(char)
print (ces)
