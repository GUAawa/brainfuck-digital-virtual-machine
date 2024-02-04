path = "D:/桌面/source_code"

bf_code = '''
,>,>,.<.<.
'''
hex_code = "v2.0 raw\n"

dictionary = {"<>+-,.[]"[i]:str(i) for i in range(8)}

for char in bf_code:
    if char not in dictionary:
        continue
    hex_code += dictionary[char] + ' '

with open(path,'w',encoding='utf-8') as f:
    f.write(hex_code)

print("十六进制码")
print(hex_code)
print("源码")
print(bf_code)
print("已烧录在 %s"%path)