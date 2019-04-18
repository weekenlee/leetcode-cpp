#include <xlnt/xlnt.hpp>

int main() {
    xlnt::workbook wb;
    for (int i = 0 ; i < 15 ; i++) {
        xlnt::worksheet ws = wb.create_sheet();
        ws.cell("A1").value(5);
    }
    wb.save("example.xlsx");
    return 0;
}
