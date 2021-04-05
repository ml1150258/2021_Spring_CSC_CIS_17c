#include "RowAray.h"

template<class T>
class Table{
    protected:
        int szRow;
        int szCol;
        RowAray<T> **columns;
    public:
        Table(unsigned int rows,unsigned int cols)
        {
            szRow = rows;
            szCol = cols;
            columns = new RowAray<T>*[cols];
            for(int i = 0; i < szRow; i++)
            {
                columns[i] = new RowAray<T>(szCol);
            }  
        }
        Table(const Table<T> &tabCopy)
        {
            szRow = tabCopy.szRow;
            szCol = tabCopy.szCol;
            columns = new RowAray<T>*[tabCopy.szRow];
            for(int i = 0; i < szRow; i++)
            {
                columns[i] = new RowAray<T>(szCol);
            }
            for(int i = 0; i < szRow; i++)
            {
                for(int j = 0; j < szCol; j++)
                {
                    setData(i, j, tabCopy.getData(i, j));
                }   
            }  
        }
        ~Table();
        int getSzRow()const {return szRow;}
        int getSzCol()const {return szCol;}
        T getData(int,int)const;
        void setData(int row,int col,T data)
        {
            columns[row]->setData(col,data);   
        }
        Table<T> operator+(const Table<T> &);
};