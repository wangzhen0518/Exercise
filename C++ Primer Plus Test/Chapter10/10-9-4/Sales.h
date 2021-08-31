namespace SALES
{
    class Sales
    {
    private:
        static const int QUARTERS = 4;
        double m_sales[QUARTERS];
        double m_average;
        double m_max;
        double m_min;

    public:
        Sales(const double ar[] = {0}, int n = 4);
        ~Sales();
        void set();
        void show() const;
    };

} // namespace SALES
