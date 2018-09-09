class Temperature
{
public:
	Temperature();
	Temperature(double degr,char temptype);
	void Input();
	void Show() const;
	bool Set(double deg, char s);
	double GetDegrees() const;
	char GetScale() const;
	bool SetFormat(char f);
	bool Convert (char sc);
	int Compare(const Temperature& d) const;
	double CompareUtility() const;
	void Increment(int deg, char sc);
private:
	double degree;
	char formsoftemp;
	char format;
};
	
	
