#ifdef MATRIX_LOADED
//Ist bereits geladen
#else
#define MATRIX_LOADED
class Matrix
{
public:
	Matrix(int m, int n);
	virtual ~Matrix();
	// Gibt alle Element der Matrix aus
	virtual void ausgabe() const;
	static int getCounter();
	void operator=(Matrix const & alteMatrix);
	double operator()(int i, int j)const ;
protected:
	// Maximale Anzahl Zeilen
	int m_Zeilen;
	// Maximale Anzahl Spalten
	int m_Spalten;
	// Zeigt auf die Array Fläche
	double* m_Element;
private:
	static int counter;
};
#endif
