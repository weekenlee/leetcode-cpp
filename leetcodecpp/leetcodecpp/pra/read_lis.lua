local function readFile(fileName)
    local f = assert(io.open(fileName,'r'))
    local c = {}
    for i in f:lines() do
        table.insert(c,i)
    end
    f:close()
    return c
end

print(readFile("电厂侧合甲线a相重合闸.lis"))
print(readFile("电厂侧合甲线a相重合闸.lis"))
print(readFile("电厂侧合甲线a相重合闸.lis"))