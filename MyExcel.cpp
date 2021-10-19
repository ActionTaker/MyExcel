#include "utils.h"
class Table;
class Cell {
 protected:
  int x, y;
  Table* table;
  MyString data;
 public:
  virtual const MyString& stringify();
  virtual int to_numeric();
  Cell(MyString data, int x, int y, Table* table);
};

Cell::Cell(MyString data, int x, int y, Table* table):data(data), x(x), y(y), table(table) {}
const MyString& Cell:: stringify() {return data;}
int Cell::to_numeric() {return 0;}

class Table {
 protected:
  int max_row_size, max_col_size;
  Cell*** data_table; 
 public:
  Table(int max_row_size, int max_col_size);
  ~Table();
  void reg_cell(Cell* c, int row, int col);
  int to_numeric(const MyString& s);
  int to_numeric(int row, int col);
  string stringify(const string& s);
  string stringify(int row, int col);
  virtual string print_table() = 0;
};
Table::Table(int max_row_size, int max_col_size)
{
  data_table = new Cell**[max_row_size];
  for(int i = 0; i < max_row_size; i++)
  {
    data_table[i] = new Cell*[max_col_size];
    for(int j = 0; j < max_col_size; j++)
      data_table[i][j] = NULL;
  }
}
Table::~Table()
{
  for(int i = 0; i < max_row_size; i++)
  {
    for(int j = 0; j < max_col_size; j++)
      if(data_table[i][j]) delete data_table[i][j];
    delete[] data_table[i];
  }
  delete[] data_table;
}
void Table::reg_cell(Cell* c, int row, int col) {
  if (data_table[row][col]) {
    delete data_table[row][col];
  }
  data_table[row][col] = c;
}
int Table::to_numeric(const MyString& s) { //s를 상수화 시켜서 받았으니 s 에서는 무조건 const 함수만 호출가능
  int col = s[0] - 'A';
  int row = s[1] - '1' + 1;
  if (data_table[row][col]) return data_table[row][col]->to_numeric();
  return 0;
}