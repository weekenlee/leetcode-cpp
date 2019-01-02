local buff=""
for i  = 1, 100000 do
    buff = buff .. tostring(i)
end
print(buff)

local buff={}
for i = 1, 100000 do
    buff[i]=tostring(i)
end
print(table.concat(buff))

