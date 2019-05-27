require("luacom")
require("lfs")
local path=lfs.currentdir()
print(path)

local excel = luacom.CreateObject("Excel.Application")
local book =excel.Workbooks:Add()
local sheet = book.Sheets(1)
sheet.Cells(1, 1).Value2 = "ÄãºÃ"

book:SaveAs(path.."\\test.xlsx")
book:Close()
