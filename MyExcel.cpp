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
  int to_numeric(const string& s);
  int to_numeric(int row, int col);
  string stringify(const string& s);
  string stringify(int row, int col);

  virtual string print_table() = 0;
};