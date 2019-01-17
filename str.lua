print(string.gsub("a (ooo) (000) b", "%b()", ""))
s = [[then he said: "it's all right!"]]
a, b, c, quotedPart = string.find(s, "([\"'])(.-)%1")
print(a)
print(b)
print(c)
print(quotedPart)
print(string.gsub("hello lua", "(%a)", "%1-%1"))

s = "\\command{some text}"
s = string.gsub(s, "\\(%a+){(.-)}", "<%1>%2<%1>")
print(s)

function expand(s)
    return (string.gsub(s, "$(%w+)", function(n)
        return tostring(_G[n])
    end))
end

a = 1
print(expand("print = $print; a = $a"))
print(_G.a)
print(_G['a'])
print(_G.bbb)
