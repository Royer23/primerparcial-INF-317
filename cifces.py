# -*- coding: utf-8 -*-
"""
Created on Sat Jul 11 22:59:52 2020

@author: Royer Cesar Alanis Flores
ALANIS FLORES ROYER CESAR
8449437 LP
INF-317
PRIMER PARCIAL EJERCICIO 2
CIFRADO DE CESAR EN PYTHON
"""


cif="ROYER CESAR ALANIS FLORES"
l=len(cif)
print(cif)
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
