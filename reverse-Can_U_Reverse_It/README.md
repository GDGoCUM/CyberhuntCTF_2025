![Reverse Engineering](https://img.shields.io/badge/Category-Reverse_Engineering-blue)  

### Write up

# I refer to imaginary ctf (unconditional) ( 99% same with it ) 

1. decode the base64 file and save it in a temp file
```bash
base64 -d suspicious.txt > temp 
```

2. make it executable
```bash
chmod +x temp
```

3. use ida to anlaysis and u will find many iteration 

4. basically we just brute force all the printable character and passed in to the encrypt funciton , make sure take only two digits .

This is my own script , if u find others solution more better can refer to it . Hope u learn smtg .  

```python
output = [0x34, 0x27, 0xCD, 0x10, 0xAF, 0x16, 0x19, 0x36, 0x98, 0x7D, 0x43, 0x17, 0x34, 0x33, 0xB3, 0xCC,
0xA6, 0x06, 0x1D, 0x28, 0x19, 0x7D, 0xA3, 0xC0, 0x85, 0x3E, 0x2C, 0x0D, 0xA6, 0x12, 0x58, 0x38,
0x0B,]

data1 = [0x52, 0x64, 0x71, 0x51, 0x54, 0x76]

data2 = [1,3,4,2,6,5]

count1 = 0
count2 = 0

for out in range (0,len(output)):
    for ch in range (32,128):
        res=''
        check1 = out % 2
        ff1 = ch>0x60 and ch<0x7b

        if check1:
            if ff1:
                res = ch ^ data1[count1] 
            else:
                res = ((ch << 2) | (ch >> (8 - 2))) 
        else:
            if ff1:
                res = ((ch >> data2[count2]) | (ch << (8 - data2[count2]))) 
            else :
                res = (((ch >> 2) | (ch << (8 - 2)))) ^ data1[count1]

        cmp=''
        if(len(hex(output[out])) <= 3):
            cmp = "0"+str(hex(output[out]))[len(hex(output[out]))-1]
        else:
            cmp = str(hex(output[out]))[-2:]
        
        temp=''
        if(len(hex(res)) <= 3):
            temp = "0"+str(hex(res))[len(hex(res))-1]
        else:
            temp = str(hex(res))[-2:]

        if cmp == temp :
            if (ch >= 65 and  ch <= 90):
                continue
            elif (ch >= 33 and ch <= 47):
                continue
            else:
                print(chr(ch),end='')
            break

    count1 = (count1 + check1) % 6
    count2 = (count2 + check1) % 6
```
