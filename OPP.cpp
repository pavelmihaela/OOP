

#include <iostream>
#include<string>
using namespace std;


class Culoare {

protected:
	char* nume;
	const string hexa;
	float opacitate;
	int nr_culori;//numarul de culori care duce la aparitaia acestei culori
	float* vector_culori;//reprezita procentul din  fiecare culoare primara necesar pt a obtine o noua culoare scris 
	//sub forma x/100. Ex: 20%=0.2

public:
	/*//Cerinta 1

	Culoare() :hexa("")
	{
		this->nume = new char[strlen("Necunoscut") + 1];
		strcpy(this->nume, "Necunoscut");
		this->opacitate = 0;
		this->nr_culori = 0;
		this->vector_culori = NULL;
	}
	Culoare(const string v_hexa ,char* v_nume, float v_opacitate, int v_nr_culori, float* v_vector_culori) :hexa( v_hexa)
	{
		if (v_nume != NULL)
		{
			this->nume = new char[strlen(v_nume) + 1];
			strcpy(this->nume, v_nume);
		}
		this->opacitate = v_opacitate;
		this->nr_culori = v_nr_culori;
		if (v_vector_culori != NULL) {
			this->vector_culori = new float[this->nr_culori];
			for (int i = 0; i < this->nr_culori; i++) {
				this->vector_culori[i] = v_vector_culori[i];

			}
		}
	}

	void Afisare()
	{
		cout << endl << "Afisare culoare: " << endl;
		cout << "Cod hexa: "<<this->hexa << endl;
		cout << "Nume: " << this->nume << endl;
		cout << "Opacitate: " << this->opacitate << endl;
		cout << "Nr. culori: " << this->nr_culori << endl;
		for (int i = 0; i < this->nr_culori; i++)
			cout << "Culoarea " <<i+1<<" se afla in procentajul: "<< this->vector_culori[i]*100<<"%" << endl;
	}
	~Culoare()
	{
		cout << "Apel destructor! ";
		if (this->nume != NULL)
		{
			delete[] this->nume;
		}
		if (this->vector_culori != NULL)
		{
			delete[] this->vector_culori;
		}
	}
	Culoare(const Culoare& copie) :hexa(copie.hexa)
	{
		if (copie.nume != NULL) {
			this->nume = new char[strlen(copie.nume) + 1];
			strcpy(this->nume, copie.nume);
		}
		if (copie.opacitate > 0)
		{
			this->opacitate = copie.opacitate;
		}
		this->nr_culori = copie.nr_culori;
		if (copie.nr_culori != NULL)
		{
			this->vector_culori = new float[this->nr_culori];
			for (int i = 0; i < this->nr_culori; i++) {
				this->vector_culori[i] = copie.vector_culori[i];
			}

		}
	}
	char* getNume()
	{
		if (this->nume != NULL) {
			return this->nume;
		}

	}
	void setNume(char* v_nume)
	{
		if (v_nume != NULL)
		{
			this->nume = new char[strlen(v_nume) + 1];
			strcpy(this->nume, v_nume);
		}
	}
	float getOpacitate()
	{
		if (this->opacitate > 0) {
			return this->opacitate;
		}
	}
	void setOpacitate(float v_opacitate)
	{
		if (v_opacitate > 0)
		{
			this->opacitate = v_opacitate;
		}
	}
	int getNrCulori()
	{
		return this->nr_culori;
	}
	void setNrCulori(int v_nr_culori) {
		this->nr_culori = v_nr_culori;
	}
	void setVectorCulori(float* v_vector_culori, int v_nr_culori)
	{
		this->nr_culori = v_nr_culori;
		this->vector_culori = new float[this->nr_culori];
		for (int i = 0; i < this->nr_culori; i++)
		{
			this->vector_culori[i] = v_vector_culori[i];
		}
	}
	float* getVectorCulori()
	{
		return this->vector_culori;
	}


	//Cerinta 2

	Culoare& operator=(const Culoare& culoare)
	{
		if (culoare.nume != NULL)
		{
			this->nume = new char[strlen(culoare.nume) + 1];
			strcpy(this->nume, culoare.nume);
		}
		if (culoare.opacitate > 0)
		{
			this->opacitate = culoare.opacitate;
		}
		this->nr_culori = culoare.nr_culori;
		if (culoare.nr_culori != NULL)
		{
			this->vector_culori = new float[this->nr_culori];
			for (int i = 0; i < this->nr_culori; i++) {
				this->vector_culori[i] = culoare.vector_culori[i];
			}

		}
		return*this;
	}

	friend istream& operator>>(istream& in, Culoare& culoare)
	{
		cout << "Citire date: " << endl;
		cout << "Nume: " << endl;
		char buf[50];
		in.getline(buf, 50);
		if (culoare.nume != NULL)
		{
			delete[] culoare.nume;
		}
		culoare.nume = new char[strlen(buf) + 1];
		strcpy(culoare.nume, buf);
		cout << "Opacitate: " << endl;
		in >> culoare.opacitate;
		cout << "Nr. culori: " << endl;
		in >> culoare.nr_culori;
		cout << "Vector culori: " << endl;

		if (culoare.vector_culori != NULL )
		{
			delete[] culoare.vector_culori;
		}
		culoare.vector_culori = new float[culoare.nr_culori];
		for (int i = 0; i < culoare.nr_culori; i++)
		{
			in >> culoare.vector_culori[i];
		}
		return in;
	}
	float& operator[](int index)
	{
		if (index >= 0 && index < this->nr_culori && this->vector_culori != NULL) {
			return this->vector_culori[index];
		}
	}
	Culoare& operator++()
	{
		this->opacitate++;
		return *this;
	}
	Culoare operator++(int)
	{
	   Culoare copie = *this;
		this->opacitate++;
		return copie;
	}
	Culoare& operator--()
	{
		this->opacitate--;
		return *this;
	}
	Culoare operator--(int)
	{
		Culoare copie = *this;
		this->opacitate--;
		return copie;
	}
	Culoare& operator+=(int a)
	{
		this->opacitate+= a;

		return *this;
	}
	friend ostream& operator<<(ostream&out, Culoare culoare)
	{
		out << "Nume: " << culoare.nume << endl;
		out << "Opacitate: " << culoare.opacitate << endl;
		out << "Nr. culori: " << culoare.nr_culori << endl;
		out << "Vector culori: " << endl;
		for (int i = 0; i < culoare.nr_culori; i++)
		{
			out << "Culoare" << i + 1 << " : " << culoare.vector_culori[i]*100 <<"%"<< endl;
		}
		return out;
	}

	bool operator>(Culoare culoare)
	{
		if (this->opacitate > culoare.opacitate)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator<(Culoare culoare)
	{
		if (this->opacitate < culoare.opacitate)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator==(Culoare culoare)
	{
		if (this->opacitate == culoare.opacitate)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>=(Culoare culoare)
	{
		if (this->nr_culori >= culoare.nr_culori)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator<=(Culoare culoare)
	{
		if (this->opacitate <= culoare.opacitate)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!()
	{
		if (this->vector_culori == NULL) {
			return false;
		}
		else {
			return true;
		}
	}
	float operator()()
	{
		float culori = 0;

		if (this->vector_culori != NULL && this->nr_culori > 0) {
			for (int i = 0; i < this->nr_culori; i++) {
				culori += this->vector_culori[i];
			}
		}
		return culori / this->nr_culori;
	}
	operator string()
	{
		return this->hexa;

	}
	Culoare operator+(int crestere_opacitate)
	{
		Culoare copie = *this;
		if (crestere_opacitate> 0) {
			copie.opacitate -= crestere_opacitate;
		}

		return copie;
	}
	friend Culoare operator-(int reducere_opacitate, Culoare& culoare)
	{
		Culoare copie = culoare;
		if (reducere_opacitate > 0) {
			copie.opacitate = reducere_opacitate - copie.opacitate;
		}

		return copie;
	}
};*/


//Cerinta 3
	Culoare() :hexa("")
	{
		this->nume = new char[strlen("Necunoscut") + 1];
		strcpy(this->nume, "Necunoscut");
		this->opacitate = 0;
		this->nr_culori = 0;
		this->vector_culori = NULL;
	}
	Culoare(const string v_hexa, char* v_nume, float v_opacitate, int v_nr_culori, float* v_vector_culori) :hexa(v_hexa)
	{
		if (v_nume != NULL)
		{
			this->nume = new char[strlen(v_nume) + 1];
			strcpy(this->nume, v_nume);
		}
		this->opacitate = v_opacitate;
		this->nr_culori = v_nr_culori;
		if (v_vector_culori != NULL) {
			this->vector_culori = new float[this->nr_culori];
			for (int i = 0; i < this->nr_culori; i++) {
				this->vector_culori[i] = v_vector_culori[i];

			}
		}
	}
	virtual int calcNrCulori() = 0;
	virtual void afisare() {
		cout << "Nume: " << this->nume << endl;
		cout << "Cod hexa: " << this->hexa << endl;
		cout << "Opacitate: " << this->opacitate << endl;
		cout << "Nr.culori: " << this->nr_culori << endl;
		cout << "Vector: " << endl;
		for (int i = 0; i < this->nr_culori; i++) {
			cout << this->vector_culori[i] * 100 << "%" << endl;
		}
	}
};
class InterfataCuloare
{
public:
	virtual float OpacitateI() = 0;
	virtual void AdaugaOpacitate(float v_opacitate) = 0;
};
class Portocaliu :public Culoare, public InterfataCuloare
{
private:
	string luminozitate;
public:
	Portocaliu(string v_luminoziate, const string v_hexa, char* v_nume, float v_opacitate, int v_nr_culori, float* v_vector_culori) :Culoare(v_hexa, v_nume,
		v_opacitate, v_nr_culori, v_vector_culori)
	{
		if (v_luminoziate.length() > 0)
		{
			this->luminozitate = v_luminoziate;
		}

	}
	int calcNrCulori()
	{
		cout << "Culori componente portocaliu: ";
		return 2;
	}
	float OpacitateI()
	{
		return this->opacitate;
	}
	void AdaugaOpacitate(float v_opacitate)
	{
		if (v_opacitate > 0)
			this->opacitate += v_opacitate;
	}
	void afisare()
	{
		cout << "Luminoziate: " << this->luminozitate << endl;
		cout << "Nume: " << this->nume << endl;
		cout << "Cod hexa: " << this->hexa << endl;
		cout << "Opacitate: " << this->opacitate << endl;
		cout << "Nr.culori: " << this->nr_culori << endl;
		cout << "Vector: " << endl;
		for (int i = 0; i < this->nr_culori; i++) {
			cout << this->vector_culori[i] * 100 << "%" << endl;
		}
	}
};
class Mov : public Culoare, public InterfataCuloare
{
	string saturatie;
public:
	Mov(string v_saturatie, const string v_hexa, char* v_nume, float v_opacitate, int v_nr_culori, float* v_vector_culori) :Culoare(v_hexa, v_nume,
		v_opacitate, v_nr_culori, v_vector_culori)
	{
		this->saturatie = v_saturatie;
	}
	int calcNrCulori()
	{
		cout << "Culori componente mov: ";
		return 2;
	}
	float OpacitateI()
	{
		return this->opacitate;
	}
	void AdaugaOpacitate(float v_opacitate)
	{
		if (v_opacitate > 0)
			this->opacitate += v_opacitate;

	}
	void afisare()
	{
		cout << "Saturatie: " << this->saturatie << endl;
		cout << "Nume: " << this->nume << endl;
		cout << "Cod hexa: " << this->hexa << endl;
		cout << "Opacitate: " << this->opacitate << endl;
		cout << "Nr.culori: " << this->nr_culori << endl;
		cout << "Vector: " << endl;
		for (int i = 0; i < this->nr_culori; i++) {
			cout << this->vector_culori[i] * 100 << "%" << endl;
		}
	}
};
class CuloriObtinute
{
private:
	int nr_total_culori;
	Culoare **culori;
public:
	CuloriObtinute(int v_nr_total_culori, Culoare** v_culori)
	{
		this->nr_total_culori = v_nr_total_culori;
		if (v_culori != NULL && this->nr_total_culori > 0) {
			this->culori = new Culoare*[this->nr_total_culori];
			for (int i = 0; i < this->nr_total_culori; i++) {
				this->culori[i] = v_culori[i];
			}
		}
	}
	CuloriObtinute(const CuloriObtinute& copie) {
		this->nr_total_culori = copie.nr_total_culori;
		if (copie.culori != NULL && this->nr_total_culori > 0) {
			this->culori = new Culoare*[this->nr_total_culori];
			for (int i = 0; i < this->nr_total_culori; i++) {
				this->culori[i] = copie.culori[i];
			}
		}
	}

	~CuloriObtinute()
	{

		if (this->culori != NULL && this->nr_total_culori > 0)
		{
			delete[] this->culori;
		}
	}
	friend ostream& operator<<(ostream& out, CuloriObtinute co) {
		out << "Afisare culori" << endl;
		if (co.culori != NULL && co.nr_total_culori > 0) {
			for (int i = 0; i < co.nr_total_culori; i++) {
				co.culori[i]->afisare();
			}
		}

		return out;
	}
};

int main()
{
	/*Culoare c1;
	c1.Afisare();


	char* nume;
	nume = new char[strlen("Portocaliu") + 1];
	strcpy(nume, "Portocaliu");
	float opacitate = 30;
	int nr_culori = 2;
	float* vector_culori;
	vector_culori = new float[2];
	vector_culori[0] =0.7;//rosu
	vector_culori[1] = 0.3;//galben
	Culoare* c2=new Culoare("FF4500",nume, opacitate, nr_culori, vector_culori);
	c2->Afisare();

	Culoare *c3 = c2;
	c3->Afisare();


	cout<<"Nume: "<<c2->getNume()<<endl;


	char* v_nume;
	v_nume = new char[strlen("Verde") + 1];
	strcpy(v_nume, "Verde");
	c2->setNume(v_nume);
	c2->Afisare();


	cout <<"Opacitate: "<< c2->getOpacitate()<<endl;


	c2->setOpacitate(0.75);
	c2->Afisare();


	cout << "Nr. culori:" << c2->getNrCulori()<<endl;


	c2->setNrCulori(3);
	c2->Afisare();

	float* v_vector_culori;
	v_vector_culori = new float[3];
	v_vector_culori[0] = 0.3;
	v_vector_culori[1] = 0.2;
	v_vector_culori[2] = 0.5;

	c2->setVectorCulori(v_vector_culori,3);
	c2->Afisare();
	cout << "Vector: " << endl;
	for(int i=0;i<c2->getNrCulori();i++)
	cout << c2->getVectorCulori()[i]<<endl;

	Culoare* dinamic = new Culoare[3];
	float vect_culori[2] = { 0.4,0.6 };
	for (int i = 0; i < 3; i++)
	{
		dinamic[i].setVectorCulori(vect_culori,2);
		nume = new char[strlen("Albastru") + 1];
		strcpy(nume, "Albastru");
		dinamic[i].setNume(nume);
		dinamic[i].setOpacitate(10);
		}
	dinamic->Afisare();
	float produs = 1;
	for (int i = 0; i < 2; i++)
	{
		produs *=vect_culori[i];
	}
	cout << "Media geometrica este: " << sqrt(produs);

	Culoare *c5;
	c5 = c2;
	c5->Afisare();

	Culoare c6;
	cin >> c6;
	c6.Afisare();
	cout << " A doua culoare este: " << c6[1];

	Culoare c7;
	c7 = c6++;
	cout << "C7::";

	c7.Afisare();
	cout << "C6::";

	c6.Afisare();
	c7 = ++c6;

	cout << "C7::";
	c7.Afisare();

	cout << "\nC7:";
	c7--;
	c7.Afisare();

	cout << "\nC7: ";
	--c7;
	c7.Afisare();

	c6 += 2;
	c6.Afisare();

	cout << " c6>c7 " << (c6 > c7) << endl;
	cout << " c3<c5 " << (c3 < c5) << endl;
	cout << "c7==c6 " << (c7 == c6) << endl;
	cout << "c7<=c6 " << (c7 <= c6) << endl;
	cout << "c7>=c6 " << (c7 >= c6) << endl;
	cout << "Culoare primala! " << !c2;
	cout << "In medie pt a obtine o culoare se folosesc " << c6()<<"culori"<<endl;
	Culoare c8;
	c8 = c6 + 3;
	cout<<"C8::" << c8<<endl;
	c8 = 10 - c6;
	cout << "C8:: " << c8 << endl;*/
	char* nume;
	nume = new char[strlen("Portocaliu") + 1];
	strcpy(nume, "Portocaliu");
	float *vect;
	vect = new float[2];
	vect[0] = 0.3;
	vect[1] = 0.7;
	Portocaliu pp("50%", "FF8C00", nume, 0.56, 2, vect);
	pp.afisare();
	char* m_nume;
	m_nume = new char[strlen("Mov") + 1];
	strcpy(m_nume, "Mov");
	float* m_vect;
	m_vect = new float[3];
	m_vect[0] = 0.7;
	m_vect[1] = 0.2;
	m_vect[2] = 0.1;
	Mov pm("20%", "A020F0", m_nume, 0.35, 3, m_vect);
	pm.afisare();

	InterfataCuloare * culori[2] = { &pp, &pm };

	for (int i = 0; i < 2; i++)
	{
		culori[i]->AdaugaOpacitate(3);
		cout << "Modificare opacitate: " << culori[i]->OpacitateI() << endl;
	}
	Culoare* vector[2] = { &pp,&pm };
	CuloriObtinute cob(2, vector);
	cout << cob << endl;

}

