#include <xlnt/xlnt.hpp>

int main() {
    xlnt::workbook wb;
    xlnt::worksheet ws = wb.active_sheet();
    ws.cell("A1").value(5);
    ws.cell("A2").value("你好");
    ws.cell("B2").formula("=RAND()");
    wb.save("example.xlsx");
    return 0;
}
