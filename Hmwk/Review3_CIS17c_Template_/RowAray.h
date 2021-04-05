

template<class T>
class RowAray
{
    protected:
        int size;
        T *rowData;
    public:
        RowAray(int rowSz)
        {
            size = rowSz;
            rowData = new T [rowSz];
            
            for(int i = 0; i < rowSz; i++)
            {
                rowData[i] = static_cast<T>(rand() % 100);
            }
        }
        virtual ~RowAray() { delete[] rowData;}
        int getSize()const{return size;}
        T getData(int i)const{
            if(i>=0&&i<size)return rowData[i];
            else return 0;}
        void setData(int,T);
};