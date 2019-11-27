#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


class probleme
{

protected:

public:
    virtual void set_frane(int,int,int,int ) = 0;
    virtual void set_motor(int,int,int) = 0;
    virtual void set_directie(int,int,int) = 0;
    virtual void set_noxe(int,int) = 0;
    virtual void set_caroserie(int,int, int,int,int, int, int ) = 0;
    virtual void get()=0;
};
class frane:public probleme
{
protected:
    bool placute,discuri,lant_tocit,lant_lipsa;
public:
    frane()
    {
        placute=0;
        discuri=0;
        lant_lipsa=0;
        lant_tocit=0;
    }
    void set_frane(int a,int b,int c,int d)
    {
        placute=a;
        discuri=b;
        lant_lipsa=d;
        lant_tocit=c;
    }
    void get()
    {
        cout<<placute<<" "<<discuri<<" "<<lant_tocit<< " "<<lant_lipsa<< " ";
    }
    void set_motor(int a,int b,int c) {;};
    void set_directie(int a,int b,int c) {;};
    void set_noxe(int a,int b) {;};
    void set_caroserie(int a,int b, int c,int d,int e, int f, int g) {;};

};



class motor:public probleme
{
protected:
    bool nivel_scazut_ulei,carburator_murdar,motor_topit;
public:
    motor()
    {
        nivel_scazut_ulei=0;
        carburator_murdar=0;
        motor_topit=0;
    }
    void set_motor(int a,int b,int c)
    {
        nivel_scazut_ulei=a;
        carburator_murdar=b;
        motor_topit=c;
    }
    void get()
    {
        cout<<nivel_scazut_ulei<<" "<<carburator_murdar<<" "<<motor_topit<< " ";
    }

    void set_frane(int a,int b,int c,int d) {;};
    void set_directie(int a,int b,int c) {;};
    void set_noxe(int a,int b) {;};
    void set_caroserie(int a,int b, int c,int d,int e, int f, int g) {;};
};


class directie:public probleme
{
protected:
    bool ghidon_stramb,roata_stramba,defectiune_capitala;
public:
    directie()
    {
        ghidon_stramb=0,roata_stramba=0,defectiune_capitala=0;
    }
    void set_directie(int a,int b,int c)
    {
        ghidon_stramb=a,roata_stramba=b,defectiune_capitala=c;
    }


    void set_frane(int a,int b,int c,int d ) {;};
    void set_motor(int a,int b,int c) {;};
    void set_noxe(int a,int b) {;};
    void set_caroserie(int a,int b, int c,int d,int e, int f, int g) {;};
    void get()
    {
        cout<<ghidon_stramb<<" "<<roata_stramba<<" "<<defectiune_capitala<< " ";
    }
};

class noxe:public probleme
{
protected:
    bool arde_ulei,an_2000;
public:
    noxe()
    {
        arde_ulei=0,an_2000=0;
    }
    void set_noxe(int a,int b)
    {
        arde_ulei=a,an_2000=b;
    }


    void set_frane(int a,int b,int c,int d ) {;};
    void set_motor(int a,int b,int c) {;};
    void set_directie(int a,int b,int c) {;};
    void set_caroserie(int a,int b, int c,int d,int e, int f, int g) {;};
    void get()
    {
        cout<<arde_ulei<<" "<<an_2000<<" ";
    }

};

class caroserie:public probleme
{
protected:
    bool stramba_aripi_st_fata,stramba_aripi_dr_fata,stramba_aripi_st_spate,stramba_aripi_dr_spate,bara,capota,foarte_stramba;
public:
    caroserie()
    {
        stramba_aripi_st_fata=0,stramba_aripi_dr_fata=0;
        stramba_aripi_st_spate=0;
        stramba_aripi_dr_spate=0;
        bara=0;
        capota=0,foarte_stramba=0;
    }
    void set_caroserie(int a,int b, int c,int d,int e, int f, int g)
    {
        stramba_aripi_st_fata=a,stramba_aripi_dr_fata=b;
        stramba_aripi_st_spate=c;
        stramba_aripi_dr_spate=d;
        bara=e;
        capota=f,foarte_stramba=g;
    }


    void set_frane(int a,int b,int c,int d ) {;};
    void set_motor(int a,int b,int c) {;};
    void set_directie(int a,int b,int c) {;};
    void set_noxe(int a,int b) {;};

    void get()
    {
        cout<<stramba_aripi_st_fata<<" "<<stramba_aripi_dr_fata<<" "<<stramba_aripi_st_spate<< " "<<stramba_aripi_dr_spate<<" "<<bara<<" "<<capota<<" "<<foarte_stramba<<" ";
    }
};



class vehicul
{
protected:
    vector <probleme*> vp;
    frane fr;
    motor mtr;
    directie dir;
    noxe nox;
    caroserie caros;
    int nr_probleme;
public:
    void citire()
    {
        cout<<"Citeste nr_probleme: ";
        cin>>nr_probleme;
        cout<<endl;
        int i;
        int op;
        for (i=0; i<nr_probleme; i++)
        {
            cout<<"Citeste optiune problema: ";
            cin>>op;
            cout<<endl;
            switch(op)
            {
            case 1:
            {
                int a,b,c,d;
                cin>>a>>b>>c>>d;
                probleme *p;
                fr.set_frane(a,b,c,d);
                p=&fr;
                vp.push_back(p);
                break;
            }

            case 2:
            {
                int a,b,c;
                cin>>a>>b>>c;
                probleme *p;
                mtr.set_motor(a,b,c);
                p=&mtr;
                vp.push_back(p);
                break;
            }
            case 3:
            {
                int a,b,c;
                cin>>a>>b>>c;
                probleme *p;
                dir.set_directie(a,b,c);
                p=&dir;
                vp.push_back(p);
                break;
            }
            case 4:
            {
                int a,b;
                cin>>a>>b;
                probleme *p;
                nox.set_noxe(a,b);
                p=&nox;
                vp.push_back(p);
                break;
            }
            case 5:
            {

                int a,b,c,d,e,f,g;
                cin>>a>>b>>c>>d>>e>>f>>g;
                probleme *p;
                caros.set_caroserie(a,b,c,d,e,f,g);
                p=&caros;
                vp.push_back(p);
                break;
            }
            }
        }





    }
    void afisare()
    {

        int i;
        for (i=0; i<nr_probleme; i++)
        {
            vp[i]->get();
        }
    }

};

class automobil:public vehicul
{
protected:
    string numar_inmatriculare;
    string culoare;
    string marca;
public:
    automobil()
    {
        numar_inmatriculare = "B99BOG";
        culoare = "NONE";
        marca="Logan";
    }


    void citire()
    {
        cout<<"Citeste nr_probleme: ";
        cin>>nr_probleme;
        cout<<endl;
        try
        {
            if (nr_probleme>5)
                throw "Ai introdus prea multe probleme";

        }
        catch(...)
        {
            cout<<"Exception caught";

        }
        int i;
        int op;
        for (i=0; i<nr_probleme; i++)
        {
            cout<<"Citeste optiune problema: ";
            cin>>op;
            cout<<endl;
            switch(op)
            {
            case 1:
            {
                int a,b,c=0,d=0;
                cin>>a>>b>>c>>d;
                c=0;
                d=0;
                probleme *p;
                fr.set_frane(a,b,c,d);
                p=&fr;
                vp.push_back(p);
                break;
            }

            case 2:
            {
                int a,b,c;
                cin>>a>>b>>c;
                probleme *p;
                mtr.set_motor(a,b,c);
                p=&mtr;
                vp.push_back(p);
                break;
            }
            case 3:
            {
                int a=0,b,c;
                cin>>a>>b>>c;
                a=0;
                probleme *p;
                dir.set_directie(a,b,c);
                p=&dir;
                vp.push_back(p);
                break;
            }
            case 4:
            {
                int a,b;
                cin>>a>>b;
                probleme *p;
                nox.set_noxe(a,b);
                p=&nox;
                vp.push_back(p);
                break;
            }
            case 5:
            {

                int a,b,c,d,e,f,g;
                cin>>a>>b>>c>>d>>e>>f>>g;
                probleme *p;
                caros.set_caroserie(a,b,c,d,e,f,g);
                p=&caros;
                vp.push_back(p);
                break;
            }
            }
        }
    }

    ~automobil()
    {

    }

};


class motocicleta:public vehicul
{

protected:
    string design;
    string marca;
    string culoare;

public:
    motocicleta()
    {
        design="sport";
        marca="YAMAHA";
        culoare="negru";
    }
    void citire()
    {
        cout<<"Citeste nr_probleme: ";
        cin>>nr_probleme;
        try
        {
            if (nr_probleme>4)
                throw "Ai introdus prea multe probleme";

        }
        catch(...)
        {
            cout<<"Exception caught";

        }
        cout<<endl;
        int i;
        int op;
        for (i=0; i<nr_probleme; i++)
        {
            cout<<"Citeste optiune problema: ";
            cin>>op;
            cout<<endl;
            switch(op)
            {
            case 1:
            {
                int a,b,c=0,d=0;
                cin>>a>>b>>c>>d;
                c=0;
                d=0;
                probleme *p;
                fr.set_frane(a,b,c,d);
                p=&fr;
                vp.push_back(p);
                break;
            }

            case 2:
            {
                int a,b=0,c;
                cin>>a>>b>>c;
                b=0;
                probleme *p;
                mtr.set_motor(a,b,c);
                p=&mtr;
                vp.push_back(p);
                break;
            }
            case 3:
            {
                int a=0,b,c;
                cin>>a>>b>>c;
                a=0;
                probleme *p;
                dir.set_directie(a,b,c);
                p=&dir;
                vp.push_back(p);
                break;
            }
            case 4:
            {
                int a,b;
                cin>>a>>b;
                probleme *p;
                nox.set_noxe(a,b);
                p=&nox;
                vp.push_back(p);
                break;
            }

            }
        }

    }

    ~motocicleta()
    {


    }
};


class bicicleta:public vehicul
{

protected:
    string tip;
    double inaltime;

public:

    bicicleta()
    {
        tip="montana";
        inaltime=0.58;
    }

    void citire()
    {
        cout<<"Citeste nr_probleme: ";
        cin>>nr_probleme;
        try
        {
            if (nr_probleme>2)
                throw "Ai introdus prea multe probleme";

        }
        catch(...)
        {
            cout<<"Exception caught";

        }
        cout<<endl;
        int i;
        int op;
        for (i=0; i<nr_probleme; i++)
        {
            cout<<"Citeste optiune problema: ";
            cin>>op;
            cout<<endl;
            switch(op)
            {
            case 1:
            {
                int a,b,c,d;
                cin>>a>>b>>c>>d;
                a=0;
                b=0;
                probleme *p;
                fr.set_frane(a,b,c,d);
                p=&fr;
                vp.push_back(p);
                break;
            }

            case 2:
            {
                int a,b,c;
                cin>>a>>b>>c;
                a=0;
                b=0;
                c=0;
                probleme *p;
                mtr.set_motor(a,b,c);
                p=&mtr;
                vp.push_back(p);
                break;
            }
            case 3:
            {
                int a,b,c;
                cin>>a>>b>>c;
                probleme *p;
                dir.set_directie(a,b,c);
                p=&dir;
                vp.push_back(p);
                break;
            }
            case 4:
            {
                int a,b;
                cin>>a>>b;
                a=0;
                b=0;
                probleme *p;
                nox.set_noxe(a,b);
                p=&nox;
                vp.push_back(p);
                break;
            }
            }
        }

    }

    ~bicicleta()
    {
        inaltime=0;
    }
};

class material
{

protected:
    string nume;
    int valoare;
public:
    material()
    {
        valoare=0;
    }
    int get_val(){return valoare;}
    friend ostream &operator <<(ostream &, material &);
    friend istream &operator >>(istream &, material &);

};

istream &operator >>(istream &in, material &ob1)
{
    cout<<endl;
    cout<<"Citeste nume material: ";
    in>>ob1.nume;
    cout<<"Citeste valoarea materialului: ";
    in>>ob1.valoare;
    cout<<endl;

//    in>>ob1.vehicul;

}

ostream &operator <<(ostream &out, material &ob1)
{
    out<<"Afiseaza nume material: ";
    out<<ob1.nume;
    out<<endl;
    out<<"Afiseaza valoare material: ";
    out<<ob1.valoare;
//   out<<ob1.vehicul;
}



class solutie
{
protected:
    int nr;
    material *mat;
    int cost_sol;
    string problema_sol;
    static int bani;
public:
    solutie()
    {
        cost_sol=0;
        nr=0;
    }


    solutie(const solutie &ob)
    {

        int i;
        for (i=0;i<nr;i++)
            this->mat[i]=ob.mat[i];
    }


    string get_problema_sol(){return problema_sol;}
    int get_cost_sol(){return cost_sol;}
   /* solutie(int i=1)
    {
        nr=i;
        mat=new material[nr];
    }*/
    void set_nr(int i){nr=i; mat=new material[nr];}
    int get_nr(){return nr;}
    void creare_sol()
    {
        cout<<"Citeste pt ce problema este solutia: ";
        cin>>problema_sol;
        int i;
        for (i=0; i<nr; i++)
        {
            cout<<"Citeste materialul"<<" ";
            cin>>mat[i];
            cost_sol+=mat[i].get_val();
        }
    }
    void afisare(){cout<<cost_sol<<endl;}
    ~solutie()
    {
        delete []mat;
        nr=0;
    }

};

int solutie::bani;


class service
{

protected:
    vector <vehicul*> v;
    automobil autom;
    motocicleta motocic;
    bicicleta bicla;
    int nr_vehicule;

public:
    /*  void citire(){

      cin>>nr_vehicule;
      int op;
      cin>>op;
      switch (op)
      {
      case 1:
          {
              automobil ob;
              break;
          }
      }

      }*/


};


int main()
{
    //vector<vehicul*> v
    int val;
    int ok=1;
    while (ok)
    {
        cout<<"Citeste val: ";
        cin>>val;
        switch(val)
        {

        case 1:
        {
            automobil oba;
            oba.citire();
            oba.afisare();
            break;
        }
        case 2:
        {
            motocicleta obm;
            obm.citire();
            obm.afisare();
            break;
        }
        case 3:
        {
            bicicleta obb;
            obb.citire();
            obb.afisare();
            break;

        }
        case 4:
        {
            ok=0;
            break;
        }
        }

    }
    return 0;
}
